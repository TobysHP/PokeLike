#pragma once
#include"Pokemonstock.h"

class Pokemoncombat : public Pokemonstock {//classe des pok�mons qui se battent ! cette classe est � part car les statistiques d'un pok�mon qui se bat peuvent changer au court du combat, mais il ne faut pas que ses statistiques de base soient chang� ! il faut donc avoir en quelque sortes des "copies" des statistiques, qui elles peuvent �voluer en combat ! ces statistiques de combat seront celles sur lesquelles nous effectuerons le calcul des d�gats
public : 
	//constructeur par d�faut
	Pokemoncombat();
	//constructeur de copie
	Pokemoncombat(Pokemonstock acopier);
	//constructeur par param�tre
	Pokemoncombat(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant, Attaque atq1, Attaque atq2, Attaque atq3, Attaque atq4);
	//destructeur par d�faut
	~Pokemoncombat();
	//r�cup�rer la statistique d'attaque de combat
	int pc_getatkcombat();
	//r�cup�rer la statistique d'attaque sp�ciale de combat
	int pc_getatkspecombat();
	//r�cup�rer la statistique de d�fense de combat
	int pc_getdefcombat();
	//r�cup�rer la statistique de d�fense sp�ciale de combat
	int pc_getdefspecombat();
	//r�cup�rer la statistique de vitesse de combat
	int pc_getvitcombat();
	//fonction qui permet au pok�mon qui l'appelle de subir les d�bats
	void pc_getdegats(Attaque lattaque, float matricecoef[17][17], Pokemoncombat attaquant);
	//fonction qui multiplie la stat affect� par la valeur du coefficient, on s'en sert aussi bien pour augmenter que r�duire les statistiques, voir dans d�roulement combat
	void pc_setupself(Attaque lattaque);

private :
	int pc_atkcombat;
	int pc_atkspecombat;
	int pc_defcombat;
	int pc_defspecombat;
	int pc_vitcombat;
};