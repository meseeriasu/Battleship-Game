#pragma once
#include "Vapor.h"

class Razboi : public Vapor {
public:
	Razboi(int, int, int, int, int, int);
	bool isDifferent(Vapor*);
	int getMatrice(int, int);
	void incrementMatrice(int, int);
	bool getStatus();
	~Razboi();
};
