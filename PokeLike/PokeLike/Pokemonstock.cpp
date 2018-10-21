#pragma once
#include "Pokemonstock.h"
#include "Pokemon.h"

Pokemonstock::Pokemonstock()
{

}
Pokemonstock :: ~Pokemonstock()
{

}
int Pokemonstock::ps_getpvrestant()
{
	return ps_pvrestant;
}
Attaque Pokemonstock::ps_getattaque(int n)
{
	return ps_listeatq[n];
}
void Pokemonstock::ps_fincombat(Pokemonstock cepokemon, Pokemonstock ciblevaincue, bool win)
{
	if (win == true)//ajout des evs
	{
		if (ciblevaincue.p_gettypeev() == "atk")
		{
			p_atk += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "atkspe")
		{
			p_atkspe += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "def")
		{
			p_def += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "defspe")
		{
			p_defspe += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "vit")
		{
			p_vit += ciblevaincue.p_getevdonne();
		}
	}
	//dans tout les cas, actualiser les pvs actuels
	ps_pvrestant = cepokemon.ps_getpvrestant();
	if (ps_pvrestant < 0)
	{
		ps_pvrestant = 0;//pas de pvs sous 0
	}
}
void Pokemonstock::ps_heal()
{
	ps_pvrestant = p_pvmax;
}