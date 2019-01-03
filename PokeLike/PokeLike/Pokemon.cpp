#pragma once
#include "Pokemon.h"


//constructeur par défaut
Pokemon::Pokemon()
{
	
}
//constructeur par paramètre
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

	//on exploite le nombre plus loin, on transpose donc le nom du type en nombre équivalent, on aurait aussi pu le gérer dans la base de données et charger cette donnée supplémentaire (il aurait fallut rajouter une colonne)
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
//destructeur par défaut
Pokemon::~Pokemon()
{

}
//récupérer le nom
std:: string Pokemon::p_getnom()
{
	return p_nom;
} 
//récupérer le type
std:: string Pokemon::p_gettype()
{
	return p_type;
}
//récupérer la position en x sur la grille
int Pokemon::p_getposx()
{
	return p_posx;
} 
//récupérer la position en y sur la grille
int Pokemon::p_getposy()
{
	return p_posy;
} 
//récupérer les pvs max
int Pokemon::p_getpvmax()
{
	return p_pvmax;
} 
//récupérer l'attaque d'un pokémon
int Pokemon::p_getatk()
{
	return p_atk;
} 
//récupérer l'attaque spéciale d'un pokémon
int Pokemon::p_getatkspe()
{
	return p_atkspe;
} 
//récupérer la défense du pokémon
int Pokemon::p_getdef()
{
	return p_def;
} 
//récupérer la défense spéciale du pokémon 
int Pokemon::p_getdefspe()
{
	return p_defspe;
} 
//récupérer la vitesse du pokémon
int Pokemon::p_getvit()
{
	return p_vit;
}
//récupérer les ev donné par le pokémon (la valeur numérique)
int Pokemon::p_getevdonne()
{
	return p_evdonne;
}
//récupérer les ev donné par le pokémon (la statistique affectée)
std:: string Pokemon::p_gettypeev()
{
	return p_typeev;
} 
//récupérer le nombre associé au type
int Pokemon::p_getnombretype()
{
	return p_nombretype;
}
//récupérer l'id du pokémon
int Pokemon::p_getid()
{
	return p_ID;
} 
//récupérer le sprite du pokémon
sf::Sprite Pokemon::p_getsprite() {
	return p_sprite;
}
//initialiser le sprite du pokémon
//x étant le facteur graphique
void Pokemon::p_setsprite(int x) {
	p_texture.loadFromFile("Sprite/4g_sprite_pokemon.png", sf::IntRect(p_posx, p_posy, 80, 80));
	p_sprite.setTexture(p_texture);
	p_sprite.setScale(2*x, 2*x);
}
//initialiser la position du sprite du pokémon
//x et y sont l'abscisse et l'ordonnée, facteurG le facteur graphique
void Pokemon::p_setSpritePosition(float x, float y, float facteurG)
{
	p_sprite.setPosition(facteurG*x, facteurG*y);
} 
//récupérer l'affichage d'un pokémon, on s'en sert pour le pokédex
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