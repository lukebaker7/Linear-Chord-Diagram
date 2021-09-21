#include <iostream>
#include <cmath>

using namespace std;

int ShortChordNum(int endpoints, int amtSmall);

double fact(int x) {
    if ( x == 0) {
        return 1;
    } else {
        return x * fact(x-1);
    }
}

int biNom(int top, int bott) {
	int top1 = fact(top);
	int bott1 = fact(bott);
	int both = fact(top - bott);
	bott1 = bott1 * both;
	return top1 / bott1;
}

int counting(int v, int w) {
	double a = fact((2*v) - w);
    double b = 1/(pow(2, (v-w)));
	double c =  double(fact(w));
	c = 1/c;
	double d = double(fact(v-w));
	d = 1/d;
	return a*b*c*d;
}


int RecursiveShortSum(int endpoints, int shorts, int shortStay) {
	if (shorts == endpoints) {
		return 0;
	} else {
		return ((ShortChordNum(endpoints, shorts + 1) * biNom(shorts + 1, shortStay)) + 
				(RecursiveShortSum(endpoints, shorts + 1, shortStay)));
	}
}

int ShortChordNum(int endpoints, int amtSmall) {
	//int secondcase = counting(endpoints, endpoints - 1) - biNom(endpoints, endpoints - 1);
	if (amtSmall == endpoints) {
		return 1;
	} else {
		//counting(endpoints, amtSmall)
		return counting(endpoints, amtSmall) - 	RecursiveShortSum(endpoints, amtSmall, amtSmall);
	}
}

void DisplayShortChord(int endpoints) {
	for(int i = 0; i < endpoints; i++) {
		cout << ShortChordNum(endpoints, i) << ", ";
	}
	cout << ShortChordNum(endpoints, endpoints) << endl;
}


int main() {
	int input;
	char ans = 'Y';
	cout << "This program will display the amount of " << 
	"linear short chord diagrams with 0-n amount of length one chords"
	<< endl;
	cout << "What amount of endpoints would you like information for?" << endl;
	while(ans == 'Y' || ans == 'y') {
		cin >> input;
		DisplayShortChord(input);
		cout << "Would you like to look at more? ('Y'/'N')" << endl;
		cin >> ans;
	}
	return 0;
}
