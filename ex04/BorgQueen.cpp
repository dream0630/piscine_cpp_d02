#include <iostream>
#include <string>
#include "BorgQueen.hh"
#include "Borg.hh"
#include "Federation.hh"
#include "Warpsystem.hh"
#include "Destination.hh"

Borg::BorgQueen::BorgQueen()
{
	this->movePtr = &Borg::Ship::move;
	this->firePtr = &Borg::Ship::fire;
	this->destroyPtr = &Borg::Ship::fire;
}

Borg::BorgQueen::~BorgQueen()
{
}

bool Borg::BorgQueen::move(Borg::Ship* borg, Destination d)
{
	return ((borg->*movePtr)(d));
}

void Borg::BorgQueen::fire(Borg::Ship* borg, Federation::Starfleet::Ship* sf)
{
	(borg->*firePtr)(sf);
}

void Borg::BorgQueen::destroy(Borg::Ship* borg, Federation::Ship* s)
{
	(borg->*destroyPtr)(s);
}
