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

	Meeting m3;
	m3.setDate("02.11.22");
	m3.setStartTime("09:00");
	m3.setEndTime("10:00");
	m3.setName("Gosho");
	m3.setNote("Meet");

	//std::cout <<m3.getDate().convertStringToInt();

	Vector <Meeting> meetingscheta;
	meetingscheta.pushBack(m1);
	meetingscheta.pushBack(m2);
	//meetingscheta.print();

	Calendar cal;
	cal.setMeetings(meetingscheta);

	//cal.findSlot("10.02.22", 2);							//---ne raboti!!!
	//cal.holiday("02.11.22");							   // ne raboti !!!
	//cal.busyDays("01.02.22", "10.02.22");				  // ne raboti !!!

									//VECTOR SORT NE RABOTI!
								   // PROVERI DALI FUNCIQTA overlapedMeetings RABOTI PRAVILNO
	
	
	//cal.find("Talk");
	//cal.agenda("10.02.22");
	//cal.unbook(m2.getDate(), m2.getStartTime(), m2.getEndTime());
	//cal.book(m3);
}