/**
 * @author Stellar Nguyen
 * CECS 282-04
 * Program 5 - Gold Rabbits
 * 04/26/2022
 *
 * I certify that this program is my own original work. I did not copy any part of this program from
 * any other source. I further certify that I typed each and every line of code in this program.
 */

#include "BigInt.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

/**
 * A default constructor
 */
BigInt::BigInt() {
	//do nothing
}

/**
 * An overloaded constructor passed by the number of integer
 * to store each digit in a number to Big Int vector.
 * 
 * @param num the number of integer.
 */
BigInt::BigInt(int num) {
	int digit = 0;
	if (num == 0) {
		digits.push_back('0');
	}
	else {
		while (num > 0) {
			digit = num % 10;
			digits.push_back(digit + 48);
			num = num / 10;
		}
	}

}

/**
 * An overloaded constructor passed by a string of a number
 * to store each digit to a Big Int vector.
 * 
 * @param n a string of a number.
 * 
 */
BigInt::BigInt(const string n) {
	for (int i = n.length() - 1; i >= 0; i--) {
		digits.push_back(n[i]);
	}
}


/**
 * Print all digits of a number.
 */
void BigInt::print() {
	for (int i = digits.size() - 1; i >= 0; i--) {
		cout << digits[i];
	}
}

/**
 * Retrieve scientific notation of a number which has more than 36 digits.
 * 
 * @return a scientific notation of a number.
 */
ostream& operator << (ostream& out, BigInt B) {
	//12345 = 1.2345e4
	vector<char> ::reverse_iterator rit;
	int size = B.digits.size();
	int e = size - 1;
	rit = B.digits.rbegin();

	if (size < 36) {
		for (; rit != B.digits.rend(); rit++) {
			out << *rit;
		}
	}
	else {
		rit = B.digits.rbegin();
		out << *rit << ".";
		rit++;

		for (; rit != (B.digits.rend() - B.digits.size() + 13); rit++) {
			out << *rit;
		}
		out << "e" << to_string(e);
	}
	
	
	return out;
}

/**
 * Implement an addition of two Big Int numbers.
 *
 * @param B Big Int number.
 *
 * @return a result by adding two Big Int numbers.
 *
 */
BigInt BigInt::operator +(BigInt B) {
	int carry = 0;
	BigInt result;
	vector<char> temp1;
	vector<char> temp;

	int smaller = 0;
	int larger = 0;
	if (digits.size() > B.digits.size()) {
		smaller = B.digits.size();
		larger = digits.size();
		temp = B.digits;
		temp1 = digits;
		for (int extend = 0; extend < (larger - smaller); extend++) {
			temp.push_back('0');
		}
	}
	else if (digits.size() < B.digits.size()) {
		smaller = digits.size();
		larger = B.digits.size();
		temp = digits;
		temp1 = B.digits;
		for (int extend = 0; extend < (larger - smaller); extend++) {
			temp.push_back('0');
		}
	}
	else {
		smaller = digits.size();
		larger = smaller;
		temp1 = digits;
		temp = B.digits;
	}
	/*
	  111
	 1249834     7
   +   50235     5
   ------------
	 1300069
	*/

	for (int i = 0; i < larger; i++) {
		int a = temp1[i] - '0'; //'0'= 48
		int b = temp[i] - '0';
		int ans = a + b + carry;

		result.digits.push_back(ans % 10 + 48);

		if (a + b + carry > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		if (i >= larger - 1) {
			if (ans / 10 != 0) {
				result.digits.push_back(ans / 10 + 48);
			}
		}
	}
	return result;

}

/**
 * Implement a subtraction of two Big Int numbers.
 *
 * @param B Big Int number.
 *
 * @return a result by subtract Big Int number from this number.
 *
 */
BigInt BigInt::operator -(BigInt B) {
	//assume a result always positive
	//so this is larger than B
	vector<char> temp = B.digits;
	BigInt result;
	if (*this == B) {
		return BigInt(0);
	}
	int diff = digits.size() - B.digits.size();
	if (diff != 0) {
		for (int extend = 0; extend < diff; extend++) {
			temp.push_back('0');
		}
	}

	/*

	 1249834     7
   -   50235     5
   ------------
	 1199599
	*/
	int carry = 0;
	for (int i = 0; i < digits.size(); i++) {
		int a = digits[i] - '0';
		int b = temp[i] - '0';
		int ans = 0;
		if (a < (b + carry)) {
			a += 10;
			ans = a - (b + carry);
			carry = 1;
		}
		else {
			ans = a - (b + carry);
			carry = 0;
		}
		result.digits.push_back(ans % 10 + 48);
		if (i >= digits.size() - 1) {
			if (ans / 10 != 0) {
				result.digits.push_back(ans / 10 + 48);
			}
		}

	}
	//avoid the result 12356 - 12333 = 00023 remove 0
	for (int i = result.digits.size() - 1; i >= 0; i--) {
		if (result.digits[i] != '0') {
			break;
		}
		else if (result.digits[i] == '0') {
			result.digits.pop_back();
		}
	}

	return result;
}

/**
 * Less than or equal operator between this number and given number.
 *
 * @param B given number to be compared with.
 *
 * @return true if this number less than or equal to B and vice versa.
 *
 */
bool BigInt::operator<=(BigInt B) {
	if ((*this < B) || (*this == B))
		return true;
	return false;
}

/**
 * Equal to operator between this number and given number.
 *
 * @param B given number to be compared with.
 *
 * @return true if two numbers are the same and vice versa.
 *
 */
bool BigInt::operator == (BigInt B) {
	if (digits.size() == B.digits.size()) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] != B.digits[i])
				return false;
		}
		return true;
	}
	return false;
}

/**
 * Not equal to operator between this number and given number.
 *
 * @param B given number to be compared with.
 *
 * @return true if two numbers are not the same and vice versa.
 *
 */
bool BigInt::operator != (BigInt B) {
	if (!(*this == B)) {
		return true;
	}
	return false;
}


/**
 * Postfix ++ operator.
 * 
 * @return previous number before being increased by 1.
 */
BigInt BigInt::operator++(int) {
	BigInt big(*this);
	*this = *this + BigInt(1);
	return big;
}

/**
* Less than operator between this number and given number.
*
* @param B given number to be compared with.
*
* @return true if this number is less than B and vice versa.
*
*/
bool BigInt::operator<(const BigInt& B) const {

	if (digits.size() < B.digits.size()) {
		return true;
	}
	else if (digits.size() == B.digits.size()) {
		//114532 and 114983
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] < B.digits[i]) {
				return true;
			}
			else if (digits[i] > B.digits[i]) {
				return false;
			}
		}
	}
	return false;
}
