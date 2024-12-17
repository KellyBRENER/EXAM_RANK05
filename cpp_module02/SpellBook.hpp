#pragma once

#include "ASpell.hpp"
#include <map>

class	SpellBook {
	private:
	std::map<std::string, ASpell*>	_spellBook;
	SpellBook(SpellBook const& src);
	SpellBook &	operator=(SpellBook const& src);
	public:
	SpellBook();
	~SpellBook();
	std::string const&	getName() const;
	std::string const&	getTitle() const;
	void	setTitle(std::string title);
	void	introduce() const;

	void	learnSpell(ASpell* spell);
	void	forgetSpell(std::string const& spellName);
	ASpell*	createSpell(std::string const& spellName);
};
