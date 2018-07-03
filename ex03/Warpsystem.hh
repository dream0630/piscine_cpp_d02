/*
** EPITECH PROJECT, 2018
** CPP Pool Day 07
** File description:
** WarpSystem namespace and QuantumReactor class definition
*/

#if !defined(WARP_SYSTEM_HPP_)
	#define WARP_SYSTEM_HPP_

namespace WarpSystem {

class QuantumReactor {
public:
	QuantumReactor();

	bool isStable() const;
	void setStability(bool stability);

private:
	bool _stability;
};

class Core {
public:
	Core(QuantumReactor *coreReactor);

	QuantumReactor *checkReactor() const;

private:
	QuantumReactor *_coreReactor;
};

}; /* namespace WarpSystem */

#endif /* !defined(WARP_SYSTEM_HPP_) */
