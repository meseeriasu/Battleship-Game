#pragma once
#include "Submarine.h"
#include "VasRazboi.h"
#include "Yacht.h"
#include "Exceptions.h"


class RazboiValidator {
public:
	RazboiValidator();
	void validate(Vapor*);
	~RazboiValidator();
};

class SubmarineValidator {
public:
	SubmarineValidator();
	void validate(Vapor*);
	~SubmarineValidator();
};

class YachtValidator {
public:
	YachtValidator();
	void validate(Vapor*);
	~YachtValidator();
};