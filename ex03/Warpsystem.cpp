#include <iostream>
#include <string>
#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{

}

bool			WarpSystem::QuantumReactor::isStable()
{
  return (this->_stability);
}

void			WarpSystem::QuantumReactor::setStability(bool status)
{
  this->_stability = status;
}

WarpSystem::Core::Core(QuantumReactor *core)
{
  this->_coreReactor = core;
}

WarpSystem::Core::~Core()
{

}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
  return (this->_coreReactor);
}
