#pragma once
#include "Repository.h"
#include "VasRazboi.h"
#include "Submarine.h"
#include "DomainValidator.h"
#include "Exceptions.h"
#include "Yacht.h"

class Service {
private:
	Repository<Vapor*>* repoPlayer;
	RazboiValidator razboiValidator;
	YachtValidator yachtValidator;
	SubmarineValidator submarineValidator;
	Repository<Vapor*>* repoCalculator;
	int linii, coloane;
public:
	Service();
	Service(Repository<Vapor*>*, Repository<Vapor*>*);
	vector<Vapor*> getAll();
	vector<Vapor*> getAllCalculator();
	void setMatrice(int, int);
	int getRandom(int, int);
	int getLinii();
	int getColoane();
	bool verifyDuplicate(Repository<Vapor*>*, Vapor*);
	void addCalculatorRazboi(int);
	void addCalculatorYacht(int);
	void addCaluclatorSubmarine(int);
	void addRazboi(int, int, int, int);
	void addSubmarine(int, int, int, int);
	void addYacht(int, int, int, int);
	bool findLovitura(int, int);
	bool lovituraCalculator();
	void lovituraGolPlayer(int, int);
	void lovituraGolCalculator(int, int);
	bool winnerPlayer();
	bool winnerCalculator();
	void resetTable();
	~Service();
};
