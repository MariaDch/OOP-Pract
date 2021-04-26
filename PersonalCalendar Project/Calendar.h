#pragma once
#include "Meeting.h"
#include "Date.h"

class Calendar
{
private:
	Meeting meetings;
	Date date;
	Date startTime;
	Date endTime;
public:
	void setMeetings(Meeting& other_meeting);
	Meeting getMeetings()const;

	void book(Meeting meetings);
	void unbook(Meeting meetings);
	void agenda();
	void change();
};

