#pragma once
#include "String.h"
#include "Vector.h"

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
	Meeting(String other_date, String other_startTime, String other_endTime, String other_name, String other_note);
	
	void setName(String other_name);
	void setNote(String other_note);
	void setStartTime(String other_starttime);
	void setEndTime(String other_endTime);
	void setDate(String other_date);

	String getDate()const;
	String getName()const;
	String getNote()const;
	String getStartTime()const;
	String getEndTime()const;

	
	bool operator==(Meeting& other_meeting);
	friend std::ostream& operator<<(std::ostream& out, Meeting meet)
	{
		out << meet.date << std::endl << meet.startTime << std::endl << meet.endTime << std::endl << meet.name << std::endl << meet.note << std::endl;
		return out;
	}

	int busyHour();
	void print()const;
	bool overlapedMeetings(Meeting& other);

};

