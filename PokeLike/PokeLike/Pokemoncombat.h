#pragma once
#include"Pokemonstock.h"

class Pokemoncombat : public Pokemonstock {
public : 
	Pokemoncombat(Pokemon acopier);
	Pokemoncombat(Pokemonstock acopier);
	~Pokemoncombat();
	int pc_getatkcombat();
	int pc_getatkspecombat();
	int pc_getdefcombat();
	int pc_getdefspecombat();
	int pc_getvitcombat();
	void pc_getdegats(Attaque lattaque, float matricecoef[17][17], Pokemoncombat attaquant);
	void pc_setupself(Attaque lattaque);
	std::vector<sf::String> pc_getnomattaques();

private :
	int pc_atkcombat;
	int pc_atkspecombat;
	int pc_defcombat;
	int pc_defspecombat;
	int pc_vitcombat;
	std::vector<Attaque> pc_attaques;
};