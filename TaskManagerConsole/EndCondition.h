#pragma once
class EndCondition
{
private:
	bool numRepeats;
	int afterNRepeats;
	int remainingRepeats;

public:
	EndCondition();
	~EndCondition();
	
	int CountRepeat() {
		return --remainingRepeats;
	}
};

