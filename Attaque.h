#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
class Attaque {

public:
	Attaque();
	Attaque(std:: string nom, std::string type, int puissanceoff, int puissanceset, std::string stataffoff, std::string stataffset, float precision, int statut);
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
	//int a_id;
	std ::string a_nom;
	std:: string a_type;
	int a_nombretype;
	int a_puissanceoff;//dégats infligé
	int a_puissanceset;//coef du set
	std:: string a_stataffecteeoff;//atk(spe)
	std:: string a_stataffecteeset;//atk(spe), def(spe), vit
	float a_precision;
	int a_statut;//1 : degats simple, 2 un setupself, 3 setup ennemi, 4 = 1+2, 5 = 1+3
	//pourquoi ne pas créer une variable booléen par type d'attaque au lieu du typecode, niveau mémoire c'est un peu mieux qu'un gros int
//genre un truc ainsi, qui serait stocké dans la database, au lieu du typecode,  des interrupteurs différents???
	//peut-être faire une table de bool
	/*bool a_normalok;
	bool a_feuok;
	bool a_eauok;
	bool a_planteok;
	bool a_electrikok;
	bool a_glaceok;
	bool a_combatok;
	bool a_poisonok;
	bool a_solok;
	bool a_volok;
	bool a_psyok;
	bool a_insecteok;
	bool a_rocheok;
	bool a_spectreok;
	bool a_dragonok;
	bool a_tenebresok;
	bool a_acierok;*/
};

