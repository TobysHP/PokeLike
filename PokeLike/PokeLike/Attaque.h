#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
class Attaque {

public:
	Attaque();
	~Attaque();
	std::string a_getnom();
	std::string a_gettype();
	int a_getpuissanceoff();
	int a_getpuissanceset();
	std::string a_getstataffecteeoff();
	std::string a_getstataffecteeset();
	float a_getprecision();
	int a_getnombretype();
	int a_getstatut();


private:
	int a_id;
	std::string a_nom;
	std::string a_type;
	int a_nombretype;
	int a_puissanceoff;//dégats infligé
	int a_puissanceset;//coef du set
	std::string a_stataffecteeoff;//atk(spe)
	std::string a_stataffecteeset;//atk(spe), def(spe), vit
	float a_precision;
	int a_statut;//1 : degats simple, 2 un setupself, 3 setup ennemi, 4 = 1+2, 5 = 1+3
	//pourquoi ne pas créer une variable booléen par type d'attaque au lieu du typecode, niveau mémoire c'est un peu mieux qu'un gros int
//genre un truc ainsi, qui serait stocké dans la database, au lieu du typecode,  des interrupteurs différents???
	//peut-être faire une table de bool
	bool a_normalok;
	bool a_fireok;
	bool a_fightingok;
	bool a_waterok;
	bool a_flyingok;
	bool a_grassok;
	bool a_poison;
	bool a_electric;
	bool a_ground;
	bool a_psychic;
	bool a_rock;
	bool a_ice;
	bool a_bug;
	bool a_dragon;
	bool a_ghost;
	bool a_dark;
	bool a_steel;

};

