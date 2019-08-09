#pragma once
#include "Task.h"
#include "StoredTask.h"
#include <stdio.h>
#include "ArchivedTask.h"
#include <string>
#include <ctime>

[event_source(native)]
class ActiveTask : public Task
{
private:
	StoredTask * parent;
	string note;
	bool done;
	//DisplayedTask * 
public:
	ActiveTask();
	~ActiveTask();

	void Complete(bool complete = true) {
		done = complete;

		string dateCreated = to_string(created.tm_mon) + "/" + to_string(created.tm_mday) + "/" + to_string(created.tm_year);
		time_t now = time(0);
		tm *today = gmtime(&now);
		string dateClosed = to_string(today->tm_mon) + "/" + to_string(today->tm_mday) + "/" + to_string(today->tm_year);
		
		ArchivedTask arch = ArchivedTask(desc, details, dateCreated, dateClosed, done, note);

		__raise Archive(arch);
	}

	__event void Archive(ArchivedTask at);

	//Archive connection?
};

