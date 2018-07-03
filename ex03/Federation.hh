#ifndef FEDERATION_H_
# define FEDERATION_H_

#include <iostream>
#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"
#include "Borg.hh"

namespace Borg
{
  class Ship;
}

namespace			Federation
{
  namespace			Starfleet
  {
    class			Captain
    {
      int			_age;
      std::string		_name;

    public:
      Captain(std::string name);
      ~Captain();
      std::string		getName();
      int			getAge();
      void			setAge(int);
    };

    class			Ship
    {
      int			_length;
      int			_width;
      std::string		_name;
      short			_maxWarp;
      WarpSystem::Core		*core;
      Captain			*cap;
      Destination      		_location;
      Destination		_home;
      int			_shield;
      int			_photonTorpedo;

    public:
      Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 20);
      ~Ship();
      void			setupCore(WarpSystem::Core *core);
      void			checkCore();
      void			promote(Captain *cap);
      bool			move(int warp, Destination d); // move _location to d
      bool			move(int warp); // move _location to _home
      bool			move(Destination d); // move _location to d
      bool			move(); // move _location to _home
      int			getShield();
      void			setShield(int);
      int			getTorpedo();
      void			setTorpedo(int);
      void			fire(Borg::Ship*);
      void			fire(int torpedoes, Borg::Ship*);
      void			damage(int);
    };

    class			Ensign
    {
      std::string		_name;

    public:
      explicit Ensign(std::string name);
      ~Ensign();
    };
  };

  class				Ship
  {
    int				_length;
    int				_width;
    std::string			_name;
    WarpSystem::Core		*core;
    Destination			_location;
    Destination			_home;

  public:
    Ship(int length, int width, std::string name);
    ~Ship();
    void			setupCore(WarpSystem::Core *core);
    void			checkCore();
    bool			move(int warp, Destination d); 
    bool			move(int warp); 
    bool			move(Destination d); 
    bool			move(); 
    WarpSystem::Core*		getCore();
    void			damage(int);
  };
};

#endif
