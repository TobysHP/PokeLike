#pragma once

#include"Pokemon.h"

class Pokemonstock : public Pokemon {//classe pour les pok�mons qui seront utilis�s par un dresseur (en stockage !), donc avec des pvs actifs et des attaques
public :
	//constructeur par d�faut
	Pokemonstock();
	//constructeur par param�tre, avec les attaques comme param�tres, nous ne nous en servons plus je pense dans la version finale
	Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant, Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4);
	//constructeur par param�tre, sans les attaques
	Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant);
	//constructeur de copie
	Pokemonstock(Pokemon acopier);
	//destructeur par d�faut
	~Pokemonstock();
	//r�cup�rer les pvs restant
	int ps_getpvrestant();
	//r�cup�rer l'attaque � la position n
	Attaque ps_getattaque(int n);
	//changer l'id, utile � la capture, car l'id temporaire des pok�mons est celle du pok�dex, on cr�e une nouvelle id � l'insertion dans boite, donc il faut la changer
	void ps_setID(int newid);
	//op�ration de fin de combat
	//si le pok�mon a gagn� (mis les pvs du pok�mon sauvage � 0) alors il gagne des evs d�pendant de son ennemi
	//mettre les pvs � 0 si il est ko
	void ps_fincombat(Pokemonstock cepokemon, Pokemonstock ciblevaincue, bool win);
	//soigner le pok�mon (n'actualise PAS dans la base de donn�es)
	void ps_heal();
	//pour initialiser toutes lesattaques d'un coup, chaque param�tre est une attaque
	void ps_setatq(Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4);
	//initialiser une attaque donn� � la position i
	void ps_setUneAttaque(Attaque attaque, int i);
	void ps_chargerAttaques();//requiert sql => voir fctsql
	void ps_updateDansDB(int boiteOuEquipe);//requiert sql => voir fct sql
	void ps_savelesattaques();//appel�e par ins�rerDansDB, voir fctsql
	void ps_insererDansDb(int boiteOuEquipe);//requiert sql, voir fctsql
	//affichage du pok�mon avec ses attaques, pour l'affichage dans la boite et l'�quipe dans le pc
	std::string ps_getAffichage();
protected:
	int ps_pvrestant;
	Attaque ps_listeatq[4];
};

