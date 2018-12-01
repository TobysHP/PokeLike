#pragma once
#include "Pokemon.h"



Pokemon::Pokemon()
{
	
}
Pokemon::Pokemon(int ID, std:: string nom, std:: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit,  int evdonne, std:: string typeev)
{
	p_ID = ID;
	std::cout << p_ID << std::endl;
	p_nom = nom;
	p_type = type;
	p_posx = posx;
	p_posy = posy;
	p_pvmax = pvmax;
	p_atk = atk;
	p_atkspe = atkspe;
	p_def = def;
	p_defspe = defspe;
	p_vit = vit;
	//p_rare = 1;//on en aura pas besoin
	p_evdonne = evdonne;
	p_typeev = typeev; 
	/*sf::Sprite p_sprite;
	sf::Texture p_texture;
	p_texture.loadFromFile("Sprite/4g_sprite_pokemon.png", sf::IntRect(p_posx, p_posy, 80, 80));
	p_sprite.setTexture(p_texture);*/
	//on va le charger sur une autre fonciton pour les temps de calcul lors de chargement
	if (type=="normal") {
		p_nombretype = 0;
	}
	if (type == "feu") {
		p_nombretype = 1;
	}
	if (type == "eau") {
		p_nombretype = 2;
	}
	if (type == "plante") {
		p_nombretype = 3;
	}
	if (type == "electrik") {
		p_nombretype = 4;
	}
	if (type == "glace") {
		p_nombretype = 5;
	}
	if (type == "combat") {
		p_nombretype = 6;
	}
	if (type == "poison") {
		p_nombretype = 7;
	}
	if (type == "sol") {
		p_nombretype = 8;
	}
	if (type == "vol") {
		p_nombretype = 9;
	}
	if (type == "psy") {
		p_nombretype = 10;
	}
	if (type == "insecte") {
		p_nombretype = 11;
	}
	if (type == "roche") {
		p_nombretype = 12;
	}
	if (type == "spectre") {
		p_nombretype = 13;
	}
	if (type == "dragon") {
		p_nombretype = 14;
	}
	if (type == "tenebres") {
		p_nombretype = 15;
	}
	if (type == "acier") {
		p_nombretype = 16;
	}
}

Pokemon::~Pokemon()
{

}

std:: string Pokemon::p_getnom()
{
	return p_nom;
}
std:: string Pokemon::p_gettype()
{
	return p_type;
}
int Pokemon::p_getposx()
{
	return p_posx;
}
int Pokemon::p_getposy()
{
	return p_posy;
}
int Pokemon::p_getpvmax()
{
	return p_pvmax;
}
int Pokemon::p_getatk()
{
	return p_atk;
}
int Pokemon::p_getatkspe()
{
	return p_atkspe;
}
int Pokemon::p_getdef()
{
	return p_def;
}
int Pokemon::p_getdefspe()
{
	return p_defspe;
}
int Pokemon::p_getvit()
{
	return p_vit;
}
/*int Pokemon::p_getrare()
{
	return p_rare;
}*/
int Pokemon::p_getevdonne()
{
	return p_evdonne;
}
std:: string Pokemon::p_gettypeev()
{
	return p_typeev;
}
int Pokemon::p_getnombretype()
{
	return p_nombretype;
}
int Pokemon::p_getid()
{
	return p_ID;
}
sf::Sprite Pokemon::p_getsprite() {
	return p_sprite;
}
void Pokemon::p_setsprite() {
	sf::Sprite p_sprite;
	sf::Texture p_texture;
	p_texture.loadFromFile("Sprite/4g_sprite_pokemon.png", sf::IntRect(p_posx, p_posy, 80, 80));
	p_sprite.setTexture(p_texture);
}

