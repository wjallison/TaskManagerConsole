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

	bool ActivateOnDate(tm dateTime) {
		if (rptCond == nullptr) {
			return false;
		}
		if (rptCond->Evaluate(dateTime)) {
			return true;
		}

		return false;
	}

	ActiveTask* Activate() {
		if (endCond->CountRepeat() == 0) {
			rptCond = nullptr;
			ended = true;
		}

		ActiveTask active = ActiveTask(desc, details);
		return &active;
	}

	/*ActiveTask* ActivateToday(tm dateTime) {
		if (rptCond == nullptr) { return nullptr; }
		if (rptCond->Evaluate(dateTime)) {
			if (endCond->CountRepeat() == 0) {
				rptCond = nullptr;
				ended = true;
			}



		}
		else {
			return nullptr;
		}
	}*/

	/*StoredTask();
	~StoredTask();*/
};

