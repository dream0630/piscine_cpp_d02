#ifndef BORGQUEEN_H_
#define BORGQUEEN_H_

#include <iostream>
#include <string>

namespace Borg
{
	class BorgQueen;
}

#include "Borg.hh"
#include "Federation.hh"
#include "Warpsystem.hh"

namespace Borg
{
	class BorgQueen
	{
		public:
		BorgQueen();
		~BorgQueen();
		bool		(Borg::Ship::*movePtr)(Destination);
		void		(Borg::Ship::*firePtr)(Federation::Starfleet::Ship*);
		void		(Borg::Ship::*destroyPtr)(Federation::Ship*);
		bool		move(Borg::Ship*, Destination);
		void		fire(Borg::Ship*, Federation::Starfleet::Ship*);
		void		destroy(Borg::Ship*, Federation::Ship*);
	};
}

#endif
