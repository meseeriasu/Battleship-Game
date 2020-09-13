#include "UI.h"
#include <iostream>

using namespace std;

UI::UI() {
}

UI::UI(Service ser) {
	service = ser;
}

void UI::readTable() {
	int m, n;
	cout << "Dati m si n: ";	cin >> m;	cin >> n;
	service.setMatrice(m, n);
}

void UI::readRazboi() {
	try {
		int k;
		cout << " Nr. vase de razboi: "; cin >> k;
		for (int i = 1;i <= k;i++)
		{
			int k, l, z, x;
			cout << "Vasul de razboi " << i << ": ";	cin >> k >> l >> z >> x;
			service.addRazboi(k, l, z, x);
		}
		service.addCalculatorRazboi(k);
	}
	catch (RepositoryException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		readRazboi();
	}
	catch (DomainException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		readRazboi();
	}
	catch (...) {
		cout << "other exception: " << endl;
		readRazboi();
	}
}

void UI::readYacht() {
	try {
		int p;
		cout << "Nr. yacht-uri: ";	cin >> p;
		for (int i = 1;i <= p;i++)
		{
			int k, l, z, x;
			cout << "Yacht-ul " << i << ": ";	cin >> k >> l >> z >> x;
			service.addYacht(k, l, z, x);
		}
		service.addCalculatorYacht(p);
	}
	catch (RepositoryException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		readYacht();
	}
	catch (DomainException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		readYacht();
	}
	catch (...) {
		cout << "other exception: " << endl;
		readYacht();
	}
}

void UI::readSubmarine() {
	try {
		int q;
		cout << "Nr. submarine: ";	cin >> q;
		for (int i = 1;i <= q;i++)
		{
			int k, l, z, x;
			cout << "Submarinul " << i << ": ";	cin >> k >> l >> z >> x;
			service.addSubmarine(k, l, z, x);
		}
		service.addCaluclatorSubmarine(q);
	}
	catch (RepositoryException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		readSubmarine();
	}
	catch (DomainException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		readSubmarine();
	}
	catch (...) {
		cout << "other exception: " << endl;
		readSubmarine();
	}
}

void UI::printPlayer() {
	cout << "Tabla dumneavoastra: " << endl;
	for (int j = 1;j <= service.getLinii();j++)
	{
		for (int k = 1;k <= service.getColoane();k++)
		{
			bool ok = true;
			for (int i = 0;i < service.getAll().size();i++)
				if (service.getAll()[i]->getMatrice(j, k) == 2)
				{
					cout << "| # ";
					ok = false;
					break;
				}
				else
					if (service.getAll()[i]->getMatrice(j, k) == 3)
					{
						ok = false;
						cout << "| X ";
					}
			if (ok and service.getAll()[1]->getMatrice(j, k) == 1)
				cout << "| * ";
			if (ok and service.getAll()[1]->getMatrice(j, k) == 0)
				cout << "| O ";
				
		}
		cout << "|" << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}

void UI::printCalculator() {
	cout << "Tabla calculator: " << endl;
	for (int j = 1;j <= service.getLinii();j++)
	{
		for (int k = 1;k <= service.getColoane();k++)
		{
			bool ok = true;
			for (int i = 0;i < service.getAllCalculator().size();i++)
				if (service.getAllCalculator()[i]->getMatrice(j, k) == 3)
				{
					cout << "| X ";
					ok = false;
					break;
				}
				else
					if (service.getAllCalculator()[i]->getMatrice(j, k) == 2)
					{
						cout << "| O ";
						ok = false;
					}
			if (ok and service.getAllCalculator()[1]->getMatrice(j,k)==0)
				cout << "| O ";
			if (ok and service.getAllCalculator()[1]->getMatrice(j, k) == 1)
				cout << "| * ";

		}
		cout << "|" << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}

void UI::showMenu() {
	cout << "1. Start game" << endl;
	cout << "2. Quit" << endl;
}

void UI::lovitura() {
	try {
		int x, y;
		cout << "Dati coordonatele loviturii: ";	cin >> x >> y;
		if (service.findLovitura(x, y))
			cout << "Ai atins!" << endl;
		else
			cout << "Nu ai nimerit" << endl;
		if (service.lovituraCalculator())
			cout << "Calculatorul te-a lovit!" << endl;
		else
			cout << "Calculatorul a dat in aer!" << endl;
	}
	catch (LovituraException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		lovitura();
	}
	catch (...) {
		cout << "other exception: " << endl;
		readSubmarine();
	}
}

void UI::runGame() {
	while (!service.winnerCalculator() and !service.winnerPlayer())
	{
		lovitura();
		printPlayer();
		printCalculator();
	}
	if (service.winnerCalculator())
		cout << "Ai castigat!" << endl;
	else
		cout << "Calculatorul a castigat!" << endl;
}

void UI::run() {
	bool gata = true;
	while (gata)
	{
		int opt;
		showMenu();
		cout << "Optiunea: ";	cin >> opt;	cout << endl;
		switch (opt)
		{
		case 1: {
			service.resetTable();
			readTable();
			readRazboi();
			readYacht();
			readSubmarine();
			printPlayer();
			runGame();
			break;
		}
		case 2: {gata = false;break;}
		}
	}
}

UI::~UI() {
}