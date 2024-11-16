#ifndef MYDATE_H
#define MYDATE_H

#include <string>

class myDate {
private:
	int month;
	int day;
	int year;
public:
	myDate();
	myDate(int M, int D, int Y);
	void display();
	void increaseDate(int N);
	void decreaseDate(int N);
	void addMonth();
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	std::string dayName();
};

#endif