#include <iostream>
#include <fstream>

#include "train.h"
#include "ticketwindow.h"

using namespace std;

train::train() {};

void train::handle() {
	ifstream file("files\\train.txt");
	if (!file.is_open())
		cout << "file not found" << endl;
	else {
		while (!file.eof()) {
			file.getline(ticketInformationFromFile, sizeof(ticketInformationFromFile), '\n');
			if (strcmp(ticketInformationFromFile, ticketInformation) == 0) {
				cout << "\na train ticket has been found\n" << endl;
				ofstream fout("files\\tickets.txt", ios_base::app);
				if (!file.is_open())
					cout << "output file not found" << endl;
				else {
					fout << ticketInformationFromFile;
					fout << "\n";
					fout.close();
					break;
				}
			}
		}
		if ((file.eof() == 1) && (strcmp(ticketInformationFromFile, ticketInformation) != 0)) {
			cout << "\ntrain ticket wasn't found." << endl;
			ticketwindow::handle();
		}
	}
	file.close();
}

train::~train() {}