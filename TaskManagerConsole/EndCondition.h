#pragma once
class EndCondition
{
private:
	bool numRepeats;
	int afterNRepeats;
	int remainingRepeats;
	bool numComplete;
	int afterNCompletes;
	int remainingCompletions;


public:
	EndCondition();
	~EndCondition();
	void CountComplete() {
		--remainingCompletions;
	}
	int CountRepeat() {
		return --remainingRepeats;
	}
	//TODO: This is messy.  Consider changing entire endcondition methodology.  
};

