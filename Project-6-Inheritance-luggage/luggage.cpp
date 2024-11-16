/**
* @author Stellar Nguyen
* CECS 282 - 04
* Program 6 - Inheritance Luggage
* 05 / 05 / 2022
*
* I certify that this program is my own original work.I did not copy any part of this program from
* any other source.I further certify that I typed each and every line of code in this program.
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <iterator>

using namespace std;

class luggage {
private:
	static double volume;
protected:
	static int count;
	string type;
	static int serialNumGen;
	int serialNumber;
public:
	/**
	 * Constructor creates a new luggage.  
	 */
	luggage() {
		cout << "Creating luggage " << endl;
		serialNumber = serialNumGen++;
		count++;
	}

	/**
	 * Destructor destroys a luggage. 
	 */
	virtual ~luggage() {
		cout << "luggage destructor " << getSN() << endl;
		count--;
	}

	/**
	 * Get volume of each type of luggage.
	 * 
	 * @return volume of each type of luggage.
	 */
	virtual double getVolume() = 0;

	/**
	 * Updating total luggage volume.
	 * 
	 * @param v volume added to total volume.
	 */
	//static because access static member
	void static updateVolume(double v) {
		volume += v;
	}

	/**
	 * Retrieve total luggages.
	 * 
	 * @return total luggages.
	 */
	static int getCount() {
		return count;
	}

	/**
	 * Retrieve a type of luggage.
	 * 
	 * @return a type of luggage.
	 */
	string getType() {
		return type;
	}

	/**
	 * Retrieve a serial number of one luggage.
	 *
	 * @return a serial number of one luggage.
	 */
	string getSN() {
		return "(SN:" + to_string(serialNumber) + ")";
	}

	/**
	 * Retrieve a total volume of luggage.
	 * 
	 * @return a total volume of luggage.
	 */
	static double getLuggageVolume() {
		return volume;
	}


	/**
	 * Retrieve a luggage info: type, volume, and serial number
	 * ex: box		:   6.0    (SN:1).
	 * 
	 * @return a luggage info: type, volume, and serial number.
	 */
	friend ostream& operator<<(ostream& out, luggage* lptr) {
		out << setw(10) << left << lptr->getType() << ": " << setw(6) << right << setprecision(1) << fixed << lptr->getVolume() << setw(10) << right << lptr->getSN();
		return out;
	}
	
};


class box : public luggage {
private:
	static double volume;
	static int count;
	double length, width, height;


public:
	/**
	 * Constructor creates a new box.
	 */
	box(double w, double h, double l) {
		count++;
		length = l;
		width = w;
		height = h;
		type = "box";
		volume += getVolume();
		cout << "Creating box" << "(Volume: " << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
		updateVolume(getVolume());
	}

	/**
	 * Destructor destroys a box.
	 */
	~box() {
		count--;
		updateVolume(getVolume() * -1);
		cout << "box destructor" << "(Volume:" << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
		volume -= getVolume();
	}

	/**
	 * Get volume of one box.
	 *
	 * @return volume of one box.
	 */
	double getVolume() {
		return width * height * length;
	}

	/**
	 * Retrieve a total volume of boxes.
	 *
	 * @return a total volume of boxes.
	 */
	static double getBoxVolume() {
		return volume;
	}

	/**
	 * Retrieve total boxes.
	 *
	 * @return total boxes.
	 */
	static int getCount(){
		return count;
	}

};


class sphere : public luggage {
private:
	double radius;
	static int count;
	static double volume;
public:
	/**
	 * Constructor creates a new sphere.
	 */
	sphere(double r) {
		count++;
		radius = r;
		volume += getVolume();
		type = "sphere";
		cout << "Creating sphere" << "(Volume: " << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
		updateVolume(getVolume());
	}

	/**
	 * Destructor destroys a sphere.
	 */
	~sphere() {
		count--;
		volume -= getVolume();
		updateVolume(getVolume() * -1);
		cout << "sphere destructor" << "(Volume:" << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
	}

	/**
	 * Get volume of one sphere.
	 *
	 * @return volume of one sphere.
	 */
	double getVolume() {
		return (4.0 / 3) * M_PI * pow(radius, 3.0);
	}

	/**
	 * Retrieve a total volume of spheres.
	 *
	 * @return a total volume of spheres.
	 */
	static double getSphereVolume() {
		return volume;
	}

	/**
	 * Retrieve total spheres.
	 *
	 * @return total spheres.
	 */
	static int getCount() {
		return count;
	}
};

class cube: public luggage {
private:
	double width;
	static int count;
	static double volume;
public:
	/**
	 * Constructor creates a new cube.
	 */
	cube(double w) {
		count++;
		width = w;
		volume += getVolume();
		type = "cube";
		cout << "Creating cube" << "(Volume: " << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
		updateVolume(getVolume());

	}
	/**
	 * Destructor destroys a cube.
	 */
	~cube() {
		count--;
		updateVolume(getVolume() * -1);
		volume -= getVolume();
		cout << "cube destructor" << "(Volume:" << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
	}

	/**
	 * Get volume of one cube.
	 *
	 * @return volume of one cube.
	 */
	double getVolume() {
		return pow(width, 3.0);
	}

	/**
	 * Retrieve a total volume of cubes.
	 *
	 * @return a total volume of cubes.
	 */
	static double getCubeVolume() {
		return volume;
	}

	/**
	 * Retrieve total cubes.
	 *
	 * @return total cubes.
	 */
	static int getCount(){
		return count;
	}
};

class pyramid: public luggage {
private:
	double base, height;
	static int count;
	static double volume;
public:
	/**
	 * Constructor creates a new pyramid.
	 */
	pyramid(double b, double h) {
		count++;
		base = b;
		height = h;
		volume += getVolume();
		type = "pyramid";
		cout << "Creating pyramid" << "(Volume: " << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
		updateVolume(getVolume());
	}

	/**
	 * Destructor destroys a pyramid.
	 */
	~pyramid() {
		count--;
		updateVolume(getVolume() * -1);
		volume -= getVolume();
		cout << "pyramid destructor" << "(Volume:" << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
	}

	/**
	 * Get volume of one pyramid.
	 *
	 * @return volume of one pyramid.
	 */
	double getVolume() {
		return (pow(base, 2) * height) / 3;
	}

	/**
	 * Retrieve a total volume of pyramids.
	 *
	 * @return a total volume of pyramids.
	 */
	static double getPyramidVolume() {
		return volume;
	}

	/**
	 * Retrieve total pyramids.
	 *
	 * @return total pyramids.
	 */
	static int getCount(){
		return count;
	}
};


class cylinder: public luggage {
private: 
	double radius, length;
	static int count;
	static double volume;

public:
	/**
	 * Constructor creates a new cylinder.
	 */
	cylinder(double r, double l) {
		count++;
		radius = r;
		length = l;
		volume += getVolume();
		type = "cylinder";
		cout << "Creating cylinder" << "(Volume: " << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
		updateVolume(getVolume());
	}

	/**
	 * Destructor destroys a cylinder.
	 */
	~cylinder() {
		count--;
		updateVolume(getVolume() * -1);
		volume -= getVolume();
		cout << "cylinder destructor" << "(Volume:" << setprecision(1) << fixed << getVolume() << ") -- " << getSN() << endl;
	}

	/**
	 * Get volume of one cylinder.
	 *
	 * @return volume of one cylinder.
	 */
	double getVolume() {
		return M_PI * pow(radius, 2.0) * length;
	}

	/**
	 * Retrieve a total volume of cylinders.
	 *
	 * @return a total volume of cylinders.
	 */
	static double getCylinderVolume() {
		return volume;
	}

	/**
	 * Retrieve total cylinders.
	 *
	 * @return total cylinders.
	 */
	static int getCount() {
		return count;
	}
	
};

//Initialize variables of luggage and each type of luggage.
int luggage::count = 0;
int luggage::serialNumGen = 1;
double luggage::volume = 0;
int box::count = 0;
double box::volume = 0;
int sphere::count = 0;
double sphere::volume = 0;
int cube::count = 0;
double cube::volume = 0;
int pyramid::count = 0;
double pyramid::volume = 0;
int cylinder::count = 0;
double cylinder::volume = 0;

/**
 * Inform menu option and get user's input.
 * 
 * @return user's input.
 */
int getUserInput();

int main() {
	vector<luggage*> container;
	
	int input = 0;
	while (input != 5) {
		input = getUserInput();
		int count = 0;
		bool stop = false;
		int type = 0;
		vector <luggage*> ::iterator it = container.begin();
		switch (input) {
		// Add a new luggage.
		case 1:
			cout << "Choose one of these luggage types: " << endl;
			cout << "1) Box\n2) Sphere\n3) Cube\n4) Pyramid\n5) Cylinder" << endl;
			while (!stop) {
				cin >> type;
				if ((type < 1) || (type > 5)) {
					cout << "You entered an invalid input! Please enter again: ";
				}
				else {
					stop = true;
				}
			}

			switch (type) {
			// Add a box.
			case 1:
				double width, height, length;
				cout << "Enter width: "; cin >> width;
				cout << "Enter height: "; cin >> height;
				cout << "Enter length: "; cin >> length;
				container.push_back(new box(width, height, length));
				break;
			// Add a sphere.
			case 2:
				double radius;
				cout << "Enter radius: "; cin >> radius;
				container.push_back(new sphere(radius));
				break;
			// Add a cube.
			case 3:
				double w;
				cout << "Enter width: "; cin >> w;
				container.push_back(new cube(w));
				break;
			// Add a pyramid.
			case 4:
				double base, h;
				cout << "Enter base: "; cin >> base;
				cout << "Enter height: "; cin >> h;
				container.push_back(new pyramid(base, h));
				break;
			// Add a cylinder.
			case 5:
				double r, l;
				cout << "Enter radius: "; cin >> r;
				cout << "Enter length: "; cin >> l;
				container.push_back(new cylinder(r,l));
				break;
			default:
				break;
			}
			break;
		// Remove one luggage.
		case 2:
			cout << "Current luggages from storage container: " << endl;

			for (auto l : container)
				cout << ++count << ") " << l << endl;
			int remove;
			cout << "Enter an item to remove: ";
			while (!stop) {
				cin >> remove;
				if ((remove < 1) || (remove > container.size())) {
					cout << "Your input is out of range. Please enter again: ";
				}
				else {
					stop = true;
				}
			}
			it = it + remove - 1;
			delete *it;
			container.erase(it);
			break;
		// Show all luggage.
		case 3:
			cout << "Current luggages from storage container: " << endl;
			for (auto l : container)
				cout << ++count << ") " << l << endl;
			cout << endl << setw(10) << left << "Total volume: " << setw(15) << right << luggage::getLuggageVolume() << endl << endl;
			cout << setw(10) << left << "Total Luggage Items: " << setw(6) << right << luggage::getCount() << endl;

			if (box::getCount() > 0)
			 cout << setw(10) << left << "Total boxes: " << setw(14) << right << box::getCount() << endl;
			if (sphere::getCount() > 0)
				cout << setw(10) << left << "Total spheres: " << setw(12) << right << sphere::getCount() << endl;
			if (cube::getCount() > 0)
				cout << setw(10) << left << "Total cubes: " << setw(14) << right << cube::getCount() << endl;
			if (pyramid::getCount() > 0)
				cout << setw(10) << left << "Total pyramids: " << setw(11) << right << pyramid::getCount() << endl;
			if (cylinder::getCount() > 0)
				cout << setw(10) << left << "Total cylinders: " << setw(10) << right << cylinder::getCount() << endl;
			break;
		// Show total volume.
		case 4:
			cout << setw(10) << left << "Item Type" << setw(15) << right << "Total Volume" << endl;
			if (box::getBoxVolume() > 0)
				cout << setw(10) << left << "Box" << setw(15) << right << box::getBoxVolume() << endl;
			if (sphere::getSphereVolume() > 0)
				cout << setw(10) << left << "Sphere" << setw(15) << right << sphere::getSphereVolume() << endl;
			if (cube::getCubeVolume() > 0)
				cout << setw(10) << left << "Cube" << setw(15) << right << cube::getCubeVolume() << endl;
			if (pyramid::getPyramidVolume() > 0)
				cout << setw(10) << left << "Pyramid" << setw(15) << right << pyramid::getPyramidVolume() << endl;
			if (cylinder::getCylinderVolume() > 0)
				cout << setw(10) << left << "Cylinder" << setw(15) << right << cylinder::getCylinderVolume() << endl;
			cout << setw(10) << left << "Luggage" << setw(15) << right << luggage::getLuggageVolume() << endl;
			break;
		// Quit a program.
		case 5:
			break;
		default:
			break;
		}
	}

	return 0;
}

/**
 * Inform menu option and get user's input.
 *
 * @return user's input.
 */
int getUserInput() {
	cout << endl;
	cout << "1) Add luggage to storage container" << endl;
	cout << "2) Remove luggage from storage container" << endl;
	cout << "3) Show all luggage" << endl;
	cout << "4) Show total volumes" << endl;
	cout << "5) Quit" << endl;

	int input = 0;
	bool stop = false;
	while (!stop) {
		cin >> input;
		// Check input if it is out ouf range.
		if ((input < 1) || (input > 5)) {
			cout << "You entered an invalid input! Please enter again: ";
		}
		else {
			stop = true;
		}
		
	}
	return input;
}