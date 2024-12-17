#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::SpellBook(SpellBook const& src) {*this = src;}
SpellBook &	SpellBook::operator=(SpellBook const& src) {
	if (this != &src) {
		_spellBook = src._spellBook;
	}
	return *this;
}
SpellBook::~SpellBook() {
	std::map<std::string, ASpell*>::iterator	it = _spellBook.begin();
	for (; it != _spellBook.end(); ++it) {
		delete it->second;
	}
	_spellBook.clear();
}

void	SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		if (_spellBook.find(spell->getName()) == _spellBook.end())
			_spellBook[spell->getName()] = spell->clone();
	}
}
void	SpellBook::forgetSpell(std::string const& spellName) {
	std::map<std::string, ASpell*>::iterator	it = _spellBook.find(spellName);
	if (it != _spellBook.end()) {
		delete it->second;
		_spellBook.erase(it);
	}
}
ASpell*	SpellBook::createSpell(std::string const& spellName) {
	std::map<std::string, ASpell*>::iterator	it = _spellBook.find(spellName);
	if (it != _spellBook.end()) {
		return _spellBook[spellName]->clone();
	}
	return NULL;
}
