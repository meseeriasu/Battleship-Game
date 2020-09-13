#pragma once
#include "Vapor.h"

class Submarine : public Vapor {
public:
	Submarine(int, int, int, int, int, int);
	int getMatrice(int, int);
	bool isDifferent(Vapor*);
	void incrementMatrice(int, int);
	bool getStatus();
	~Submarine();
};