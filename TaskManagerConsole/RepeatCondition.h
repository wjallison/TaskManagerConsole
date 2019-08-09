#pragma once
#include <ctime>
class RepeatCondition
{
private:
	bool weekly;
	bool wk[7];
	
	bool monthly;
	bool month[31];
	
	bool yearDates;
	bool year[365];

	bool everyXDays;
	int eXD;
	int eXDStartDay;

	bool everyXWorkDays;
	int eXWD;
	int eXWDStartDay;

public:
	RepeatCondition();
	~RepeatCondition();

	bool Evaluate(tm dateTime) {
		if (weekly) {
			if (wk[dateTime.tm_wday]) {
				return true;
			}
		}
		if (monthly) {
			if (month[dateTime.tm_mday]) {
				return true;
			}
		}
		if (yearDates) {
			if (year[dateTime.tm_yday]) {
				return true;
			}
		}
		if (everyXDays) {
			if ((dateTime.tm_yday - eXDStartDay) % eXD == 0) {
				return true;
			}
		}
		if (everyXWorkDays) {
			if ((dateTime.tm_yday - eXWDStartDay) % eXWD == 0) {
				return true;
			}
		}
		return false;
	}
};

