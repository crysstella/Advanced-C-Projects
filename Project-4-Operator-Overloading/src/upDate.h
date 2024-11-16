/**
 * @author Vo Nguyen
 * CECS 282-04
 * Program 4 - Operator Overloading
 * 04/12/2022
 *
 * I certify that this program is my own original work. I did not copy any part of this program from
 * any other source. I further certify that I typed each and every line of code in this program.
 */

#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <string>

using namespace std;

class upDate {
private:
	int* dptr;
	static int count;

public:
	upDate();
	upDate(int M, int D, int Y);
	upDate(int J);
	upDate(const upDate& D);
	~upDate();
	upDate operator=(const upDate&);
	upDate operator+=(int);
	upDate operator-=(int);
	upDate operator++(); //prefix
	upDate operator++(int); //postfix
	upDate operator--(); //prefix
	upDate operator--(int); //postfix
	bool operator ==(upDate);
	bool operator<(upDate);
	bool operator>(upDate);
	friend ostream& operator<<(ostream& out, const upDate&);
	friend upDate operator+(upDate, int);
	friend upDate operator+(int, upDate);
	friend upDate operator-(upDate, int);
	friend int operator-(upDate, upDate);
	int julian() const;
	static int GetDateCount();
	void increaseDate(int N);
	void decreaseDate(int N);
	int daysBetween(upDate D) const;
	void setDate(int M, int D, int Y);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	
};


#endif
