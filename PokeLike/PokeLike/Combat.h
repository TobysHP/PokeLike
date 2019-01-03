#pragma once
#include"Pokemon.h"
#include"Pokemonstock.h"
#include"Pokemoncombat.h"
#include"Attaque.h"
#include"Dresseur.h"
//cette fonction gère le déroulement d'une attaque, en fonction du statut de celle-ci (voir rapport ou détail code ici plus bas)
//paramètre (par adresse) : lattaquant :  le pokémon qui attaque
//paramètre (par adresse) : quisubit : le pokémon qui va recevoir l'attaque
//paramètre : atqselect : le numéro (0, 1, 2 ou 3) de l'attaque sélectionnée
//paramètre : matricecoef : la matrice des coefficients pour gérer les avantages/désavantages de types
//return : un string, pour gérer l'affichage en combat
 std::string deroulementattaque(Pokemoncombat &lattaquant, Pokemoncombat &quisubit, int atqselect, float matricecoef[17][17])//c'est une seule partie : une phase d'attaque, à dupliquer pour contre attaque
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
	return lattaquant.p_getnom() + " attaque " + lattaquant.ps_getattaque(atqselect).a_getnom();
}
