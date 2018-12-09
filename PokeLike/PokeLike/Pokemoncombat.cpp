#pragma once
#include "Pokemoncombat.h"

Pokemoncombat::Pokemoncombat()
{

}
Pokemoncombat::Pokemoncombat(Pokemonstock acopier)
{
	/*Pokemonstock::Pokemonstock(acopier.p_getid(), acopier.p_getnom(), acopier.p_gettype(), acopier.p_getposx(), acopier.p_getposy(), acopier.p_getpvmax(), acopier.p_getatk(), acopier.p_getatkspe(),
		acopier.p_getdef(), acopier.p_getdefspe(), acopier.p_getvit(), acopier.p_getevdonne(), acopier.p_gettypeev(), acopier.ps_getpvrestant(), acopier.ps_getattaque(0),
		acopier.ps_getattaque(1), acopier.ps_getattaque(2), acopier.ps_getattaque(3));*/
	ps_pvrestant = acopier.ps_getpvrestant();
	p_ID = acopier.p_getid();
	std::cout << p_ID << std::endl;
	p_nom = acopier.p_getnom();
	p_type = acopier.p_gettype();
	p_posx = acopier.p_getposx();
	p_posy = acopier.p_getposy();
	p_pvmax = acopier.p_getpvmax();
	p_atk = acopier.p_getatk();
	p_atkspe = acopier.p_getatkspe();
	p_def = acopier.p_getdef();
	p_defspe = acopier.p_getdefspe();
	p_vit = acopier.p_getvit();
	//p_rare = 1;//on en aura pas besoin
	p_evdonne = acopier.p_getevdonne();
	p_typeev = acopier.p_gettypeev();
	std::string type = acopier.p_gettype();
	//on va le charger sur une autre fonciton pour les temps de calcul lors de chargement
	if (type == "normal") {
		p_nombretype = 0;
	}
	if (type == "feu") {
		p_nombretype = 1;
	}
	if (type == "eau") {
		p_nombretype = 2;
	}
	if (type == "plante") {
		p_nombretype = 3;
	}
	if (type == "electrik") {
		p_nombretype = 4;
	}
	if (type == "glace") {
		p_nombretype = 5;
	}
	if (type == "combat") {
		p_nombretype = 6;
	}
	if (type == "poison") {
		p_nombretype = 7;
	}
	if (type == "sol") {
		p_nombretype = 8;
	}
	if (type == "vol") {
		p_nombretype = 9;
	}
	if (type == "psy") {
		p_nombretype = 10;
	}
	if (type == "insecte") {
		p_nombretype = 11;
	}
	if (type == "roche") {
		p_nombretype = 12;
	}
	if (type == "spectre") {
		p_nombretype = 13;
	}
	if (type == "dragon") {
		p_nombretype = 14;
	}
	if (type == "tenebres") {
		p_nombretype = 15;
	}
	if (type == "acier") {
		p_nombretype = 16;
	}
	for (int i = 0; i<4; i++)
	{
		ps_listeatq[i] = acopier.ps_getattaque(i);
	}
	pc_atkcombat=p_atk;
	pc_atkspecombat=p_atkspe;
	pc_defcombat=p_def;
	pc_defspecombat=p_defspe;
	pc_vitcombat=p_vit;
}
Pokemoncombat::Pokemoncombat(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant, Attaque atq1, Attaque atq2, Attaque atq3, Attaque atq4)
{
	ps_pvrestant = pvrestant;
	p_ID = ID;
	std::cout << p_ID << std::endl;
	p_nom = nom;
	p_type = type;
	p_posx = posx;
	p_posy = posy;
	p_pvmax = pvmax;
	p_atk = atk;
	p_atkspe = atkspe;
	p_def = def;
	p_defspe = defspe;
	p_vit = vit;
	p_evdonne = evdonne;
	p_typeev = typeev;
	ps_listeatq[0] = atq1;
	ps_listeatq[1] = atq2;
	ps_listeatq[2] = atq3;
	ps_listeatq[3] = atq4;
	pc_atkcombat = p_atk;
	pc_atkspecombat = p_atkspe;
	pc_defcombat = p_def;
	pc_defspecombat = p_defspe;
	pc_vitcombat = p_vit;
	if (type == "normal") {
		p_nombretype = 0;
	}
	if (type == "feu") {
		p_nombretype = 1;
	}
	if (type == "eau") {
		p_nombretype = 2;
	}
	if (type == "plante") {
		p_nombretype = 3;
	}
	if (type == "electrik") {
		p_nombretype = 4;
	}
	if (type == "glace") {
		p_nombretype = 5;
	}
	if (type == "combat") {
		p_nombretype = 6;
	}
	if (type == "poison") {
		p_nombretype = 7;
	}
	if (type == "sol") {
		p_nombretype = 8;
	}
	if (type == "vol") {
		p_nombretype = 9;
	}
	if (type == "psy") {
		p_nombretype = 10;
	}
	if (type == "insecte") {
		p_nombretype = 11;
	}
	if (type == "roche") {
		p_nombretype = 12;
	}
	if (type == "spectre") {
		p_nombretype = 13;
	}
	if (type == "dragon") {
		p_nombretype = 14;
	}
	if (type == "tenebres") {
		p_nombretype = 15;
	}
	if (type == "acier") {
		p_nombretype = 16;
	}

}
Pokemoncombat:: ~Pokemoncombat()
{
	Pokemon::~Pokemon();	
}
int Pokemoncombat::pc_getatkcombat()
{
	return pc_atkcombat;
}
int Pokemoncombat::pc_getatkspecombat()
{
	return pc_atkspecombat;
}
int Pokemoncombat::pc_getdefcombat()
{
	return pc_defcombat;
}
int Pokemoncombat::pc_getdefspecombat()
{
	return pc_defspecombat;
}
int Pokemoncombat::pc_getvitcombat()
{
	return pc_vitcombat;
}
void Pokemoncombat::pc_getdegats(Attaque lattaque, float matricecoef[17][17], Pokemoncombat attaquant)
{
	float coef;
	coef = matricecoef[(*this).p_getnombretype()][lattaque.a_getnombretype()];
	//coef = matricecoef[1][1];
	int pvperdu;
	if (lattaque.a_getstataffecteeoff() == "physique")//atk phys
	{
		pvperdu = coef*(attaquant.pc_getatkcombat()* lattaque.a_getpuissanceoff() / ((*this).pc_getdefcombat()));//float to int ok car valeur arrondies ! 
	}
	else//atk spe
	{
		pvperdu = coef*(attaquant.pc_getatkspecombat() * lattaque.a_getpuissanceoff() / ((*this).pc_getdefspecombat()));
	}
	ps_pvrestant -= pvperdu;
	if (ps_pvrestant < 0)
	{
		ps_pvrestant = 0;//pas de pv sous 0
	}
	//std::cout<<"pv restant :"<<ps_pvrestant<<std::endl;
}
void Pokemoncombat::pc_setupself(Attaque lattaque)//multiplier la stat affecté par le boost par le coef
{
	if (lattaque.a_getstataffecteeset() == "atk")
	{
		pc_atkcombat *= lattaque.a_getpuissanceset();
	}
	if (lattaque.a_getstataffecteeset() == "atkspe")
	{
		pc_atkspecombat *= lattaque.a_getpuissanceset();
	}
	if (lattaque.a_getstataffecteeset() == "def")
	{
		pc_defcombat *= lattaque.a_getpuissanceset();
	}
	if (lattaque.a_getstataffecteeset() == "defspe")
	{
		pc_defspecombat *= lattaque.a_getpuissanceset();
	}
	if (lattaque.a_getstataffecteeset() == "vit")
	{
		pc_vitcombat *= lattaque.a_getpuissanceset();
	}
}
