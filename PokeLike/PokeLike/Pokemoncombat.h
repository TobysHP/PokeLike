#pragma once
#include"Pokemonstock.h"

class Pokemoncombat : public Pokemonstock {//classe des pokémons qui se battent ! cette classe est à part car les statistiques d'un pokémon qui se bat peuvent changer au court du combat, mais il ne faut pas que ses statistiques de base soient changé ! il faut donc avoir en quelque sortes des "copies" des statistiques, qui elles peuvent évoluer en combat ! ces statistiques de combat seront celles sur lesquelles nous effectuerons le calcul des dégats
public : 
	//constructeur par défaut
	Pokemoncombat();
	//constructeur de copie
	Pokemoncombat(Pokemonstock acopier);
	//constructeur par paramètre
	Pokemoncombat(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant, Attaque atq1, Attaque atq2, Attaque atq3, Attaque atq4);
	//destructeur par défaut
	~Pokemoncombat();
	//récupérer la statistique d'attaque de combat
	int pc_getatkcombat();
	//récupérer la statistique d'attaque spéciale de combat
	int pc_getatkspecombat();
	//récupérer la statistique de défense de combat
	int pc_getdefcombat();
	//récupérer la statistique de défense spéciale de combat
	int pc_getdefspecombat();
	//récupérer la statistique de vitesse de combat
	int pc_getvitcombat();
	//fonction qui permet au pokémon qui l'appelle de subir les débats
	void pc_getdegats(Attaque lattaque, float matricecoef[17][17], Pokemoncombat attaquant);
	//fonction qui multiplie la stat affecté par la valeur du coefficient, on s'en sert aussi bien pour augmenter que réduire les statistiques, voir dans déroulement combat
	void pc_setupself(Attaque lattaque);

private :
	int pc_atkcombat;
	int pc_atkspecombat;
	int pc_defcombat;
	int pc_defspecombat;
	int pc_vitcombat;
};