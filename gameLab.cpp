#include <iostream>
#include "Vapor.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"

using namespace std;

int main()
{
	Repository<Vapor*>* player, *calculator;
	player = new Repository<Vapor*>;
	calculator = new Repository<Vapor*>;
	Service service(player, calculator);
	UI ui(service);
	ui.run();
}
