#ifndef ADMIRAL_HH_
#define ADMIRAL_HH_

#include <string>
#include "Federation.hh"
#include "Borg.hh"

namespace Federation {
namespace Starfleet {

class Admiral {
public:
	Admiral(std::string name);

	bool (Federation::Starfleet::Ship::*movePtr)(Destination);
	void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *);

	bool move(Federation::Starfleet::Ship *ship, Destination d);
	void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);

private:
	std::string _name;
};

}; 
}; 

#endif
