/**
 * @brief A program allows user to sort movies' datas by movie's Name, Running Time, 
 * IMDB Rating, Release Date, and Main Actor.
 * 
 * @author Stellar Nguyen.
 * March 16, 2022
 *
 */

#include "myDate.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

struct Movie {
	char name[30];
	int time;
	double rt;
	myDate releaseDate;
	string actor;
};

int menu();
void populate(Movie* mov[]);
void display(Movie* mov[]);
string getTime(int time);
void sortbyName(Movie* mov[]);
void sortbyTime(Movie* mov[]);
void sortbyRating(Movie* mov[]);
void sortbyDate(Movie* mov[]);
void sortbyActor(Movie* mov[]);
int partition(Movie* mov[], int size, int type);
void quicksort(Movie* mov[], int size, int type);



int main() {
	Movie* mov[10];
	populate(mov);
	display(mov);
	cout << endl;

	srand(time(NULL));

	int choice = 0;
	bool stop = false;
	while (!stop) {
		choice = menu();
		//1. Name, 2. Running time, 3. Rating, 4. Release Date, 5. Actor
		switch (choice) {
		case 1:
			sortbyName(mov);
			break;
		case 2:
			sortbyTime(mov);
			break;
		case 3:
			sortbyRating(mov);
			break;
		case 4:
			sortbyDate(mov);
			break;
		case 5:
			sortbyActor(mov);
			break;
		case 6:
			stop = true;
			break;
		}
		if (!stop) {
			cout << endl;
			display(mov);
			cout << endl;
		}
		
	}
	

	return 0;

}

/**
 * Allocates 10 movie structure and populates each movie. 
 * 
 * @param mov a pointer array of movie structure.
 *
 */
void populate(Movie* mov[]) {
	for (int i = 0; i < 10; i++) {
		mov[i] = new Movie;
	}
	strncpy_s(mov[0]->name, "The Matrix", 30);
	mov[0]->time = 136;
	mov[0]->rt = 8.7;
	mov[0]->releaseDate = myDate(3, 31, 1999);
	mov[0]->actor = "Keano Reeves";
	
	strncpy_s(mov[1]->name, "Water World", 30);
	mov[1]->time = 177;
	mov[1]->rt = 6.2;
	mov[1]->releaseDate = myDate(7, 28, 1995);
	mov[1]->actor = "Kevin Cosner";

	strncpy_s(mov[2]->name, "Easy Rider", 30);
	mov[2]->time = 95;
	mov[2]->rt =7.3;
	mov[2]->releaseDate = myDate(6, 26, 1969);
	mov[2]->actor = "Peter Fonda";

	strncpy_s(mov[3]->name, "Forrest Gump", 30);
	mov[3]->time = 142;
	mov[3]->rt = 8.8;
	mov[3]->releaseDate = myDate(6, 23, 1994);
	mov[3]->actor = "Tom Hanks";

	strncpy_s(mov[4]->name, "Interstellar", 30);
	mov[4]->time = 169;
	mov[4]->rt = 8.7;
	mov[4]->releaseDate = myDate(10, 26, 2014);
	mov[4]->actor = "Matthew McConaughey";

	strncpy_s(mov[5]->name, "Spider-Man: No Way Home", 30);
	mov[5]->time = 148;
	mov[5]->rt = 8.5;
	mov[5]->releaseDate = myDate(12, 17, 2021);
	mov[5]->actor = "Tom Holland";

	strncpy_s(mov[6]->name, "The Godfather", 30);
	mov[6]->time = 177;
	mov[6]->rt = 9.2;
	mov[6]->releaseDate = myDate(2, 14, 1972);
	mov[6]->actor = "Marlon Brando";

	strncpy_s(mov[7]->name, "Inception", 30);
	mov[7]->time = 148;
	mov[7]->rt = 8.7;
	mov[7]->releaseDate = myDate(7, 8, 2010);
	mov[7]->actor = "Leonardo DiCaprio";

	strncpy_s(mov[8]->name, "Divergent", 30);
	mov[8]->time = 140;
	mov[8]->rt = 6.7;
	mov[8]->releaseDate = myDate(3, 18, 2014);
	mov[8]->actor = "Shailene Woodley";

	strncpy_s(mov[9]->name, "When in Rome", 30);
	mov[9]->time = 91;
	mov[9]->rt = 5.5;
	mov[9]->releaseDate = myDate(1, 29, 2010);
	mov[9]->actor = "Kristen Bell";

}

/**
 * Display each movie's information: Name, Running time, 
 * Rating, Release Date, and Main Actor.
 * 
 * @param mov a pointer array of movie structure.
 * 
 */
void display(Movie* mov[]) {
	string underline = "\033[4m";
	string closeu = "\033[0m";
	
	cout << underline << "Name" << closeu;
	cout << setw(23) << left << "" << underline << "Running Time" << closeu;
	cout << setw(4) << left << "" << underline << "IMDB Rating" << closeu;
	cout << setw(5) << left << "" << underline << "Release Date" << closeu;
	cout << setw(10) << left << "" << underline << "Main Actor" << closeu;
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << setw(27) << left << mov[i]->name
		     << setw(16) << left << getTime(mov[i]->time)
		     << setw(16) << left << mov[i]->rt
		     << setw(22) << left << mov[i]->releaseDate.getDate()
		     << setw(20) << left << mov[i]->actor << endl;
	}
}

/**
 * Display the menu option and get user's input.
 * 
 * @return user's input.
 *
 */
int menu() {
	cout << "1. Display list sorted by Name" << endl;
	cout << "2. Display lsit sorted by Running Time" << endl;
	cout << "3. Display list sorted by IMDB Rating" << endl;
	cout << "4. Display list sorted by Release Date" << endl;
	cout << "5. Display list sorted by Main Actor" << endl;
	cout << "6. Exit" << endl;

	int input = 0;
	cout << "Choose your option: ";
	cin >> input;
	
	while ((!cin) || (input < 1) || (input > 6)) {
		cout << "Invalid input. Please enter again: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> input;
	}
	return input;
}

/**
 * Sort the movies by Name (type 1).
 * 
 * @param mov a pointer array of movie structure.
 *
 */
void sortbyName(Movie* mov[]) {
	quicksort(mov, 10, 1);
}

/**
 * Sort the movies by Running Time (type 2).
 *
 * @param mov a pointer array of movie structure.
 *
 */
void sortbyTime(Movie* mov[]) {
	quicksort(mov, 10, 2);
}

/**
 * Sort the movies by IMDB Rating (type 3).
 *
 * @param mov a pointer array of movie structure.
 *
 */
void sortbyRating(Movie* mov[]) {
	quicksort(mov, 10, 3);
}

/**
 * Sort the movies by release Date (type 4).
 *
 * @param mov a pointer array of movie structure.
 *
 */
void sortbyDate(Movie* mov[]) {
	quicksort(mov, 10, 4);
}

/**
 * Sort the movies by actor's name (type 5).
 *
 * @param mov a pointer array of movie structure
 *
 */
void sortbyActor(Movie* mov[]) {
	quicksort(mov, 10, 5);
}

/**
 * Find a pair on the wrong sides of the array based on the pivot
 * If mov[i] >= pivot, mov[i] should be on right side and vice versa
 * /Sorting by name (1), running time (2), rating (3), release date (4), and actor's name (5).
 * 
 * @param mov a pointer array of movie structure.
 * @param size size of movies.
 * @param type of sorting.
 * 
 * @return an index of right half.
 * 
 */
int partition(Movie* mov[], int size, int type) {
	int s = 0; 
	if (size > 2) {
		s = rand() % (size - 2) + 1;
	}
	else if (size == 2) {
		s = 1;
	}
	int i = -1, j = size;

	if (type == 1) {
		char cpivot[30] = "";
		strncpy_s(cpivot, mov[s]->name, 30);
		int cmp = 0;
		while (true) {
			do {
				++i;
				cmp = strcmp(mov[i]->name, cpivot);
			} while (cmp < 0);

			do {
				--j;
				cmp = strcmp(mov[j]->name, cpivot);
			} while (cmp > 0);

			if (i >= j) {
				return j + 1;
			}

			swap(mov[i], mov[j]);
		}
	}
	else if (type == 2) {
		int pivot = mov[s]->time;
		while (true) {
			do ++i; while (mov[i]->time < pivot);
			do --j; while (mov[j]->time > pivot);
			if (i >= j) {
				return j + 1;
			}
			swap(mov[i], mov[j]);

		}
	}
	else if (type == 3) {
		double dpivot = mov[s]->rt;
		while (true) {
			do ++i; while (mov[i]->rt < dpivot);
			do --j; while (mov[j]->rt > dpivot);

			if (i >= j) {
				return j + 1;
			}
			swap(mov[i], mov[j]);
		}
	}
	else if (type == 4) {
		myDate datePivot = mov[s]->releaseDate;
		int cmp = 0;
		while (true) {
			do {
				++i;
				cmp = mov[i]->releaseDate.daysBetween(datePivot);
			} while (cmp > 0);

			do {
				--j;
				cmp = mov[j]->releaseDate.daysBetween(datePivot);
			} while (cmp < 0);

			if (i >= j) {
				return j + 1;
			}

			swap(mov[i], mov[j]);
		}
	}
	else if (type == 5) {
		string actorPivot = mov[s]->actor;
		int cmp = 0;
		while (true) {
			do {
				++i;
				cmp = mov[i]->actor.compare(actorPivot);
			} while (cmp < 0);

			do {
				--j;
				cmp = mov[j]->actor.compare(actorPivot);
			} while (cmp > 0);

			if (i >= j) {
				return j + 1;
			}

			swap(mov[i], mov[j]);

		}
	}
	return 0;
}

/**
 * Check the value of partition and make sure it doesn't have an empty partition.
 * 
 * @param mov a pointer array of movie structure.
 * @param size size of movies.
 * @param type of sorting.
 *
 */
void quicksort(Movie* mov[], int size, int type) {
	if ((size == 0) || (size == 1)) {
		return;
	}
	else {
		int mid = partition(mov, size, type);

		if (mid == size) {
			mid = mid - 1;
		}

		quicksort(mov, mid, type);
		quicksort(mov + mid, size - mid, type);
	}
}

/**
 * Retrieve running time format: 2h 16m.
 * 
 * @param time running time being formatted.
 * 
 * @return running time format: 2h 16m.
 *
 */
string getTime(int time) {
	if (time < 60) {
		return to_string(time) + "m";
	}
	int hour = time / 60;
	int remain = time % 60;

	return to_string(hour) + "h " + to_string(remain) + "m";
}

