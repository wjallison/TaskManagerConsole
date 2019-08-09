#pragma once
#include "Task.h"
#include "RepeatCondition.h"
#include "EndCondition.h"
#include <ctime>
class StoredTask : public Task
{
private:
	bool ended;
	RepeatCondition * rptCond;
	EndCondition * endCond;
	
public:


	ActiveTask* ActivateToday(tm dateTime) {
		if (rptCond->Evaluate(dateTime)) {
			if (endCond->CountRepeat() == 0) {
				rptCond = nullptr;
				ended = true;
			}


		}
		else {
			return nullptr;
		}
	}

	StoredTask();
	~StoredTask();
};

