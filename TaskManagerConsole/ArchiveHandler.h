#pragma once
#include "ActiveTask.h"
#include <list>
#include <ctime>

//Abstract class; concrete classes will be for individual systems, eg Windows
class ArchiveHandler
{
private:
	
public:
	ArchiveHandler();
	~ArchiveHandler();

	virtual void ArchiveTask(ActiveTask a);
	virtual list<ActiveTask> RetrieveTasks();
	virtual void OverrideArchive(list<ActiveTask> ls);
	virtual list<ActiveTask> RetrieveTasksOnDate(tm dateTime);
};



class WindowsArchiveHandler : ArchiveHandler 
{
private:

public:

};



class AndroidArchiveHandler : ArchiveHandler 
{
private:

public:

};

