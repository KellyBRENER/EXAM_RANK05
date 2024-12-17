#pragma once

#include "ASpell.hpp"
#include "SpellBook.hpp"
#include <map>

class	Warlock {
	private:
	std::string _name;
	std::string	_title;
	SpellBook	_spellBook;
	Warlock();
	Warlock(Warlock const& src);
	Warlock &	operator=(Warlock const& src);
	public:
	Warlock(std::string name, std::string title);
	~Warlock();
	std::string const&	getName() const;
	std::string const&	getTitle() const;
	void	setTitle(std::string title);
	void	introduce() const;

	void	learnSpell(ASpell* spell);
	void	forgetSpell(std::string spellName);
	void	launchSpell(std::string spellName, ATarget const& target);
};
