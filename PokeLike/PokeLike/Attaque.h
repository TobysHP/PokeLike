#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
class Attaque {//classe des attaques, on a décrit beaucoup dans le rapport pour tout expliciter, voir là bas donc pour bien comprendre si des questions subsistent ! (identification des entités types)

public:
	//constructeur par défaut
	Attaque();
	//constructeur par paramètre
	Attaque(std:: string nom, std::string type, int puissanceoff, float puissanceset, std::string stataffoff, std::string stataffset, float precision, int statut);
	//destructeur par défaut
	~Attaque();
	//récupérer le nom de l'attaque
	std::string a_getnom();
	//récupérer le type de l'attaque
	std::string a_gettype();
	//récupérer la puissance offensive de l'attaque
	int a_getpuissanceoff();
	//récupérer le coefficient numérique du set de l'attaque
	float a_getpuissanceset();
	//récupérer la statistique affectée par l'attaque offensive (physique ou spéciale)
	std::string a_getstataffecteeoff();
	//récupérer la statistique affectée par le set (une des stats de combat)
	std::string a_getstataffecteeset();
	//récupérer la précision de l'attaque
	float a_getprecision();
	//récupérer le nombre associé au type de l'attaque
	int a_getnombretype();
	//récupérer le statut de l'attaque
	int a_getstatut();
	//récupérer l'affichage de l'attaque, sera utile pour l'affichage des pokemons dans la boite et l'équipe
	std::string a_getAffichage();
private:
	//int a_id;
	std ::string a_nom;
	std:: string a_type;
	int a_nombretype;
	int a_puissanceoff;//dégats infligé
	float a_puissanceset;//coef du set
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

