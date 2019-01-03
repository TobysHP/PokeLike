#pragma once

#include"Pokemon.h"

class Pokemonstock : public Pokemon {//classe pour les pokémons qui seront utilisés par un dresseur (en stockage !), donc avec des pvs actifs et des attaques
public :
	//constructeur par défaut
	Pokemonstock();
	//constructeur par paramètre, avec les attaques comme paramètres, nous ne nous en servons plus je pense dans la version finale
	Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant, Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4);
	//constructeur par paramètre, sans les attaques
	Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant);
	//constructeur de copie
	Pokemonstock(Pokemon acopier);
	//destructeur par défaut
	~Pokemonstock();
	//récupérer les pvs restant
	int ps_getpvrestant();
	//récupérer l'attaque à la position n
	Attaque ps_getattaque(int n);
	//changer l'id, utile à la capture, car l'id temporaire des pokémons est celle du pokédex, on crée une nouvelle id à l'insertion dans boite, donc il faut la changer
	void ps_setID(int newid);
	//opération de fin de combat
	//si le pokémon a gagné (mis les pvs du pokémon sauvage à 0) alors il gagne des evs dépendant de son ennemi
	//mettre les pvs à 0 si il est ko
	void ps_fincombat(Pokemonstock cepokemon, Pokemonstock ciblevaincue, bool win);
	//soigner le pokémon (n'actualise PAS dans la base de données)
	void ps_heal();
	//pour initialiser toutes lesattaques d'un coup, chaque paramètre est une attaque
	void ps_setatq(Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4);
	//initialiser une attaque donné à la position i
	void ps_setUneAttaque(Attaque attaque, int i);
	void ps_chargerAttaques();//requiert sql => voir fctsql
	void ps_updateDansDB(int boiteOuEquipe);//requiert sql => voir fct sql
	void ps_savelesattaques();//appelée par insérerDansDB, voir fctsql
	void ps_insererDansDb(int boiteOuEquipe);//requiert sql, voir fctsql
	//affichage du pokémon avec ses attaques, pour l'affichage dans la boite et l'équipe dans le pc
	std::string ps_getAffichage();
protected:
	int ps_pvrestant;
	Attaque ps_listeatq[4];
};

