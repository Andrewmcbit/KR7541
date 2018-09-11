#define _CRT_SECURE_NO_WARNINGS
#ifndef TRAIN_H
#define TRAIN_H

#include "ticketwindow.h"

class train : public ticketwindow {
private:
	char ticketInformationFromFile[100];
public:
	train();
	virtual void handle();
	~train();
};

#endif TRAIN_H