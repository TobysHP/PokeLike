#include "Pokemon.h"



Pokemon::Pokemon()
{
	//lire les variables dans database + condition pour les attaques (en link direct 4)
	//80 par 80 pour le sprite
}


Pokemon::~Pokemon()
{

}

sf::String Pokemon::p_getnom()
{
	return p_nom;
}
sf::String Pokemon::p_gettype()
{
	return p_type;
}
int Pokemon::p_getpvmax()
{
	return p_pvmax;
}
int Pokemon::p_getatk()
{
	return p_atk;
}
int Pokemon::p_getatkspe()
{
	return p_atkspe;
}
int Pokemon::p_getdef()
{
	return p_def;
}
int Pokemon::p_getdefspe()
{
	return p_defspe;
}
int Pokemon::p_getvit()
{
	return p_vit;
}
int Pokemon::p_getrare()
{
	return p_rare;
}
int Pokemon::p_getevdonne()
{
	return p_evdonne;
}
std::string Pokemon::p_gettypeev()
{
	return p_typeev;
}
int Pokemon::p_getnombretype()
{
	return p_nombretype;
}

