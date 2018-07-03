#include <iostream>
#include "Admiral.hh"

Federation::Starfleet::Admiral::Admiral(std::string name) :
	movePtr(&Federation::Starfleet::Ship::move),
	firePtr(&Federation::Starfleet::Ship::fire),
	_name(name)
{
	std::cout << "Admiral " << name << " ready for action." << std::endl;
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship,
	Destination d)
{
	if (!ship || !this->movePtr)
		return (false);
	std::cout << "On order from Admiral " << this->_name << ":" <<
		std::endl;
	return ((ship->*(this->movePtr))(d));
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship,
	Borg::Ship *target)
{
	if (!ship || !this->firePtr)
		return;
	std::cout << "On order from Admiral " << this->_name << ":" <<
		std::endl;
	(ship->*(this->firePtr))(target);
}
