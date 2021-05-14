#include <iostream>
#include "Calendar.h"

int main()
{
	Meeting m1;
	m1.setDate("22.02.03");
	m1.setStartTime("08:00");
	m1.setEndTime("11:00");
	m1.setName("Maria");
	m1.setNote("Work");

	Meeting m2;
	m2.setDate("22.02.01");
	m2.setStartTime("07:00");
	m2.setEndTime("12:00");
	m2.setName("Hristo");
	m2.setNote("Talk");

	Meeting m3;
	m3.setDate("22.11.02");
	m3.setStartTime("09:00");
	m3.setEndTime("10:00");
	m3.setName("Gosho");
	m3.setNote("Meet");

	//std::cout <<m3.getDate().convertStringToInt();

	Vector <Meeting> meetingscheta;
	meetingscheta.pushBack(m3);
	meetingscheta.pushBack(m2);
	meetingscheta.pushBack(m1);
	//std::cout <<m1.overlapedMeetings(m2);
	Calendar cal;
	cal.setMeetings(meetingscheta);
	meetingscheta.sort();

	//meetingscheta.print();

	//cal.findSlot("22.01.10", 2);							//promeni da smqta do kolko chasa trqbva da e sreshtata!!!
	//cal.holiday("22.11.10");							   // ne raboti !!! ninam zashto
	//cal.busyDays("22.02.01", "22.02.10");				  // proveri za greshka !!!!!!
	
	
	//cal.find("Talk");
	//cal.agenda("10.02.22");
	//cal.unbook(m2.getDate(), m2.getStartTime(), m2.getEndTime());
	//cal.book(m3);
}