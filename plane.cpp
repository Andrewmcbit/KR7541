#include <iostream>
#include <fstream>

#include "plane.h"
#include "ticketwindow.h"

using namespace std;

plane::plane() {};

void plane::handle() {
	ifstream file("files\\plane.txt");
	if (!file.is_open())
		cout << "file not found" << endl;
	else {
		while (!file.eof()) {
			file.getline(ticketInformationFromFile, sizeof(ticketInformationFromFile), '\n');
			if (strcmp(ticketInformationFromFile, ticketInformation) == 0) {
				cout << "plane ticket has been found\n" << endl;
				ofstream fout("files\\tickets.txt", ios_base::app);
				fout << ticketInformationFromFile;
				fout << "\n";
				fout.close();
				break;
			}
		}
		if ((file.eof() == 1) && (strcmp(ticketInformationFromFile, ticketInformation) != 0)) {
			cout << "plane ticket wasn't found.\n" << endl;
		}
	}
	file.close();
}

plane::~plane() {}