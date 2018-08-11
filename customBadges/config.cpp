#include "config.h"

Config* config = new Config;

string getShitAfterDelim(string line, char delim)
{
	auto findPos = line.find(delim);
	if (findPos == string::npos)
		return line;

	return line.substr(findPos + 1);
}

vector<string> getNextLineAndSplitIntoTokens(istream& str)
{
	vector<std::string>   result;
	string                line;
	getline(str, line);

	stringstream          lineStream(line);
	string                cell;

	while (getline(lineStream, cell, ','))
	{
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

void Config::readCSVLine(vector<string> results)
{
	//uid,name,description,filename
	bool fileFound = ifstream(this->directory + "icons/" + results[3] + ".png").good();
	string fileName = fileFound ? results[3] : "placeholder";
	this->allBadges.push_back(make_tuple(results[0], results[1], results[2], fileName));
	this->badgeCount++;
}

bool Config::readCSV(string dir)
{
	string configFile = dir + csvName;

	ifstream file(configFile);

	if (!file.good())
		return false;

	string line;
	getline(file, line); //skip the first line
	while (!file.eof())
		readCSVLine(getNextLineAndSplitIntoTokens(file));

	file.close();

	return true;
}

void Config::readConfigLine(vector<string> results)
{
	for (string result : results)
	{
		if (result.size() > 1)
		{
			this->badges.push_back(result);
		}
	}
}

bool Config::readConfig(string dir)
{
	this->directory = dir;

	string configFile = this->directory + this->configName;
	readCSV(dir);

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	string line;

	getline(file, line);
	this->overwolfBadge = stoi(getShitAfterDelim(line, '='));

	this->badges.clear();
	readConfigLine(getNextLineAndSplitIntoTokens(file));

	this->badgeIDs.clear();
	for (string badge : this->badges) //add ids from badgeGUIDs
		this->badgeIDs.push_back(findBadgeID(badge));

	return true;
}

bool Config::writeConfig()
{
	if (this->directory.empty())
		return false;

	ofstream file(this->directory + this->configName, ofstream::out | ofstream::trunc);

	file << "overwolfBadge=" << int(this->overwolfBadge) << endl;

	for (string badge : this->badges)
		file << badge << ",";

	file.close();

	return true;
}

string Config::buildBadges()
{
	string badgesString = "";
	for (int i = 0; i < this->badges.size(); i++)
	{
		badgesString += this->badges[i] + ',';
	}
	if (badgesString.size() > 0)
		badgesString.pop_back(); //delete last comma

	return badgesString;
}

int Config::findBadgeID(string GUID)
{
	for (unsigned i = 0; i < badgeCount; i++)
	{
		if (get<0>(this->allBadges[i]) == GUID)
			return i;
		else
			continue;
	}
	return -1;
}
