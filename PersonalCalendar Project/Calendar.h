#pragma once
#include "Meeting.h"
#include "Vector.h"
#include "String.h"

class Calendar
{
private:
	Vector <Meeting> meetings;
	String date;
	String startTime;
	String endTime;

	void copy(Calendar& other_calendar);
public:
	Calendar();
	Calendar(Calendar& other_calendars);

	void setMeetings(Vector<Meeting>& other_meetings);
	void setDate(String& other_date);
	void setStartTime(String& other_startTime);
	void setEndTime(String& other_ednTime);

	Vector <Meeting> getMeetings()const;
	String getDate()const;
	String getStartTime()const;
	String getEndTime()const;

	void book(Meeting meeting);
	void unbook(String _date, String start_time, String end_time);
	void agenda(String _date);
	void change(Meeting meet, String option, String newValue);
	void find(String findString);
	void holiday(String _date);
	void busyDays(String from, String to);
	void findSlot(String date, int hours);
	void findSlotWith(String fromDate, int hours, Calendar other_calendar);
	void findSlotWith(String _date, int hours, Vector<Calendar> calendars);		//za bonus uslovieto !
	void merge(Calendar other_calendar);
	void merge(Vector<Calendar> calendars);										//za bonus uslovieto !
	
};

