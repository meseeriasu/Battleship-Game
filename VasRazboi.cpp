#include "VasRazboi.h"

Razboi::Razboi(int m, int n, int x, int y, int k, int l) {
	this->n = n;
	this->m = m;
	for (int i = x;i <= k;i++)
		for (int j = y;j <= l;j++)
			this->matrice[i][j] = 2;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (matrice[i][j] != 2)
				matrice[i][j] = 0;
}

bool Razboi::getStatus() {
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			if (matrice[i][j] == 2)
				return false;
	return true;
}

bool Razboi::isDifferent(Vapor* p) {
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			if (this->matrice[i][j] == 2 and p->getMatrice(i, j) == 2)
				return false;
	return true;
}

void Razboi::incrementMatrice(int p, int l) {
	matrice[p][l]++;
}

int Razboi::getMatrice(int p, int l) {
	return matrice[p][l];
}

Razboi::~Razboi(){
}