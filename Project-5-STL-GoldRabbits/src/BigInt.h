/**
 * @author Stellar Nguyen
 * CECS 282-04
 * Program 5 - Gold Rabbits
 * 04/26/2022
 *
 * I certify that this program is my own original work. I did not copy any part of this program from
 * any other source. I further certify that I typed each and every line of code in this program.
 */

#ifndef BIGINT_H
#define BIGINT_H
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class BigInt {
private:
	vector<char> digits;
public:
	BigInt();
	BigInt(int);
	BigInt(const string);
	void print();
	friend ostream& operator << (ostream& out, BigInt);
	BigInt operator +(BigInt);
	BigInt operator -(BigInt);
	bool operator <= (BigInt);
	bool operator == (BigInt);
	bool operator != (BigInt);
	BigInt operator++(int); //postfix
	bool operator<(const BigInt&) const;



};
#endif