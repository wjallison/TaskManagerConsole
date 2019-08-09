#pragma once
class ArchivedTask
{
private:
	string desc;
	string detail;
	string dateCreated;
	string dateClosed;
	bool completed;
	string note;
public:
	ArchivedTask(string desc_, string detail_, string dateCreated_, string dateClosed_, bool completed_, string notes) {
		desc = desc_;
		detail = detail_;
		dateCreated = dateCreated_;
		dateClosed = dateClosed_;
		completed = completed_;
		note = notes;
	}
	~ArchivedTask();
};

