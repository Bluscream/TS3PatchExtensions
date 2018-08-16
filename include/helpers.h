#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<string, string>> parse(string command)
{
	vector<pair<string, string>> results;
	size_t currentPosition = command.find(' ') + 1;
	do
	{
		size_t seperatorPos = command.find('=', currentPosition);
		if (seperatorPos == string::npos)
			break;

		size_t endPos = command.find(' ', seperatorPos);
		if (endPos == string::npos)
			endPos = command.size();

		pair<string, string> current = { command.substr(currentPosition, seperatorPos - currentPosition),
			command.substr(seperatorPos + 1, endPos - (seperatorPos + 1)) };
		results.push_back(current);

		currentPosition = endPos;
	} while (true);
	return results;
}

map<string, string> parseMap(string command)
{
	map<string, string> results;
	size_t currentPosition = command.find(' ') + 1;
	do
	{
		size_t seperatorPos = command.find('=', currentPosition);
		if (seperatorPos == string::npos)
			break;

		size_t endPos = command.find(' ', seperatorPos);
		if (endPos == string::npos)
			endPos = command.size();

		results[command.substr(currentPosition, seperatorPos - currentPosition)] =
			command.substr(seperatorPos + 1, endPos - (seperatorPos + 1));

		currentPosition = endPos;
	} while (true);
	return results;
}

string parseField(string command, string field)
{
	size_t findPos = command.find(field);
	if (findPos == string::npos)
		return string();

	size_t findEndPos = command.find(' ', findPos);
	if (findEndPos == string::npos)
		findEndPos = command.size();

	size_t start = findPos + field.size() + 1; //+1 cuz seperator
	return command.substr(start, findEndPos - start);
}

string setField(string command, string field, string value)
{
	size_t findPos = command.find(field);
	if (findPos == string::npos)
		return command;

	size_t findEndPos = command.find(' ', findPos);
	if (findEndPos == string::npos)
		findEndPos = command.size();

	return command.substr(0, findPos + field.size() + 1) + value + command.substr(findEndPos, command.size() - findEndPos);
}

string setFields(string command, vector<string> fields, vector<string> values)
{
	string buffer = command;
	for (int i = 0; i < fields.size(); i++)
	{
		size_t findPos = command.find(fields[i]);
		if (findPos == string::npos)
			continue;

		size_t findEndPos = command.find(' ', findPos);
		if (findEndPos == string::npos)
			findEndPos = command.size();

		size_t start = findPos + fields[i].size() + 1;
		size_t origSize = findEndPos - start;
		int sizeDiff = origSize - values[i].size();
		if (sizeDiff > 0) //delete some unneeded space
		{
			buffer.erase(start, sizeDiff);
		}
		else if (sizeDiff < 0) //insert some needed space
		{
			buffer.insert(start, -sizeDiff, ' ');
		}
		buffer.replace(start, values[i].size(), values[i]);
	}
	return buffer;
}