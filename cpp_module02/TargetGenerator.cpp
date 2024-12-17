#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::TargetGenerator(TargetGenerator const& src) {*this = src;}
TargetGenerator &	TargetGenerator::operator=(TargetGenerator const& src) {
	if (this != &src) {
		_TargetGenerator = src._TargetGenerator;
	}
	return *this;
}
TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget*>::iterator	it = _TargetGenerator.begin();
	for (; it != _TargetGenerator.end(); ++it) {
		delete it->second;
	}
	_TargetGenerator.clear();
}

void	TargetGenerator::learnTargetType(ATarget* target) {
	if (target) {
		if (_TargetGenerator.find(target->getType()) == _TargetGenerator.end())
			_TargetGenerator[target->getType()] = target->clone();
	}
}
void	TargetGenerator::forgetTargetType(std::string const& type) {
	std::map<std::string, ATarget*>::iterator	it = _TargetGenerator.find(type);
	if (it != _TargetGenerator.end()) {
		delete it->second;
		_TargetGenerator.erase(it);
	}
}
ATarget*	TargetGenerator::createTarget(std::string const& type) {
	std::map<std::string, ATarget*>::iterator	it = _TargetGenerator.find(type);
	if (it != _TargetGenerator.end()) {
		return _TargetGenerator[type]->clone();
	}
	return NULL;
}
