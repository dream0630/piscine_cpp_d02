#include <iostream>
#include "BorgQueen.hh"

Borg::BorgQueen::BorgQueen() :
	movePtr(&Borg::Ship::move),
	firePtr(&Borg::Ship::fire),
	destroyPtr(&Borg::Ship::fire)
{
}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination d)
{
	if (!ship || !this->movePtr)
		return (false);
	return ((ship->*(this->movePtr))(d));
}

void Borg::BorgQueen::fire(Borg::Ship *ship,
	Federation::Starfleet::Ship *target)
{
	if (!ship || !this->firePtr)
		return;
	(ship->*(this->firePtr))(target);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
	if (!ship || !this->destroyPtr)
		return;
	(ship->*(this->destroyPtr))(target);
}
