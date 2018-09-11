#ifndef TICKETWINDOW_H
#define TICKETWINDOW_H

extern char ticketInformation[100];

class ticketwindow {
	ticketwindow *next;
private:
	char buffer[20];
public:
	ticketwindow();
	void add(ticketwindow *n);
	void setInformation();
	void setNext(ticketwindow *n);
	virtual void handle(int i);
	~ticketwindow();
};

#endif TICKETWINDOW_H