#pragma once
#include "Attaque.h"
//constructeur par défaut
Attaque::Attaque()
{
 
} 
//constructeur par paramètre
Attaque::Attaque(std::string nom, std::string type, int puissanceoff, float puissanceset, std::string stataffoff, std::string stataffset, float precision, int statut)
{
	a_nom = nom;
	a_type = type;
	//a_nombretype plus bas
	a_puissanceoff = puissanceoff;
	a_puissanceset = puissanceset;
	a_stataffecteeoff = stataffoff;
	a_stataffecteeset = stataffset;
	a_precision = precision;
	a_statut = statut;
	if (type == "normal") {
		a_nombretype = 0;
	}
	if (type == "feu") {
		a_nombretype = 1;
	}
	if (type == "eau") {
		a_nombretype = 2;
	}
	if (type == "plante") {
		a_nombretype = 3;
	}
	if (type == "electrik") {
		a_nombretype = 4;
	}
	if (type == "glace") {
		a_nombretype = 5;
	}
	if (type == "combat") {
		a_nombretype = 6;
	}
	if (type == "poison") {
		a_nombretype = 7;
	}
	if (type == "sol") {
		a_nombretype = 8;
	}
	if (type == "vol") {
		a_nombretype = 9;
	}
	if (type == "psy") {
		a_nombretype = 10;
	}
	if (type == "insecte") {
		a_nombretype = 11;
	}
	if (type == "roche") {
		a_nombretype = 12;
	}
	if (type == "spectre") {
		a_nombretype = 13;
	}
	if (type == "dragon") {
		a_nombretype = 14;
	}
	if (type == "tenebres") {
		a_nombretype = 15;
	}
	if (type == "acier") {
		a_nombretype = 16;
	}
}
//destructeur par défaut
Attaque::~Attaque()
{
}
//récupérer le nom de l'attaque
std::string Attaque :: a_getnom()
{
return a_nom; 
}
//récupérer le type de l'attaque
std::string Attaque :: a_gettype()
{
return a_type; 
}
//récupérer la puissance offensive de l'attaque
int Attaque :: a_getpuissanceoff()
{
return a_puissanceoff;
}
//récupérer le coefficient numérique du set de l'attaque
float Attaque :: a_getpuissanceset()
{
	return a_puissanceset;
}
//récupérer la statistique affectée par l'attaque offensive (physique ou spéciale)
std::string Attaque :: a_getstataffecteeoff()
{
return a_stataffecteeoff;
}
//récupérer la statistique affectée par le set (une des stats de combat)
std::string Attaque::a_getstataffecteeset()
{
	return a_stataffecteeset;
}
//récupérer la précision de l'attaque
float Attaque :: a_getprecision()
{
return a_precision;
}
//récupérer le nombre associé au type de l'attaque
int Attaque::a_getnombretype()
{
	return a_nombretype;
}
//récupérer le statut de l'attaque
int Attaque::a_getstatut()
{
	return a_statut;
}
//récupérer l'affichage de l'attaque, sera utile pour l'affichage des pokemons dans la boite et l'équipe
std::string Attaque::a_getAffichage()
{
	switch (a_statut) {
	case 1:
		return a_nom + "\t" + a_type + "\t" + a_stataffecteeoff + "\t" + std::to_string(a_puissanceoff);
	case 2:
		return a_nom + "\t" + a_type + "\t" + a_stataffecteeset + "\tx" + std::to_string(a_puissanceset)[0];
	case 3:
		return a_nom + "\t" + a_type + "\t" + a_stataffecteeset + "\t/" + std::to_string(1 / a_puissanceset)[0];
	case 4:
		return a_nom + "\t" + a_type + "\t" + a_stataffecteeoff + "\t" + std::to_string(a_puissanceoff) + " + " + a_stataffecteeset + "\tx" + std::to_string(a_puissanceset)[0];
	case 5:
		return a_nom + "\t" + a_type + "\t" + a_stataffecteeoff + "\t" + std::to_string(a_puissanceoff) + " + " + a_stataffecteeset + "\t/" + std::to_string(1 / a_puissanceset)[0];
	}


	return std::string();
}
