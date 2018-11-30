#pragma once

#include"Pokemon.h"

class Pokemonstock : public Pokemon {
public :
	Pokemonstock();
	Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant, Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4);
	Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant);
	Pokemonstock(Pokemon acopier);
	~Pokemonstock();
	int ps_getpvrestant();
	Attaque ps_getattaque(int n);
	void ps_fincombat(Pokemonstock cepokemon, Pokemonstock ciblevaincue, bool win);
	void ps_heal();
	void ps_setatq(Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4);
	void ps_setUneAttaque(Attaque attaque, int i);
	void ps_chargerAttaques();
protected:
	int ps_pvrestant;
	Attaque ps_listeatq[4];
};

