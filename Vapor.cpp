#include "Vapor.h"

bool Vapor::getStatus() {
	return false;
}

int Vapor::getMatrice(int p, int l) {
	return matrice[p][l];
}

bool Vapor::isDifferent(Vapor* p) {
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			if (this->matrice[i][j] == 2 and p->getMatrice(i, j) == 2)
				return false;
	return true;
}

int Vapor::getLinii() {
	return m;
}

int Vapor::getColoane() {
	return n;
}

void Vapor::incrementMatrice(int p, int l) {
	matrice[p][l]++;
}

Vapor::~Vapor() {
}