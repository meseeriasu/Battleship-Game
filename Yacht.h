#pragma once
#include "Vapor.h"

class Yacht : public Vapor {
public:
	Yacht(int, int, int, int, int, int);
	int getMatrice(int, int);
	bool isDifferent(Vapor*);
	void incrementMatrice(int, int);
	bool getStatus();
	~Yacht();
};
