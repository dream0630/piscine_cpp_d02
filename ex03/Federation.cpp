/*
** EPITECH PROJECT, 2018
** CPP Pool Day 07
** File description:
** Federation and Starfleet Ship classes implementation
*/

#include <iostream>
#include "Federation.hh"

Federation::Ship::Ship(int length, int width,
	std::string name, short maxWarp, Destination home) :
	::Ship(maxWarp, home), _name(name), _length(length), _width(width)
{
}

Federation::Ship::Ship(int length, int width, std::string name) :
	Federation::Ship(length, width, name, 1, VULCAN)
{
	std::cout << "The independant ship " << name << " just finished its "
		"construction. It is " << length << " m in length and " <<
		width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
	::Ship::setupCore(core);
	std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() const
{
	if (!this->_core || !this->_core->checkReactor())
		return;
	bool stability = this->_core->checkReactor()->isStable();
	std::cout << this->_name << ": The core is " <<
		(stability ? "stable" : "unstable") << " at the time." <<
		std::endl;
}

WarpSystem::Core *Federation::Ship::getCore() const
{
	return (this->_core);
}

Federation::Starfleet::Ship::Ship(
	int length, int width, std::string name, short maxWarp, int torpedo) :
	Federation::Ship(length, width, name, maxWarp, EARTH),
	_shield(100), _photonTorpedo(torpedo)
{
	std::cout << "The ship USS " << name << " has been finished. It is " <<
		length << " m in length and " << width << " m in width. "
		"It can go to Warp " << maxWarp << "! Weapons are set: " <<
		torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship() :
	Federation::Starfleet::Ship::Ship(289, 132, "Entreprise", 6, 20)
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
	::Ship::setupCore(core);
	std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() const
{
	if (!this->_core || !this->_core->checkReactor())
		return;
	bool stability = this->_core->checkReactor()->isStable();
	std::cout << "USS " << this->_name << ": The core is " <<
		(stability ? "stable" : "unstable") << " at the time." <<
		std::endl;
}

void Federation::Starfleet::Ship::promote(
	Federation::Starfleet::Captain *captain)
{
	this->_captain = captain;
	if (!captain)
		return;
	std::cout << captain->getName() << ": I'm glad to be the captain of "
		"the USS " << this->_name << "." << std::endl;
}

int Federation::Starfleet::Ship::getShield() const
{
	return (this->_shield);
}

int Federation::Starfleet::Ship::getTorpedo() const
{
	return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
	this->_shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
	this->_photonTorpedo = torpedo;
}

void	Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship* borg)
{
  if (this->getTorpedo() - torpedoes >= 0)
    {
      this->setTorpedo(this->getTorpedo() - torpedoes);
      std::cout << this->_name << ": Firing on target. " << this->getTorpedo() << " torpedoes remaining." << std::endl;
      borg->setShield(borg->getShield() - (torpedoes * 50));
    }
  else if (this->getTorpedo() == 0)
    std:: cout << this->_name << ": No more torpedo to fire, " << (this->_captain)->getName() << "!" << std::endl;
  else if (this->getTorpedo() - torpedoes < 0)
    std::cout << this->_name << ": No enough torpedoes to fire, " << (this->_captain)->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
	this->fire(1, target);
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0)
{
}

std::string Federation::Starfleet::Captain::getName() const
{
	return (this->_name);
}

int Federation::Starfleet::Captain::getAge() const
{
	return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
	this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
	std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}
