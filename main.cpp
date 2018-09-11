#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include "ticketwindow.h"
#include "train.h"
#include "plane.h"

using namespace std;

char ticketInformation[100];

int main() {
	train first;
	plane second;
	first.add(&second);
	second.setNext(&first);
	
	int button = 1;
	while (button) {
		cout << "|1| - buy a ticket\n";
		cout << "|2| - clear outfile\n";
		cout << "|0| - exit\n";
		cin >> button;
		switch (button) {
			case 1: {
				first.setInformation();
				first.handle(1);
				break;
			}
			case 2: {ofstream file("tickets.txt", ios_base::trunc); file.close(); break; }
			case 0: break;
			}
	}
	return 0;
}
