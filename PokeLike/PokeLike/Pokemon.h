#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Attaque.h"
//#include "Pokemoncombat.h"
//c'est la classe des pokémons qui peuvent être affiché dans le pokédex
class Pokemon
{
public:
	//constructeur par défaut
	Pokemon();
	//constructeur par paramètre
	Pokemon(int ID, std:: string nom, std:: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev);
	//destructeur par défaut
	~Pokemon();
	//récupérer le nom
	std::string p_getnom();
	//récupérer le type
	std::string p_gettype();
	//récupérer l'id du pokémon
	int p_getid();
	//récupérer la position en x sur la grille
	int p_getposx();
	//récupérer la position en y sur la grille
	int p_getposy();
	//récupérer le nombre associé au type
	int p_getnombretype();
	//récupérer les pvs max
	int p_getpvmax();
	//récupérer l'attaque d'un pokémon
	int p_getatk();
	//récupérer l'attaque spéciale d'un pokémon
	int p_getatkspe();
	//récupérer la défense du pokémon
	int p_getdef();
	//récupérer la défense spéciale du pokémon
	int p_getdefspe();
	//récupérer la vitesse du pokémon
	int p_getvit();
	//récupérer les ev donné par le pokémon (la valeur numérique)
	int p_getevdonne();
	//récupérer les ev donné par le pokémon (la statistique affectée)
	std::string p_gettypeev();
	//initialiser le sprite du pokémon
	//x étant le facteur graphique
	void p_setsprite(int x);
	//initialiser la position du sprite du pokémon
	//x et y sont l'abscisse et l'ordonnée, facteurG le facteur graphique
	void p_setSpritePosition(float x, float y, float facteurG);
	//récupérer le sprite du pokémon
	sf::Sprite p_getsprite();
	//récupérer l'affichage d'un pokémon, on s'en sert pour le pokédex
	std::string p_getAffichage();
	//int p_getrare();//sera inutile finalement
protected://liste des attributs, en grande partie expliqué via l'identification des entités, c'est expliqué dans le rapport
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
	//int p_rare;
	int p_evdonne;
	std :: string p_typeev;
	sf::Sprite p_sprite;
	sf::Texture p_texture;
};
