#include "Service.h"
#include <iostream>
#include <time.h>

using namespace std;

Service::Service() {
	linii = 0;
	coloane = 0;
}

Service::Service(Repository<Vapor*>* player, Repository<Vapor*>* calculator) {
	srand(time(0));
	repoPlayer = player;
	repoCalculator = calculator;
	linii = 0;
	coloane = 0;
}

int Service::getLinii() {
	return linii;
}

int Service::getColoane() {
	return coloane;
}

void Service::setMatrice(int m, int n) {
	linii = m;
	coloane = n;
}

int Service::getRandom(int lower, int upper) {
	return (rand() % (upper - lower + 1)) + lower;
}

bool Service::verifyDuplicate(Repository<Vapor*>* repo, Vapor* vap) {
	for (int i = 0;i < repo->getAll().size();i++)
		if (!repo->getAll()[i]->isDifferent(vap))
			return false;
	return true;
}

void Service::addCalculatorRazboi(int k) {
	for (int i = 1;i <= k;i++)
	{
		bool ok = true;
		while (ok)
		{
			int k = getRandom(1, linii), l = getRandom(1, coloane), o = getRandom(1,4);
			if (o == 1)
				if(k-4>=1)
				{
					Vapor* vap = new Razboi(linii, coloane, k - 4, l, k, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if(o==2)
				if (l + 4 <= coloane)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l, k, l + 4);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if(o==3)
				if (k + 4 <= linii)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l, k + 4, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if(o==4)
				if (l - 4 >= 1)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l-4, k, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
		}
	}
}

void Service::addCalculatorYacht(int k) {
	for (int i = 1;i <= k;i++)
	{
		bool ok = true;
		while (ok)
		{
			int k = getRandom(1, linii), l = getRandom(1, coloane), o = getRandom(1, 4);
			if (o == 1)
				if (k - 2 >= 1)
				{
					Vapor* vap = new Razboi(linii, coloane, k - 2, l, k, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if (o == 2)
				if (l + 2 <= coloane)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l, k, l + 2);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if (o == 3)
				if (k + 2 <= linii)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l, k + 2, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if (o == 4)
				if (l - 2 >= 1)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l - 2, k, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
		}
	}
}

void Service::addCaluclatorSubmarine(int k) {
	for (int i = 1;i <= k;i++)
	{
		bool ok = true;
		while (ok)
		{
			int k = getRandom(1, linii), l = getRandom(1, coloane), o = getRandom(1, 4);
			if (o == 1)
				if (k - 1 >= 1)
				{
					Vapor* vap = new Razboi(linii, coloane, k - 1, l, k, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if (o == 2)
				if (l + 1 <= coloane)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l, k, l + 1);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if (o == 3)
				if (k + 1 <= linii)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l, k + 1, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
			if (o == 4)
				if (l - 1 >= 1)
				{
					Vapor* vap = new Razboi(linii, coloane, k, l - 1, k, l);
					if (verifyDuplicate(repoCalculator, vap))
					{
						repoCalculator->add(vap);
						ok = false;
					}
				}
		}
	}
}

vector<Vapor*> Service::getAll() {
	return repoPlayer->getAll();
}

vector<Vapor*> Service::getAllCalculator() {
	return repoCalculator->getAll();
}

void Service::addRazboi(int k, int l, int z, int x) {
	Vapor* vap = new Razboi(linii, coloane, k, l, z, x);
	if (verifyDuplicate(repoPlayer, vap))
	{
		razboiValidator.validate(vap);
		repoPlayer->add(vap);
	}
	else
	{
		RepositoryException exc("Vaporul acesta se intersecteaza cu altul!");
		throw exc;
	}
}

void Service::addSubmarine(int k, int l, int z, int x) {
	Vapor* vap = new Submarine(linii, coloane, k, l, z, x);
	if (verifyDuplicate(repoPlayer, vap))
	{
		submarineValidator.validate(vap);
		repoPlayer->add(vap);
	}
	else
	{
		RepositoryException exc("Vaporul acesta se intersecteaza cu altul!");
		throw exc;
	}
}

void Service::addYacht(int k, int l, int z, int x) {
	Vapor* vap = new Yacht(linii, coloane, k, l, z, x);
	if (verifyDuplicate(repoPlayer, vap))
	{
		yachtValidator.validate(vap);
		repoPlayer->add(vap);
	}
	else
	{
		RepositoryException exc("Vaporul acesta se intersecteaza cu altul!");
		throw exc;
	}
}

bool Service::findLovitura(int x, int y) {
	for (int i = 0;i < getAllCalculator().size();i++)
		if (getAllCalculator()[i]->getMatrice(x, y) == 3)
			throw LovituraException("Ai lovit deja in locul acesta!");
	if (getAllCalculator()[0]->getMatrice(x, y) == 1)
		throw LovituraException("Ai lovit deja in locul acesta!");
	if (x > getLinii() or x<1 or y>getColoane() or y < 1)
		throw LovituraException("Ai dat coordonatele gresite!");
	for (int i = 0;i < getAllCalculator().size();i++)
		if (getAllCalculator()[i]->getMatrice(x, y) == 2)
		{
			getAllCalculator()[i]->incrementMatrice(x, y);
			return true;
		}
	lovituraGolCalculator(x, y);
	return false;
}

bool Service::lovituraCalculator() {
	int x, y, p=0;
	while (true)
	{
		p = 0;
		x = getRandom(1, linii);
		y = getRandom(1, coloane);
		for (int i = 0;i < getAll().size();i++)
			if (getAll()[i]->getMatrice(x, y) == 2)
			{
				getAll()[i]->incrementMatrice(x, y);
				return true;
			}
			else
				if(getAll()[i]->getMatrice(x,y)==0)
					p++;
		if (p == getAll().size())
			break;
	}
	lovituraGolPlayer(x, y);
	return false;
}

void Service::lovituraGolPlayer(int x, int y) {
	for (int i = 0;i < getAll().size();i++)
		getAll()[i]->incrementMatrice(x, y);
}

void Service::lovituraGolCalculator(int x, int y) {
	for (int i = 0;i < getAllCalculator().size();i++)
		getAllCalculator()[i]->incrementMatrice(x, y);
}

bool Service::winnerPlayer() {
	for (int i = 0;i < repoPlayer->getAll().size();i++)
		if (!repoPlayer->getAll()[i]->getStatus())
			return false;
	return true;
}

bool Service::winnerCalculator() {
	for (int i = 0;i < repoCalculator->getAll().size();i++)
		if (!repoCalculator->getAll()[i]->getStatus())
			return false;
	return true;
}

void Service::resetTable() {
	while (getAll().size())
	{
		repoPlayer->remove(repoPlayer->getAll()[0]);
		repoCalculator->remove(repoCalculator->getAll()[0]);
	}
}

Service::~Service() {
}