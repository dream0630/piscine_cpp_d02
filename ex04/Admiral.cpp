#include <iostream>
#include <string>
#include "Admiral.hh"
#include "Borg.hh"
#include "Federation.hh"
#include "Warpsystem.hh"
#include "Destination.hh"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
	this->_name = name;
	this->movePtr = &Federation::Starfleet::Ship::move;
	this->firePtr = &Federation::Starfleet::Ship::fire;
	std::cout << "Admiral " << name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship* sf, Borg::Ship* borg)
{
	std::cout << "On order from Admiral " << this->_name << ":"  << std::endl;
	(sf->*firePtr)(borg);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship* sf, Destination d)
{
	return ((sf->*movePtr)(d));
}
