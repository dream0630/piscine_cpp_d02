/*
** EPITECH PROJECT, 2018
** CPP Pool Day 07
** File description:
** QuantumReactor class implementation
*/

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true)
{
}

bool WarpSystem::QuantumReactor::isStable() const
{
	return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
	this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() const
{
	return (this->_coreReactor);
}
