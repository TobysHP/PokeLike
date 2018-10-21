#pragma once

#include"Pokemon.h"

class Pokemonstock : public Pokemon {
public :
	Pokemonstock();
	~Pokemonstock();
	int ps_getpvrestant();
	Attaque ps_getattaque(int n);
	void ps_fincombat(Pokemonstock cepokemon, Pokemonstock ciblevaincue, bool win);
	void ps_heal();
protected:
	int ps_pvrestant;
	Attaque ps_listeatq[4];
};

