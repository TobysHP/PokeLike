#pragma once
#include "Pokemon.h"


//constructeur par d�faut
Pokemon::Pokemon()
{
	
}
//constructeur par param�tre
Pokemon::Pokemon(int ID, std:: string nom, std:: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit,  int evdonne, std:: string typeev)
{
	p_ID = ID;
	//std::cout << p_ID << std::endl;
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

	//on exploite le nombre plus loin, on transpose donc le nom du type en nombre �quivalent, on aurait aussi pu le g�rer dans la base de donn�es et charger cette donn�e suppl�mentaire (il aurait fallut rajouter une colonne)
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
//destructeur par d�faut
Pokemon::~Pokemon()
{

}
//r�cup�rer le nom
std:: string Pokemon::p_getnom()
{
	return p_nom;
} 
//r�cup�rer le type
std:: string Pokemon::p_gettype()
{
	return p_type;
}
//r�cup�rer la position en x sur la grille
int Pokemon::p_getposx()
{
	return p_posx;
} 
//r�cup�rer la position en y sur la grille
int Pokemon::p_getposy()
{
	return p_posy;
} 
//r�cup�rer les pvs max
int Pokemon::p_getpvmax()
{
	return p_pvmax;
} 
//r�cup�rer l'attaque d'un pok�mon
int Pokemon::p_getatk()
{
	return p_atk;
} 
//r�cup�rer l'attaque sp�ciale d'un pok�mon
int Pokemon::p_getatkspe()
{
	return p_atkspe;
} 
//r�cup�rer la d�fense du pok�mon
int Pokemon::p_getdef()
{
	return p_def;
} 
//r�cup�rer la d�fense sp�ciale du pok�mon 
int Pokemon::p_getdefspe()
{
	return p_defspe;
} 
//r�cup�rer la vitesse du pok�mon
int Pokemon::p_getvit()
{
	return p_vit;
}
//r�cup�rer les ev donn� par le pok�mon (la valeur num�rique)
int Pokemon::p_getevdonne()
{
	return p_evdonne;
}
//r�cup�rer les ev donn� par le pok�mon (la statistique affect�e)
std:: string Pokemon::p_gettypeev()
{
	return p_typeev;
} 
//r�cup�rer le nombre associ� au type
int Pokemon::p_getnombretype()
{
	return p_nombretype;
}
//r�cup�rer l'id du pok�mon
int Pokemon::p_getid()
{
	return p_ID;
} 
//r�cup�rer le sprite du pok�mon
sf::Sprite Pokemon::p_getsprite() {
	return p_sprite;
}
//initialiser le sprite du pok�mon
//x �tant le facteur graphique
void Pokemon::p_setsprite(int x) {
	p_texture.loadFromFile("Sprite/4g_sprite_pokemon.png", sf::IntRect(p_posx, p_posy, 80, 80));
	p_sprite.setTexture(p_texture);
	p_sprite.setScale(2*x, 2*x);
}
//initialiser la position du sprite du pok�mon
//x et y sont l'abscisse et l'ordonn�e, facteurG le facteur graphique
void Pokemon::p_setSpritePosition(float x, float y, float facteurG)
{
	p_sprite.setPosition(facteurG*x, facteurG*y);
} 
//r�cup�rer l'affichage d'un pok�mon, on s'en sert pour le pok�dex
std::string Pokemon::p_getAffichage()
{
	std::string textString;
	textString = "ID: " + std::to_string(p_ID)
		+ "\nType:\t" + p_type
		+ "\nAttaque:\t" + std::to_string(p_atk) + "\tAttaque Speciale:\t" + std::to_string(p_atkspe)
		+ "\nDefense:\t" + std::to_string(p_def) + "\tDefense Speciale:\t" + std::to_string(p_defspe)
		+ "\nVitesse:\t" + std::to_string(p_vit) + "\tPV:\t" + std::to_string(p_pvmax)
		+ "\nPress S to sort options";
	/*sf::Text text((sf::String) textString, font, 20);
	text.setPosition(610, 740);
	text.setFillColor(sf::Color::White);*/
	return textString;
}

/*int Pokemon::p_getrare()
{
	return p_rare;
}*/