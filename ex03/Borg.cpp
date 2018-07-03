/*
** EPITECH PROJECT, 2018
** CPP Pool Day 07
** File description:
** Base and Borg Ship classes implementation
*/

#include <climits>
#include <iostream>
#include "Borg.hh"
#include "Federation.hh"

Ship::Ship(short maxWarp, Destination home) :
	_maxWarp(maxWarp), _home(home), _location(home)
{
}

bool Ship::move(int warp, Destination d)
{
	if (warp > this->_maxWarp)
		return (false);
	if (d == this->_location)
		return (false);
	if (!this->_core->checkReactor() ||
		!this->_core->checkReactor()->isStable())
		return (false);
	this->_location = d;
	return (true);
}

bool Ship::move(int warp)
{
	return (this->move(warp, this->_home));
}

bool Ship::move(Destination d)
{
	return (this->move(SHRT_MIN, d));
}

bool Ship::move()
{
	return (this->move(SHRT_MIN, this->_home));
}

void Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
}

Borg::Ship::Ship(int weaponFrequency, short repair) :
	::Ship(9, UNICOMPLEX), _side(300), _shield(100),
	_weaponFrequency(weaponFrequency), _repair(repair)
{
	std::cout << "We are the Borgs. Lower your shields and surrender "
		"yourselves unconditionally." << std::endl;
	std::cout << "Your biological characteristics and technologies will be "
		"assimilated." << std::endl;
	std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weaponFrequency) : Ship(weaponFrequency, 3)
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
	::Ship::setupCore(core);
}

void Borg::Ship::checkCore() const
{
	if (!this->_core || !this->_core->checkReactor())
		return;
	if (this->_core->checkReactor()->isStable())
		std::cout << "Everything is in order." << std::endl;
	else
		std::cout << "Critical failure imminent." << std::endl;
}

int Borg::Ship::getShield() const
{
	return (this->_shield);
}

int Borg::Ship::getWeaponFrequency() const
{
	return (this->_weaponFrequency);
}

short Borg::Ship::getRepair() const
{
	return (this->_repair);
}

void Borg::Ship::setShield(int shield)
{
	this->_shield = shield;
}

void Borg::Ship::setWeaponFrequency(int weaponFrequency)
{
	this->_weaponFrequency = weaponFrequency;
}

void Borg::Ship::setRepair(short repair)
{
	this->_repair = repair;
}

void Borg::Ship::fire()
{
	std::cout << "Firing on target with " << this->_weaponFrequency <<
		"GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
	if (!target)
		return;
	this->fire();
	target->setShield(target->getShield() - this->_weaponFrequency);
}

void Borg::Ship::fire(Federation::Ship *target)
{
	if (!target || !target->getCore() || !target->getCore()->checkReactor())
		return;
	this->fire();
	target->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair()
{
	if (this->_repair > 0) {
		this->_repair--;
		this->_shield = 100;
		std::cout << "Begin shield re-initialisation... Done. "
			"Awaiting further instructions." << std::endl;
	}
	else {
		std::cout << "Energy cells depleted, shield weakening." <<
			std::endl;
	}
}
