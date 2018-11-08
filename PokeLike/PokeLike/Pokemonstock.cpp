#pragma once
#include "Pokemonstock.h"
#include "Pokemon.h"

Pokemonstock::Pokemonstock()
{

}
Pokemonstock::Pokemonstock(int ID, std:: string nom, std :: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int rare, int evdonne, std:: string typeev, int pvrestant, Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4)
{
	
	Pokemon::Pokemon(ID, nom, type, posx, posy, pvmax, atk, atkspe, def, defspe, vit, rare, evdonne, typeev);
	if (evdonne != 0)//j'ai un nouveau pokemon
	{
		ps_pvrestant = pvmax;
	}
	ps_listeatq[0] = attaque1;
	ps_listeatq[1] = attaque2;
	ps_listeatq[2] = attaque3;
	ps_listeatq[3] = attaque4;
}
Pokemonstock::Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int rare, int evdonne, std::string typeev, int pvrestant)
{
	Pokemon::Pokemon(ID, nom, type, posx, posy, pvmax, atk, atkspe, def, defspe, vit, rare, evdonne, typeev);
	if (evdonne != 0)//j'ai un nouveau pokemon
	{
		ps_pvrestant = pvmax;
	}

}
Pokemonstock::Pokemonstock(Pokemon acopier)
{
	Pokemon::Pokemon(acopier.p_getid(), acopier.p_getnom(), acopier.p_gettype(), acopier.p_getposx(), acopier.p_getposy(), acopier.p_getpvmax(), acopier.p_getatk(), acopier.p_getatkspe(),
		acopier.p_getdef(), acopier.p_getdefspe(), acopier.p_getvit(), acopier.p_getrare(), acopier.p_getevdonne(), acopier.p_gettypeev());
	ps_pvrestant = acopier.p_getpvmax();
}
void Pokemonstock::ps_setatq(Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4)
{
	ps_listeatq[0] = attaque1;
	ps_listeatq[1] = attaque2;
	ps_listeatq[2] = attaque3;
	ps_listeatq[3] = attaque4;
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