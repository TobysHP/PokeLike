#pragma once
#include"Pokemon.h"
#include"Pokemonstock.h"
#include"Pokemoncombat.h"
#include"Attaque.h"
#include"Dresseur.h"

 void deroulementattaque(Pokemoncombat &lattaquant, Pokemoncombat &quisubit, int atqselect, float matricecoef[17][17])//c'est une seule partie : une phase d'attaque, à dupliquer pour contre attaque
{
	//1 : degats simple, 2 un setupself, 3 setup ennemi, 4 = 1+2, 5 = 1+3
	if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 1)//que dégats
	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);//créer la méthode dans pkmn getdegats, celle devra contenir la table de correspondance
	}
	else if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 2)//que setupself
	{
		lattaquant.pc_setupself(lattaquant.ps_getattaque(atqselect));
	}
	else if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 3)//que setup ennemi
	{
		quisubit.pc_setupself(lattaquant.ps_getattaque(atqselect));//appelle aussi setup (qui multiplie les stats) sauf que c'est l'ennemi qui est la target mnt
	}
	else if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 4)//dégats + setupself
	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);
		lattaquant.pc_setupself(lattaquant.ps_getattaque(atqselect));
	}
	else// degats + setup ennemi

	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);
		quisubit.pc_setupself(lattaquant.ps_getattaque(atqselect));
	}
}
