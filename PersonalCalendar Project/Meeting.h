#pragma once
#include "Date.h"
#include "String.h"

class Meeting
{
private:
	String name;
	String note;
	String startTime;
	String endTime;

public:
	Meeting();
	Meeting(const Meeting& other_meeting);

	void setName(String other_name);
	void setNote(String other_note);
	void setStartTime(String other_startTime);
	void setEndTime(String other_endTime);

	String getName()const;
	String getNote()const;
	String getStartTime()const;
	String getEndTime()const;

	void print()const;
};

