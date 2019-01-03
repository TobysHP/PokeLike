#pragma once
#include"Pokemon.h"
#include"Pokemonstock.h"
#include"Pokemoncombat.h"
#include"Attaque.h"
#include"Dresseur.h"
//cette fonction g�re le d�roulement d'une attaque, en fonction du statut de celle-ci (voir rapport ou d�tail code ici plus bas)
//param�tre (par adresse) : lattaquant :  le pok�mon qui attaque
//param�tre (par adresse) : quisubit : le pok�mon qui va recevoir l'attaque
//param�tre : atqselect : le num�ro (0, 1, 2 ou 3) de l'attaque s�lectionn�e
//param�tre : matricecoef : la matrice des coefficients pour g�rer les avantages/d�savantages de types
//return : un string, pour g�rer l'affichage en combat
 std::string deroulementattaque(Pokemoncombat &lattaquant, Pokemoncombat &quisubit, int atqselect, float matricecoef[17][17])//c'est une seule partie : une phase d'attaque, � dupliquer pour contre attaque
{
	//1 : degats simple, 2 un setupself, 3 setup ennemi, 4 = 1+2, 5 = 1+3
	if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 1)//que d�gats
	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);//cr�er la m�thode dans pkmn getdegats, celle devra contenir la table de correspondance
	}
	else if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 2)//que setupself
	{
		lattaquant.pc_setupself(lattaquant.ps_getattaque(atqselect));
	}
	else if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 3)//que setup ennemi
	{
		quisubit.pc_setupself(lattaquant.ps_getattaque(atqselect));//appelle aussi setup (qui multiplie les stats) sauf que c'est l'ennemi qui est la target mnt
	}
	else if (lattaquant.ps_getattaque(atqselect).a_getstatut() == 4)//d�gats + setupself
	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);
		lattaquant.pc_setupself(lattaquant.ps_getattaque(atqselect));
	}
	else// degats + setup ennemi

	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);
		quisubit.pc_setupself(lattaquant.ps_getattaque(atqselect));
	}
	return lattaquant.p_getnom() + " attaque " + lattaquant.ps_getattaque(atqselect).a_getnom();
}
