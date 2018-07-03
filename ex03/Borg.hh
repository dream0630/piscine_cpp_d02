/*
** EPITECH PROJECT, 2018
** CPP Pool Day 07
** File description:
** Borg namespace and Base and Borg Ship classes definition
*/

#if !defined (BORG_HPP_)
	#define BORG_HPP_
	#include "Warpsystem.hh"
	#include "Destination.hh"

class Ship {
public:
	void setupCore(WarpSystem::Core *core);
	virtual void checkCore() const = 0;

	bool move(int warp, Destination d);
	bool move(int warp);
	bool move(Destination d);
	bool move();

protected:
	Ship(short maxWarp, Destination home);

	short _maxWarp;
	WarpSystem::Core *_core;
	Destination _home;
	Destination _location;
};

namespace Federation {
class Ship;
namespace Starfleet {
class Ship;
}
};

namespace Borg {

class Ship : public ::Ship {
public:
	Ship(int weaponFrequency, short repair);
	Ship(int weaponFrequency);

	void setupCore(WarpSystem::Core *core);
	void checkCore() const;

	int getShield() const;
	int getWeaponFrequency() const;
	short getRepair() const;
	void setShield(int shield);
	void setWeaponFrequency(int weaponFrequency);
	void setRepair(short repair);

	void fire(Federation::Starfleet::Ship *target);
	void fire(Federation::Ship *target);

	void repair();

private:
	void fire();

	int _side;
	int _shield;
	int _weaponFrequency;
	short _repair;
};

}; /* namespace Borg */

#endif /* !defined (BORG_HPP_) */
