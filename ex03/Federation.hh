#ifndef (FEDERATION_HPP_)
# define FEDERATION_HPP_

#include <iostream>
#include "Borg.hh"

namespace Federation {

class Ship : public ::Ship {
public:
	Ship(int length, int width, std::string name);

	void setupCore(WarpSystem::Core *core);
	void checkCore() const;
	WarpSystem::Core *getCore() const;

protected:
	Ship(int length, int width, std::string name, short maxWarp,
		Destination home);

	std::string _name;

private:
	int _length;
	int _width;
};

namespace Starfleet {

class Captain {
public:
	Captain(std::string name);

	std::string getName() const;
	int getAge() const;
	void setAge(int age);

private:
	std::string _name;
	int _age;
};

class Ship : public Federation::Ship {
public:
	Ship();
	Ship(int length, int width,
		std::string name, short maxWarp, int torpedo);

	void setupCore(WarpSystem::Core *core);
	void checkCore() const;

	void promote(Captain *captain);

	int getShield() const;
	int getTorpedo() const;
	void setShield(int shield);
	void setTorpedo(int torpedo);

	void fire(int torpedoes, Borg::Ship *target);
	void fire(Borg::Ship *target);

private:
	Captain *_captain;
	int _shield;
	int _photonTorpedo;
};

class Ensign {
public:
	explicit Ensign(std::string name);

private:
	std::string _name;
};

}; /* namespace Starfleet */

}; /* namespace Federation */

#endif /* !defined (FEDERATION_HPP_) */
