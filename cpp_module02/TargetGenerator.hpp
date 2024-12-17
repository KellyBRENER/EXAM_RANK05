#pragma once

#include "ATarget.hpp"
#include <map>

class	TargetGenerator {
	private :
	std::map<std::string, ATarget*>	_TargetGenerator;
	TargetGenerator(TargetGenerator const& src);
	TargetGenerator &	operator=(TargetGenerator const& src);
	public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const & type);
	ATarget* createTarget(std::string const & type);
};
