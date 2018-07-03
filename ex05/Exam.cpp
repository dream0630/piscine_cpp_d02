#include <iostream>
#include "Exam.hh"

bool Exam::cheat = false;

Exam::Exam(bool *cheat_ptr)
{
	this->_cheat_ptr = cheat_ptr;
}

void Exam::start(int klingons) const
{
	std::cout << "[The exam is starting]" << std::endl;
	std::cout << klingons << " Klingon vessels appeared out of nowhere." <<
		std::endl;
	std::cout << "they are fully armed and shielded" << std::endl;
	if (!this->isCheating())
		std::cout << "This exam is hard... you lost again." << std::endl;
	else
		std::cout << "What the... someone changed the parameters of the"
			" exam !" << std::endl;
}

bool Exam::isCheating() const
{
	return (this->_cheat_ptr ? *this->_cheat_ptr : false);
}
