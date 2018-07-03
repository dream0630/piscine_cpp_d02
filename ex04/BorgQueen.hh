#ifndef BORG_QUEEN_HH_
#define BORG_QUEEN_HH_

#include <string>
#include "Borg.hh"
#include "Federation.hh"

namespace Borg {

class BorgQueen {
public:
	BorgQueen();

	bool (Borg::Ship::*movePtr)(Destination);
	void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
	void (Borg::Ship::*destroyPtr)(Federation::Ship *);

	bool move(Borg::Ship *ship, Destination d);
	void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
	void destroy(Borg::Ship *ship, Federation::Ship *target);
};

}; 

#endif
