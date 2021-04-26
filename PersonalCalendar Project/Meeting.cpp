#include "Meeting.h"
#include<iostream>

Meeting::Meeting()
{
	name = nullptr;
	note = nullptr;
	startTime = nullptr;
	endTime = nullptr;
}

Meeting::Meeting(const Meeting& other_meeting)
{
	name = other_meeting.name;
	note = other_meeting.note;
	startTime = other_meeting.startTime;
	endTime = other_meeting.endTime;
}

void Meeting::setName(String other_name)
{
	name = other_name;
}

void Meeting::setNote(String other_note)
{
	note = other_note;
}

void Meeting::setStartTime(String other_startTime)
{
	startTime = other_startTime;
}

void Meeting::setEndTime(String other_endTime)
{
	endTime = other_endTime;
}

String Meeting::getName()const
{
	return name;
}

String Meeting::getNote()const
{
	return note;
}

String Meeting::getStartTime()const
{
	return startTime;
}

String Meeting::getEndTime()const
{
	return endTime;
}

/*void Meeting::print() const
{
	std::cout << name;
	std::cout << std::endl;
	std::cout << note;
	std::cout << std::endl;
	std::cout << startTime;
	std::cout << std::endl;
	std::cout << endTime;
}*/