#include "Pokemoncombat.h"

Pokemoncombat::Pokemoncombat()
{

}
Pokemoncombat::Pokemoncombat(Pokemonstock acopier)
{
	Pokemonstock::Pokemonstock(acopier.p_getid(), acopier.p_getnom(), acopier.p_gettype(), acopier.p_getposx(), acopier.p_getposy(), acopier.p_getpvmax(), acopier.p_getatk(), acopier.p_getatkspe(),
		acopier.p_getdef(), acopier.p_getdefspe(), acopier.p_getvit(), acopier.p_getrare(), acopier.p_getevdonne(), acopier.p_gettypeev(), acopier.ps_getpvrestant(), acopier.ps_getattaque(0),
		acopier.ps_getattaque(1), acopier.ps_getattaque(2), acopier.ps_getattaque(3));
	pc_atkcombat=p_atk;
	pc_atkspecombat=p_atkspe;
	pc_defcombat=p_def;
	pc_defspecombat=p_defspe;
	pc_vitcombat=p_vit;
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
	int pvperdu;
	if (lattaque.a_getstataffecteeoff() == "atk")//atk phys
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
