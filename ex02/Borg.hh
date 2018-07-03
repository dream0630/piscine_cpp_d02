#ifndef BORG_H_
# define BORG_H_

#include <iostream>
#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"

namespace			Borg
{
  class				Ship
  {
    int				_side;
    short			_maxWarp;
    WarpSystem::Core		*core;
    Destination			_location;
    Destination			_home;
    
  public:
    Ship();
    ~Ship();
    void			setupCore(WarpSystem::Core *core);
    void			checkCore();
    bool			move(int warp, Destination d); 
    bool			move(int warp); 
    bool			move(Destination d); 
    bool			move(); 
  };
};

#endif
