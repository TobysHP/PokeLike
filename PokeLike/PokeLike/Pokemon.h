#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Attaque.h"
//#include "Pokemoncombat.h"

class Pokemon
{
public:
	Pokemon();
	Pokemon(int ID, std:: string nom, std:: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int rare, int evdonne, std::string typeev);
	~Pokemon();
	std::string p_getnom();
	std::string p_gettype();
	int p_getid();
	int p_getposx();
	int p_getposy();
	int p_getnombretype();
	int p_getpvmax();
	int p_getatk();
	int p_getatkspe();
	int p_getdef();
	int p_getdefspe();
	int p_getvit();
	int p_getrare();
	int p_getevdonne();
	std::string p_gettypeev();
	sf::Sprite p_getsprite();
	//friend class Attaque;

protected:
	int p_ID;
	std:: string p_nom;
	std:: string p_type;
	int p_posx;
	int p_posy;
	int p_nombretype;
	int p_pvmax;
	int p_atk;
	int p_atkspe;
	int p_def;
	int p_defspe;
	int p_vit;
	int p_rare;
	int p_evdonne;
	std :: string p_typeev;
	sf::Sprite p_sprite;
	sf::Texture p_texture;
};
