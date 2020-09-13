#include "DomainValidator.h"
#include <iostream>

using namespace std;

RazboiValidator::RazboiValidator() {
}

void RazboiValidator::validate(Vapor* r) {
	int op = 0;
	for (int i = 1;i <= r->getLinii();i++)
		for (int j = 1;j <= r->getColoane();j++)
			if (r->getMatrice(i, j) == 2)
				op++;
	if (op != 5)
	{
		DomainException exc("Nu ai dat coordonatele bine!");
		throw exc;
	}
}

RazboiValidator::~RazboiValidator() {
}

YachtValidator::YachtValidator() {
}

void YachtValidator::validate(Vapor* r) {
	int op = 0;
	for (int i = 1;i <= r->getLinii();i++)
		for (int j = 1;j <= r->getColoane();j++)
			if (r->getMatrice(i, j) == 2)
				op++;
	if (op != 3)
	{
		DomainException exc("Nu ai dat coordonatele bine!");
		throw exc;
	}
}

YachtValidator::~YachtValidator() {
}

SubmarineValidator::SubmarineValidator() {
}

void SubmarineValidator::validate(Vapor* r) {
	int op = 0;
	for (int i = 1;i <= r->getLinii();i++)
		for (int j = 1;j <= r->getColoane();j++)
			if (r->getMatrice(i, j) == 2)
				op++;
	if (op != 2)
	{
		DomainException exc("Nu ai dat coordonatele bine!");
		throw exc;
	}
}

SubmarineValidator::~SubmarineValidator() {
}