/**
 * @author Vo Nguyen
 * CECS 282-04
 * Program 4 - Operator Overloading
 * 04/12/2022
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from
 * any other source. I further certify that I typed each and every line of code in this program.
 */


#include "upDate.h"
#include <iostream>
#include <string>

using namespace std;

int upDate::count = 0;

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
upDate::upDate() {
	++count;
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
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
 // upDate D1(10, 27, 2010)
upDate::upDate(int M, int D, int Y) {
	//Check date if it is invalid
	++count;
	dptr = new int[3];
	int JD = Greg2Julian(M, D, Y);
	dptr[0] = M;
	dptr[1] = D;
	dptr[2] = Y;

	Julian2Greg(JD, M, D, Y);

	if (!((dptr[0] == M) && (dptr[1] == D) && (dptr[2] == Y))) {
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
}

/**
 *An overloaded constructor initializes passing by Julian date.
 *
 * @param J Julian date.
 *
 */
upDate::upDate(int J) {
	++count;
	int m = 0, d = 0, y = 0;
	dptr = new int[3];
	Julian2Greg(J, m, d, y);
	dptr[0] = m;
	dptr[1] = d;
	dptr[2] = y;
}

/**
 * Deconstructor.
 */
upDate::~upDate() {
	delete []dptr;
	count--;
}

/**
 * Copy constructor.
 * 
 * @param D the upDate object to copy.
 *
 */
// upDate D2(D1)
upDate::upDate(const upDate& D) {
	++count;
	dptr = new int[3];
	dptr[0] = D.dptr[0];
	dptr[1] = D.dptr[1];
	dptr[2] = D.dptr[2];
}

/**
 * Assignment operator.
 *
 * @param D the upDate object is assigned to current object.
 * 
 * @return current object after assigning.
 *
 */
// upDate D3 = D2
upDate upDate::operator=(const upDate& D) {
	dptr = new int[3];
	dptr[0] = D.dptr[0];
	dptr[1] = D.dptr[1];
	dptr[2] = D.dptr[2];
	return *this;
}

/**
 * Implement += operator add num days to current object.
 * 
 * @param num number days to be added.
 * 
 * @return current object after adding num days. 
 *
 */
// D1 += 5
upDate upDate::operator+=(int num) {
	increaseDate(num);
	return *this;
}

/**
 * Implement -= operator subtract num days from current object.
 *
 * @param num number days to be subtracted from current object.
 *
 * @return current object.
 *
 */
// D1 -= 7
upDate upDate::operator-=(int num) {
	decreaseDate(num);
	return *this;
}

/**
 * Implement + operator add num days to given object.
 *
 * @param D given object to add.
 * @param num number days to be added.
 *
 * @return current object after adding num to D.
 *
 */
// D3 = D2 + 5
upDate operator+(upDate D, int num) {
	upDate d(D);
	d.increaseDate(num);
	return d;
}

/**
 * Implement +operator add num days to given object.
 *
 * @param num number days added.
 * @param D given object.
 *
 * @return current object after adding num to D.
 *
 */
// D3 = 5 + D2
upDate operator+(int num, upDate D) {
	return upDate(D + num);
}

/**
 * Implement -operator subtract num days from given object.
 *
 * @param num number days to be subtracted.
 * @param D given object.
 *
 * @return current object after subtracting num from D.
 *
 */

// D3 = D2 - 4;
upDate operator-(upDate D, int num) {
	upDate d(D);
	d.decreaseDate(num);
	return d;
}

/** 
 * Days between two upDate object.
 * 
 * @param D object from which the other object is subtracted.
 * @param d object to be subtracted from D.
 *
 * @return days between two upDate object.
 */
//int x = D5 - D4;
int operator-(upDate D, upDate d) {
	return d.daysBetween(D);
}

/**
 * Prefix ++ operator.
 *
 * @return current object increased by 1.
 */
// prefix
upDate upDate::operator++() {
	increaseDate(1);
	return *this;
}


/**
 * Postfix ++ operator.
 *
 * @return previous object before increased by 1.
 */
//postfix
upDate upDate::operator++(int) {
	upDate d(*this);
	++* this;
	return d;
}

/**
 * Prefix -- operator.
 *
 * @return current object decreased by 1.
 */
// prefix
upDate upDate::operator--() {
	decreaseDate(1);
	return *this;
}

/**
 * Postfix -- operator.
 *
 * @return previous object before decreased by 1.
 */
//postfix
upDate upDate::operator--(int) {
	upDate d(*this);
	--* this;
	return d;
}


/**
 * Increasing the date by N days.
 *
 * @param N number of days increasing.
 *
 */
void upDate::increaseDate(int N) {
	int JD = julian() + N;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);

}

/**
 * Decreasing the date by N days.
 *
 * @param N number of days decreasing.
 *
 */
void upDate::decreaseDate(int N) {
	int JD = julian() - N;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
}


/**
 * A number of days between current day and inputted day.
 *
 * @param D inputted day.
 *
 * @return the number of days between 2 dates.
 *
 */
int upDate::daysBetween(upDate D) const{
	int JD1 = julian();
	int JD2 = D.julian();

	return JD2 - JD1;
}

/**
 * Set current date to a new date.
 * 
 * @param M new month.
 * @param D new day.
 * @param Y new year.
 * 
 */
void upDate::setDate(int M, int D, int Y) {
	dptr[0] = M;
	dptr[1] = D;
	dptr[2] = Y;
}
/**
 * Retrieve month value.
 * 
 * @return month value.
 */
int upDate::getMonth() const{
	return dptr[0];
}

/**
 * Retrieve day value.
 *
 * @return day value.
 */
int upDate::getDay() const{
	return dptr[1];
}

/**
 * Retrieve year value.
 *
 * @return year value.
 */
int upDate::getYear() const{
	return dptr[2];
}


/**
 * Equal to operator between this object and given object.
 * 
 * @param d given object to be compared with.
 * 
 * @return true if they are the same and vice versa.
 * 
 */
bool upDate::operator ==(upDate d) {
	if (julian() == d.julian()) {
		return true;
	}
	return false;
}

/**
 * Less than operator between this object and given object.
 *
 * @param d given object to be compared with.
 *
 * @return true if this object comes before d and vice versa.
 *
 */
bool upDate::operator<(upDate d) {
	if (julian() < d.julian()) {
		return true;
	}
	return false;
}

/**
 * Greater than operator between this object and given object.
 *
 * @param d given object to be compared with.
 *
 * @return true if this object comes after d and vice versa.
 *
 */
bool upDate::operator>(upDate d) {
	if (julian() > d.julian()) {
		return true;
	}
	return false;
}

/**
 * Retrieve the date with format: 1/1/2000.
 *
 * @return the date with format: 1/1/2000.
 */
ostream& operator<<(ostream& out, const upDate& D) {
	out << D.getMonth() << "/" << D.getDay() << "/" << D.getYear();
	return out;
}

/**
 * Retrieve Julian date.
 * 
 * @return Julian date.
 */
int upDate::julian() const{
	return Greg2Julian(getMonth(), getDay(), getYear());
}

/**
 * Retrieve the number of upDate.
 * 
 * @return the number of upDate.
 */
int upDate::GetDateCount() {
	return count;
}


