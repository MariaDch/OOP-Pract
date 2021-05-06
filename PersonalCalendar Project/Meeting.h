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
	bool compareMeetings(Meeting meet);

	void print()const;

	/*friend std::ostream& operator<<(std::ostream& out,const Meeting& meet)
	{
		out << meet.getDate() << std::endl;
		out << meet.startTime << std::endl;
		out << meet.endTime << std::endl;
		out << meet.name << std::endl;
		return out;
	}
	*/
};

