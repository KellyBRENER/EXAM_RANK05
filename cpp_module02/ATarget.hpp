#pragma once

#include "ASpell.hpp"

class	ATarget {
	protected:
	std::string	_type;
	public:
	ATarget();
	ATarget(ATarget const& src);
	ATarget(std::string type);
	ATarget &	operator=(ATarget const& src);
	virtual ~ATarget();
	std::string	getType() const;
	virtual ATarget*	clone() const = 0;
	void	getHitBySpell(ASpell const& spell) const;
};
