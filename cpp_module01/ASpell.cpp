#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}
ASpell::ASpell(ASpell const& src) {*this = src;}
ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}
ASpell &	ASpell::operator=(ASpell const& src) {
	if (this != &src) {
		_name = src._name;
		_effects = src._effects;
	}
	return *this;
}
ASpell::~ASpell() {}
std::string	ASpell::getName() const {return _name;}
std::string	ASpell::getEffects() const {return _effects;}
void	ASpell::launch(ATarget const& target) const {
	target.getHitBySpell(*this);
}
