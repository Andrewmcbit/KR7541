#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "ticketwindow.h"

using namespace std;

ticketwindow::ticketwindow() { 
	next = 0; 
}

void ticketwindow::add(ticketwindow *n) {
	if (next)
		next->add(n);
	else
		next = n;
}

void ticketwindow::setInformation() {
	cout << "Enter information for the ticket\nexample: 01 01 2000 xxx yyy 100\n";
	cout << "enter the day: ";
	cin >> ticketInformation;
	cout << "enter the month: ";
	cin >> buffer;
	strcat(ticketInformation, " ");
	strcat(ticketInformation, buffer);
	cout << "enter the year: ";
	cin >> buffer;
	strcat(ticketInformation, " ");
	strcat(ticketInformation, buffer);
	cout << "enter the place of departure: ";
	cin >> buffer;
	strcat(ticketInformation, " ");
	strcat(ticketInformation, buffer);
	cout << "enter the destination: ";
	cin >> buffer;
	strcat(ticketInformation, " ");
	strcat(ticketInformation, buffer);
	cout << "enter cost: ";
	strcat(ticketInformation, " ");
	cin >> buffer;
	strcat(ticketInformation, buffer);
}

void ticketwindow::setNext(ticketwindow *n) {
	next = n;
}

void ticketwindow::handle() {
	next->handle();
}

ticketwindow::~ticketwindow() {}