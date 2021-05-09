#include <iostream>
#include "Calendar.h"

int main()
{
	Meeting m1;
	m1.setDate("01.02.22");
	m1.setStartTime("08:00");
	m1.setEndTime("10:00");
	m1.setName("Maria");
	m1.setNote("Work");

	Meeting m2;
	m2.setDate("10.02.22");
	m2.setStartTime("09:00");
	m2.setEndTime("10:00");
	m2.setName("Hristo");
	m2.setNote("Talk");

	Vector <Meeting> meetingscheta;
	meetingscheta.pushBack(m1);
	meetingscheta.pushBack(m2);
	meetingscheta.print();

	Calendar cal;
	cal.setMeetings(meetingscheta);
	//cal.findSlot();
}