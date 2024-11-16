#include "myDate.h"
#include <iostream>
using namespace std;

/**
 * Convert Gregorian date to Julian date.
 * 
 * @param month a month.
 * @param day a number of days.
 * @param year a number of a year.
 * 
 * @return Julian number after converting.
 */
int Greg2Julian(int month, int day, int year) {
	int i, j, k;
	i = year;
	j = month;
	k = day;

	int JD = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;

	return JD;
}

/**
 * Convert Julian date number to Gregorian date.
 * 
 * @param JD a Julian date number.
 * @param month a month.
 * @param day a number of days.
 * @param year a number of a year. 
 *
 */
void Julian2Greg(int JD, int& month, int& day, int& year) {
	int i, j, k;

	int l = JD + 68569;
	int n = 4 * l / 146097;
	
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	j = 80 * l / 2447;
	k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;

	year = i;
	month = j;
	day = k;
}

/**
 * A default constructor create default month, day, and year
 * to 5/11/1959.
 */
myDate::myDate() {
	month = 5;
	day = 11;
	year = 1959;
}

/**
 * An overloaded constructor initializes given month, day, and year
 * and then checks if the date is valid, if not, date will be a default day.
 * 
 * @param M a month.
 * @param D a number of days.
 * @param Y a number of a year.
 * 
 */
myDate::myDate(int M, int D, int Y) {
	//Check date if it is invalid
	int JD = Greg2Julian(M, D, Y); 
	month = M;
	day = D;
	year = Y;

	Julian2Greg(JD, M, D, Y);

	if (!((month == M) && (day == D) && (year == Y))) {
		month = 5;
		day = 11;
		year = 1959;
	}

}

/**
 * Display the date in format May 11, 1959.
 *
 */
void myDate::display() {
	switch (month) {
	case 1:
		cout << "January ";
		break;
	case 2:
		cout << "February ";
		break;
	case 3:
		cout << "March ";
		break;
	case 4:
		cout << "April ";
		break;
	case 5: 
		cout << "May ";
		break;
	case 6:
		cout << "June ";
		break;
	case 7: 
		cout << "July ";
		break;
	case 8: 
		cout << "August ";
		break;
	case 9:
		cout << "September ";
		break;
	case 10: 
		cout << "October ";
		break;
	case 11:
		cout << "November ";
		break;
	default:
		cout << "December ";
		break;
	}

	cout << day << ", " << year;
}

/**
 * Increasing the date by N days.
 * 
 * @param N number of days increasing.
 * 
 */
void myDate::increaseDate(int N) {
	int JD = Greg2Julian(month, day, year) + N;
	Julian2Greg(JD, month, day, year);

}

/**
 * Decreasing the date by N days.
 *
 * @param N number of days decreasing.
 *
 */
void myDate::decreaseDate(int N) {
	int JD = Greg2Julian(month, day, year) - N;
	Julian2Greg(JD, month, day, year);
}

/**
 * Increment a month by 1
 * and check if the increased date is valid.
 * 
 */
void myDate::addMonth() {
	//Check leap year
	int feb = 2;
	int t = 29;
	bool leap = false;
	int JD = Greg2Julian(feb, t, year);
	Julian2Greg(JD, feb, t, year);

	if (feb == 2) {
		leap = true;
	}

	int m = month;
	int JD_current = Greg2Julian(month, day, year);
	month += 1;
	JD = Greg2Julian(month, day, year);
	Julian2Greg(JD, month, day, year);

	if (month > m + 1) {
		if (month == 3) {
			if (leap == true) {
				day = 29;
			}
			else { day = 28; }
			month = 2;
		}
		else {
			month = m + 1;
			day = 30;
		}
	}

	JD = Greg2Julian(month, day, year);
	
}

/**
 * A number of days between current day and inputted day.
 * 
 * @param D inputted day.
 * 
 * @return the number of days between 2 dates.
 * 
 */
int myDate::daysBetween(myDate D) {
	int JD1 = Greg2Julian(month, day, year);
	int JD2 = Greg2Julian(D.getMonth(), D.getDay(), D. getYear());

	return JD2 - JD1;
}

/**
 * Retrieve a month value.
 * 
 * @return a month value.
 * 
 */
int myDate::getMonth() {
	return month;
}

/**
 * Retrieve a number of days.
 *
 * @return a number of days.
 *
 */
int myDate::getDay() {
	return day;
}

/**
 * Retrieve a year value.
 *
 * @return a year value.
 *
 */
int myDate::getYear() {
	return year;
}

/**
 * Retrieve a number of days between the first day of
 * a year and current day of a same year (includes the last day).
 * 
 * @return a number of days between two dates.
 *
 */
int myDate::dayOfYear() {
	myDate beginYear(1, 1, year);
	return abs(daysBetween(beginYear)) + 1;
}

/**
 * Retrieve the name of the day in a week (Monday, Tuesday, ...).
 * 
 * @return a name of the week day.
 * 
 */
std::string myDate::dayName() {
	int JD = Greg2Julian(month, day, year);
	int dayName = JD % 7;

	//0:Mon  1:Tues  2:Wed  3:Thurs  4:Fri  5:Sat  6:Sun
	switch (dayName) {
	case 0:
		return "Monday";
	case 1:
		return "Tuesday";
	case 2: 
		return "Wednesday";
	case 3:
		return "Thursday";
	case 4:
		return "Friday";
	case 5:
		return "Saturday";
	case 6:
		return "Sunday";
	defaut:
		break;
	}

	return " ";
}