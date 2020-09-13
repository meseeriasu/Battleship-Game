#pragma once

class Vapor {
protected:
	int n, m;
	int matrice[32][32];
public:
	virtual bool getStatus();
	virtual bool isDifferent(Vapor*);
	virtual int getMatrice(int, int);
	int getLinii();
	int getColoane();
	virtual void incrementMatrice(int, int);
	virtual ~Vapor();
};