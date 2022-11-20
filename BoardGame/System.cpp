#include "Cell.h"
#include "Card.h"
#include <string>
#include "System.h"


void BoardSystem::Initialize(string str, int plNumber) {
	playerNumber = plNumber;
	map.Initailize(str);
}