#ifndef BORG_H_
# define BORG_H_

#include <iostream>
#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"
#include "Federation.hh"

namespace			Federation
{
  namespace			Starfleet
  {
    class			Captain;
    class			Ship;
    class			Ensign;
  };
  class				Ship;
};

namespace			Borg
{
  class				Ship
  {
    int				_side;
    short			_maxWarp;
    WarpSystem::Core		*core;
    Destination			_location;
    Destination			_home;
    int				_shield;
    int				_weaponFrequency;
    short			_repair;
    
  public:
    Ship(int wF, short repair = 3);
    ~Ship();
    void			setupCore(WarpSystem::Core *core);
    void			checkCore();
    bool			move(int warp, Destination d); // move _location to d
    bool			move(int warp); // move _location to _home
    bool			move(Destination d); // move _location to d
    bool			move(); // move _location to _home  
    int				getShield();
    void			setShield(int);
    int				getWeaponFrequency();
    void			setWeaponFrequency(int);
    short			getRepair();
    void			setRepair(short);
    void			fire(Federation::Starfleet::Ship*);
    void			fire(Federation::Ship*);
    void			repair();
    void			damage(int);
  };
};

#endif
