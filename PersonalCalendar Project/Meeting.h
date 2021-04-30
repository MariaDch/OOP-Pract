#pragma once
#include "Date.h"
#include "String.h"

class Meeting
{
private:
	String date;
	String name;
	String note;
	String startTime;
	String endTime;
public:
	Meeting();
	Meeting(const Meeting& other_meeting);
	
	void setName(String other_name);
	void setNote(String other_note);
	void setStartTime(String other_starttime);
	void setEndTime(String other_endTime);

	String getDate()const;
	String getName()const;
	String getNote()const;
	String getStartTime()const;
	String getEndTime()const;

	Meeting& operator=(Meeting& other_meeting);
	bool operator==(Meeting& other_meeting);

	int dateDay();
	int dateMonth();
	int dateYear();
	int TimeHours(String time);
	int TimeSeconds(String time);
	int convertTimeToInt(String time);
	int convertDateToInt();
	bool validateDate();
	bool validateTime(String time);

	void print()const;
};

