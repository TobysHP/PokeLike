#include "Pokemoncombat.h"
Pokemoncombat :: Pokemoncombat(Pokemon acopier)
{
	
}
Pokemoncombat::Pokemoncombat(Pokemonstock acopier)
{

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
	int coef;
	coef = matricecoef[(*this).p_getnombretype()][lattaque.a_getnombretype()];
	int pvperdu;
	if (lattaque.a_getstataffecteeoff() == "atk")//atk phys
	{
		pvperdu = coef*(attaquant.pc_getatkcombat()* lattaque.a_getpuissanceoff() / ((*this).pc_getdefcombat()));
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
std::vector<sf::String> Pokemoncombat::pc_getnomattaques()
{
	std::vector<sf::String> x;
	for (int i = 0; i < 4; i++) {
		x.push_back(pc_attaques[i].a_getnom());
	}
	return x;
}