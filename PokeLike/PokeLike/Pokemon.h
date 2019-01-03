#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Attaque.h"
//#include "Pokemoncombat.h"
//c'est la classe des pok�mons qui peuvent �tre affich� dans le pok�dex
class Pokemon
{
public:
	//constructeur par d�faut
	Pokemon();
	//constructeur par param�tre
	Pokemon(int ID, std:: string nom, std:: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev);
	//destructeur par d�faut
	~Pokemon();
	//r�cup�rer le nom
	std::string p_getnom();
	//r�cup�rer le type
	std::string p_gettype();
	//r�cup�rer l'id du pok�mon
	int p_getid();
	//r�cup�rer la position en x sur la grille
	int p_getposx();
	//r�cup�rer la position en y sur la grille
	int p_getposy();
	//r�cup�rer le nombre associ� au type
	int p_getnombretype();
	//r�cup�rer les pvs max
	int p_getpvmax();
	//r�cup�rer l'attaque d'un pok�mon
	int p_getatk();
	//r�cup�rer l'attaque sp�ciale d'un pok�mon
	int p_getatkspe();
	//r�cup�rer la d�fense du pok�mon
	int p_getdef();
	//r�cup�rer la d�fense sp�ciale du pok�mon
	int p_getdefspe();
	//r�cup�rer la vitesse du pok�mon
	int p_getvit();
	//r�cup�rer les ev donn� par le pok�mon (la valeur num�rique)
	int p_getevdonne();
	//r�cup�rer les ev donn� par le pok�mon (la statistique affect�e)
	std::string p_gettypeev();
	//initialiser le sprite du pok�mon
	//x �tant le facteur graphique
	void p_setsprite(int x);
	//initialiser la position du sprite du pok�mon
	//x et y sont l'abscisse et l'ordonn�e, facteurG le facteur graphique
	void p_setSpritePosition(float x, float y, float facteurG);
	//r�cup�rer le sprite du pok�mon
	sf::Sprite p_getsprite();
	//r�cup�rer l'affichage d'un pok�mon, on s'en sert pour le pok�dex
	std::string p_getAffichage();
	//int p_getrare();//sera inutile finalement
protected://liste des attributs, en grande partie expliqu� via l'identification des entit�s, c'est expliqu� dans le rapport
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
