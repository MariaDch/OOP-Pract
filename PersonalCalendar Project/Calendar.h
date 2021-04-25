#pragma once
#include "String.h"
#include "Vector.h"
#include <ctime>

class Calendar
{
private:
	String date;
	Vector<> meetings;

public:
	//void book(String name, String note, String date, starttime,endtime);
	void unbook(String);
};