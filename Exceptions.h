#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class RepositoryException {
protected:
	const char* message;
public:
	RepositoryException(const char* msg) : message(msg) {
	}
	const char* getMessage() {
		return message;
	}
};

class DomainException {
protected:
	const char* message;
public:
	DomainException(const char* msg) : message(msg) {
	}
	const char* getMessage() {
		return message;
	}
};

class LovituraException {
protected:
	const char* message;
public:
	LovituraException(const char* msg) : message(msg) {
	}
	const char* getMessage() {
		return message;
	}
};