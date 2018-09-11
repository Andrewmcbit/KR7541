#include <iostream>
#include <fstream>

#include "train.h"
#include "ticketwindow.h"

using namespace std;

train::train() {};

void train::handle(int i) {
	ifstream file("train.txt");
	if (!file.is_open())
		cout << "file not found" << endl;
	else {
		while (!file.eof()) {
			file.getline(ticketInformationFromFile, sizeof(ticketInformationFromFile), '\n');
			if (strcmp(ticketInformationFromFile, ticketInformation) == 0) {
				cout << "\na train ticket has been found\n" << endl;
				ofstream fout("tickets.txt", ios_base::app);
				fout << ticketInformationFromFile;
				fout << "\n";
				fout.close();
				break;
			}
		}
		if ((file.eof() == 1) && (strcmp(ticketInformationFromFile, ticketInformation) != 0)) {
			cout << "\ntrain ticket wasn't found." << endl;
			ticketwindow::handle(i);
		}
	}
	file.close();
}

train::~train() {}