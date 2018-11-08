#include "Attaque.h"
Attaque::Attaque()
{
 
}
Attaque::Attaque(std::string nom, std::string type, int puissanceoff, int puissanceset, std::string stataffoff, std::string stataffset, float precision, int statut)
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
Attaque::~Attaque()
{
}

std::string Attaque :: a_getnom()
{
return a_nom; 
}
std::string Attaque :: a_gettype()
{
return a_type; 
}
int Attaque :: a_getpuissanceoff()
{
return a_puissanceoff;
}
int Attaque :: a_getpuissanceset()
{
	return a_puissanceset;
}
std::string Attaque :: a_getstataffecteeoff()
{
return a_stataffecteeoff;
}
std::string Attaque::a_getstataffecteeset()
{
	return a_stataffecteeset;
}
float Attaque :: a_getprecision()
{
return a_precision;
}
int Attaque::a_getnombretype()
{
	return a_nombretype;
}
int Attaque::a_getstatut()
{
	return a_statut;
}
