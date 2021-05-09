#include "Calendar.h"

void Calendar::copy(Calendar& other_calendar)
{
	meetings = other_calendar.meetings;
	date = other_calendar.date;
	startTime = other_calendar.startTime;
	endTime = other_calendar.endTime;
}

Calendar::Calendar()
{
	//meetings; ???????????????????????????????
	date = "00.00.00";
	startTime = "00:00";
	endTime = "00:00";
}

Calendar::Calendar(Calendar& other_calendar)
{
	copy(other_calendar);
}

void Calendar::setMeetings(Vector<Meeting>& other_meetings)
{
	meetings = other_meetings;
}

void Calendar::setDate(String& other_date)
{
	date = other_date;
}

void Calendar::setStartTime(String& other_startTime)
{
	startTime = other_startTime;
}

void Calendar::setEndTime(String& other_endTime)
{
	endTime = other_endTime;
}

Vector<Meeting> Calendar::getMeetings() const
{
	return meetings;
}

String Calendar::getDate() const
{
	return date;
}

String Calendar::getStartTime()const
{
	return startTime;
}

String Calendar::getEndTime()const
{
	return endTime;
}

void Calendar::book(Meeting meeting)									//TRQBVA  DA E VQrNO
{
	if (meetings.overlapedMeetings(meeting) == false)
	{
		meetings.pushBack(meeting);
	}
}

void Calendar::unbook(String _date, String start_time, String end_time) //trqbva da e vqrno
{
	meetings.removeElement(_date, start_time, end_time);	    
}

void Calendar::agenda(String _date)						    	        //trqbva da e vqrno
{
	meetings.sort();

	for (int i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getDate() == _date)
		{
			meetings[i].print();
		}
	}
}

void Calendar::change(Meeting meet, String option, String newValue)
{
	Meeting currentMeeting = meetings.findElement(meet);
	unbook(currentMeeting.getDate(), currentMeeting.getStartTime(), currentMeeting.getEndTime());

	if (option == "date")
	{
		currentMeeting.setDate(option);
		book(Meeting(currentMeeting));
	}

	if (option == "start time")
	{
		currentMeeting.setStartTime(option);
		book(Meeting(currentMeeting));
	}

	if (option == "end time")
	{
		currentMeeting.setEndTime(option);
		book(Meeting(currentMeeting));

	}

	if (option == "name")
	{
		currentMeeting.setName(option);
		book(Meeting(currentMeeting));
	}

	if (option == "note")
	{
		currentMeeting.setNote(option);
		book(Meeting(currentMeeting));
	}

							//ako stava sus switch
	/*int selection = 0;
	std::cout << "If you want to change date, press 1." << std::endl;
	std::cout << "If you want to change the start time, press 2. " << std::endl;
	std::cout << "If you want to change the end time, press 3. " << std::endl;
	std::cout << "If you want to change the name, press 4. " << std::endl;
	std::cout << "If you want to change the note, press 5. " << std::endl;
	std::cin >> selection;

	switch (selection)
	{
		case 1:
		{
			currentMeeting.setDate(option);
			book(Meeting(currentMeeting));
			break;
		}
		case 2:
		{
			currentMeeting.setStartTime(option);
			book(Meeting(currentMeeting));
			break;
		}
		case 3:
		{
			currentMeeting.setEndTime(option);
			book(Meeting(currentMeeting));
			break;
		}
		case 4:
		{
			currentMeeting.setName(option);
			book(Meeting(currentMeeting));
			break;
		}
		case 5:
		{
			currentMeeting.setNote(option);
			book(Meeting(currentMeeting));
			break;
		}
	*/
}


void Calendar::find(String string)
{
	for (size_t i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getName() == string || meetings[i].getNote() == string)
		{
				meetings[i].print();
		}
	}
}

void Calendar::holiday(String _date)
{
		Meeting holiday;
		holiday.setDate(_date);
		holiday.setName("Yaaay, you don't need to work today ^^ !!!");
		holiday.setNote("Holiday");
		holiday.setStartTime("00:00");
		holiday.setEndTime("23:59");

		/*
		String starttime;
		starttime.setArray("00:00");
		String endtime;
		starttime.setArray("23:59");
		String notee;
		notee.setArray("Holiday");
		String namee;
		namee.setArray("Yaaay, you don't need to work today ^^ !!!");

		holiday.setDate(_date);
		holiday.setStartTime(starttime);
		holiday.setEndTime(endtime);
		holiday.setNote(notee);
		holiday.setName(namee);*/

		if (meetings.overlapedMeetings(holiday))
		{
			book(holiday);
		}
		else
		{
			std::cout << "Error while freeing your holiday!";
		}
}


void Calendar::busyDays(String from, String to)
{
	meetings.sort();
	Vector <String> busyDays;
	int hoursPerDayOne = 0;
	int hoursPerDayTwo = 0;
	String one ;
	String two;

	for (size_t i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getDate().convertDateToInt() >= from.convertDateToInt() && meetings[i].getDate().convertDateToInt() <= to.convertDateToInt())
		{
			if (i == 0 || i % 2 == 0)
			{
				for (size_t j = i; meetings[j].getDate() == meetings[j + 1].getDate(); j++)
				{
					hoursPerDayOne += meetings[j].busyHour();
					one = meetings[j].getDate();
				}
			}
			else
			{ 
				for (size_t j = i; meetings[j].getDate() == meetings[j + 1].getDate(); j++)
				{
					hoursPerDayTwo += meetings[j].busyHour();
					two = meetings[j].getDate();
				}
			}

			if (hoursPerDayOne >= hoursPerDayTwo)
			{
				busyDays.pushBack(one);
			}
			if (hoursPerDayTwo > hoursPerDayOne)
			{
				busyDays.pushBack(two);
			}
		}
	}
	busyDays.print();
}

void Calendar::findSlot(String fromDate, int hours)
{
	meetings.sort();			  //hour - kolko vreme shte prodluji meetinga;
	Meeting newMeet;			 //proverqvam dali mejdu 2 meetinga imam vreme za noviq meet
				   				//sort sortira i po chas

	for (size_t i = 0; i < meetings.getSize(); i++) 
	{
		if (meetings[i].getNote() != "Holiday" && meetings[i].getDate().convertDateToInt()>=fromDate.convertDateToInt())
		{
			if (meetings[i + 1].getStartTime().convertTimeToInt() - meetings[i].getEndTime().convertTimeToInt() >= hours)
			{
				/*newMeet.setDate(meetings[i].getDate());
				newMeet.setStartTime(meetings[i].getEndTime());
				newMeet.setEndTime(meetings[i + 1].getStartTime());*/

				std::cout << "You can book your meet at : ";
				std::cout << meetings[i].getDate() << std::endl;
				std::cout << "From: ";
				std::cout << meetings[i].getEndTime() << std::endl;
				std::cout << "To: ";
				std::cout << meetings[i + 1].getStartTime() << std::endl;
				break;
			}
			if (meetings[i].getEndTime().convertTimeToInt() < 1700 && meetings[i].getEndTime().convertTimeToInt() + hours <= 1700)
			{
				/*newMeet.setDate(meetings[i].getDate());
				newMeet.setStartTime(meetings[i].getEndTime());
				newMeet.setEndTime("17:00");*/

				std::cout << "You can book your meet at : ";
				std::cout << meetings[i].getDate() << std::endl;
				std::cout << "From: ";
				std::cout << meetings[i].getEndTime() << std::endl;
				std::cout << "To: 17:00 " << std::endl;
				break;
			}
			if (meetings[i].getStartTime().convertTimeToInt() > 800 && meetings[i].getStartTime().convertTimeToInt() - hours >= 800)
			{
				/*newMeet.setDate(meetings[i].getDate());
				newMeet.setStartTime("08:00");
				newMeet.setEndTime(meetings[i + 1].getStartTime());*/

				std::cout << "You can book your meet at : ";
				std::cout << meetings[i].getDate() << std::endl;
				std::cout << "From: 08:00" << std::endl;
				std::cout << "To: " << std::endl;
				std::cout << meetings[i + 1].getStartTime() << std::endl;
				break;
			}
		}
	}
}

void Calendar::findSlotWith(String fromDate, int hours, Calendar calendar)
{
	meetings.sort();
	calendar.getMeetings().sort();
	Meeting newMeet;

	for (size_t i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getNote() != "Holiday" && meetings[i].getDate().convertDateToInt() >= fromDate.convertDateToInt())
		{
			if (meetings[i + 1].getStartTime().convertTimeToInt() - meetings[i].getEndTime().convertTimeToInt() >= hours)
			{
				newMeet.setDate(meetings[i].getDate());
				newMeet.setStartTime(meetings[i].getEndTime());
				newMeet.setEndTime(meetings[i + 1].getStartTime());
				break;
			}
			if (meetings[i].getEndTime().convertTimeToInt() < 1700 && meetings[i].getEndTime().convertTimeToInt() + hours <= 1700)
			{
				newMeet.setDate(meetings[i].getDate());
				newMeet.setStartTime(meetings[i].getEndTime());
				newMeet.setEndTime("17:00");
				break;
			}
			if (meetings[i].getStartTime().convertTimeToInt() > 800 && meetings[i].getStartTime().convertTimeToInt() - hours >= 800)
			{
				newMeet.setDate(meetings[i].getDate());
				newMeet.setStartTime("08:00");
				newMeet.setEndTime(meetings[i + 1].getStartTime());
				break;
			}
		}
	}

}


