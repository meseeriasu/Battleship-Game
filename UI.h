#pragma once
#include "Service.h"

class UI {
private:
	Service service;
public:
	UI();
	UI(Service);
	void run();
	void showMenu();
	void readTable();
	void readRazboi();
	void readYacht();
	void readSubmarine();
	void runGame();
	void printPlayer();
	void printCalculator();
	void lovitura();
	~UI();
};