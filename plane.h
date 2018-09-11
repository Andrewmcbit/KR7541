#define _CRT_SECURE_NO_WARNINGS
#ifndef PLANE_H
#define PLANE_H

#include "ticketwindow.h"

class plane : public ticketwindow {
private:
	char ticketInformationFromFile[100];
public:
	plane();
	virtual void handle();
	~plane();
};

#endif PLANE_H