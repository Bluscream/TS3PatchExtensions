#include "QtPacketList.h"
#include "packetList.h"
#include <helpers.h>

QtPacketList::QtPacketList(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());

	ui.tabWidget->setCurrentIndex(0); //set to first page
	ui.sendButton->setEnabled(false); //disable cuz we don't want to send nothing (wouldn't be possible but looks better ya know)
	ui.parseFieldsButton->setEnabled(false);
	
	updateLists();
}

QtPacketList::~QtPacketList()
{
}

void QtPacketList::copyTextToClipboard(QTreeWidgetItem* item)
{
	QClipboard* clipboard = QApplication::clipboard();
	clipboard->setText(item->text(0));
}

void QtPacketList::sendCommand()
{
	if (ui.sendCommandLine->text().isEmpty())
		return;

	string command = ui.sendCommandLine->text().toStdString();
	int schid = ui.sendSchidSpin->value();

	if (schid > 0)
		hook_functions.sendCommand(schid, command);
}

void QtPacketList::checkSendButton()
{
	ui.sendButton->setEnabled(!ui.sendCommandLine->text().isEmpty());
}

void QtPacketList::checkParseFieldsButton()
{
	ui.parseFieldsButton->setEnabled(!ui.parseFieldEdit->text().isEmpty());
}

void QtPacketList::parseFields()
{
	if (ui.parseFieldEdit->text().isEmpty())
		return;

	string cmd = ui.parseFieldEdit->text().toStdString();
	vector<pair<string, string>> fields = parse(cmd);
	ui.parseFieldsList->clear();
	for (int i = 0; i < fields.size(); i++)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem;
		item->setText(0, QString::fromStdString(fields[i].first));
		item->setText(1, QString::fromStdString(fields[i].second));
		ui.parseFieldsList->insertTopLevelItem(i, item);
	}
}

void QtPacketList::updateLists()
{
	QString filter = ui.searchLine->text();
	Qt::CaseSensitivity caseSensitive = ui.searchCaseBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
	ui.packetInList->clear();
	for (int i = 0, j = 0; i < config->packetsIn.size(); i++)
	{
		if (!filter.isEmpty() && !config->packetsIn[i].contains(filter, caseSensitive))
			continue;
		QTreeWidgetItem* item = new QTreeWidgetItem;
		item->setText(0, config->packetsIn[i]);
		item->setToolTip(0, config->packetsIn[i]);
		ui.packetInList->insertTopLevelItem(j, item);
		j++;
	}

	ui.packetOutList->clear();
	for (int i = 0, j = 0; i < config->packetsOut.size(); i++)
	{
		if (!filter.isEmpty() && !config->packetsOut[i].contains(filter, caseSensitive))
			continue;
		QTreeWidgetItem* item = new QTreeWidgetItem;
		item->setText(0, config->packetsOut[i]);
		item->setToolTip(0, config->packetsOut[i]);
		ui.packetOutList->insertTopLevelItem(j, item);
		j++;
	}
}
