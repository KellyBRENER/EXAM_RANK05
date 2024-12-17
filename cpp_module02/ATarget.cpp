#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(ATarget const& src) {*this = src;}
ATarget::ATarget(std::string type) : _type(type) {}
ATarget &	ATarget::operator=(ATarget const& src) {
	if (this != &src) {
		_type = src._type;
	}
	return *this;
}
ATarget::~ATarget() {}
std::string	ATarget::getType() const {return _type;}
void	ATarget::getHitBySpell(ASpell const& spell) const {
	std::cout<<_type<<" has been "<<spell.getEffects()<<"!"<<std::endl;
}
