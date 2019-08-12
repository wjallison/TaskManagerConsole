#pragma once
#include "ActiveTask.h"
#include <list>
#include <iterator>
#include <ctime>

using namespace std;
class ActiveTaskHandler
{
public:
	ActiveTaskHandler();
	~ActiveTaskHandler();

	list <ActiveTask> activeList;

	ActiveTaskHandler(tm dateTime, list <StoredTask> allTasks) {
		//int n = sizeof
		list <StoredTask> ::iterator it;
		for (it = allTasks.begin(); it != allTasks.end(); ++it) {
			if (it->ActivateOnDate(dateTime)) {
				activeList.push_back(*(it->Activate()));
			}
		}
	}

};

