#ifndef FEDERATION_H_
# define FEDERATION_H_

#include <iostream>
#include <string>
#include "Warpsystem.hh"

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

    public:
      Ship(int length, int width, std::string name, short maxWarp);
      ~Ship();
      void			setupCore(WarpSystem::Core *core);
      void			checkCore();
      void			promote(Captain *cap);
    };

    class			Ensign
    {
      std::string		_name;

    public:
      explicit Ensign(std::string name);
      ~Ensign();
    };
  };

  class			Ship
  {
    int			_length;
    int			_width;
    std::string		_name;
    WarpSystem::Core	*core;

  public:
    Ship(int length, int width, std::string name);
    ~Ship();
    void		setupCore(WarpSystem::Core *core);
    void		checkCore();
  };
};

#endif
