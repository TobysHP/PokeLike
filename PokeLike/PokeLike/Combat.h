#pragma once
#include"Pokemon.h"
#include"Pokemonstock.h"
#include"Pokemoncombat.h"
#include"attaque.h"
#include"Dresseur.h"

template <class a> void deroulementattaque(class a lattaquant, class a quisubit, int atqselect, float matricecoef[17][17])//c'est une seule partie : une phase d'attaque, � dupliquer pour contre attaque
{
	if (lattaquant.p_getattaque(atqselect).a_getstatut() == 1)//que d�gats
	{
		quisubit.pc_getdegats(lattaquant.p_getattaque(atqselect), matricecoef, lattaquant);//cr�er la m�thode dans pkmn getdegats, celle devra contenir la table de correspondance
	}
	else if (lemien.p_getattaque(attaquejoueur).a_getstatut() == 2)//que setup
	{
		lemien.pc_setup(lemien.p_getattaque(attaquejoueur));
	}
	else//C'est les 2 donc ! 
	{
		ennemi.pc_getdegats(lemien.p_getattaque(attaquejoueur));
		lemien.pc_setup(lemien.p_getattaque(attaquejoueur));
	}
}

void lecombat(Dresseur &dress, Pokemoncombat ennemi, bool &endcombat) {
	int const nmax = 17;
	int selection = 0;//1 = combat, 2 : ball,  3 switch, 4 fuite
	int attaquejoueur = 0;//vaudra0,1,2 ou 3 pour se balader dans le tableau des attaques du pkmn du dresseur
	bool fuite = false;
	bool switchp = false;
	int nombre;
	bool win = false;
	int i = 0;
	bool okdecontinuer = true;
	float matricecoef[nmax][nmax] = { {1,1,1,1,1,1,2,1,1,1,1,1,1,0,1,1,1},
		{1,0.5,2,0.5,1,0.5,1,1,2,1,1,0.5,2,1,1,1,0.5},
		{1,0.5,0.5,2,2,0.5,1,1,1,1,1,1,1,1,1,1,0.5},
		{1,2,0.5,0.5,0.5,2,1,2,0.5,2,1,2,1,1,1,1,1},
		{1,1,1,1,0.5,1,1,1,2,0.5,1,1,1,1,1,1,1},
		{1,2,1,1,1,0.5,2,1,1,1,1,1,2,1,1,1,2},
		{1,1,1,1,1,1,1,1,1,2,2,0.5,0.5,1,1,0.5,1},
		{1,1,1,0.5,1,1,0.5,0.5,2,1,2,0.5,1,1,1,1,1},
		{1,1,2,2,0,2,1,0.5,1,1,1,1,0.5,1,1,1,1},
		{1,1,1,0.5,2,2,0.5,1,0,1,1,0.5,2,1,1,1,1},
		{1,1,1,1,1,1,0.5,1,1,1,0.5,2,1,2,1,2,1},
		{1,2,1,0.5,1,1,0.5,1,0.5,2,1,1,2,1,1,1,1},
		{0.5,0.5,2,2,1,1,2,0.5,2,0.5,1,1,1,1,1,1,2},
		{0,1,1,1,1,1,0,0.5,1,1,1,0.5,1,2,1,2,1},
		{1,0.5,0.5,0.5,0.5,2,1,1,1,1,1,1,1,1,2,1,1},
		{1,1,1,1,1,1,2,1,1,1,0,2,1,0.5,1,0.5,1},
		{0.5,2,1,0.5,1,0.5,2,0,2,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5} };
	//i : premi�re comp : type d�f, j : 2eme comp type attaque
	//ordre des types voir table image pc, juste penser � bien tout associer � la cr�ation
	//doit passer comme param ! 
	//endcombat=true pour le d�but du combat, passera � false � la fin du combat

	//il faut penser � charger les pok�mons avant de faire quoi que ce soit ! 
	//ennemi est pass� en param (d�j� au format combat) alors que pour le dresseur, il faut encore charger le premier pkmn (en stock) sous forme combat avec une copie!
	//charger un pkmn non ko ! 
	while (dress.d_getpokemon(i).ps_getpvrestant() == 0)//faudra s'assurer que quand tout les pkmn du dress sont ko, c'est game over et pokecentre instant
	{
		i++;
	}
	Pokemoncombat lemien = Pokemoncombat(dress.d_getpokemon(i));//cr�er le constructeur de copie
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
	{
		//ouvrir le sous menu des attaques, rentre un int pour l'attaque s�lectionn�, puis continuer le combat
		//attaquejoueur=true
		selection = 1;//je d�cide donc de me battre, il faut que je s�lectionne une attaque par la suite ! 
		//voir sur le git (et le ranger !) ce que pierre fait pour faire bouger le curseur et valider une option
	}
	if (selection==1)//combat
	{
		if (lemien.pc_getvitcombat() > ennemi.pc_getvitcombat())//mon pokemon attaque donc en premier
		{
			deroulementattaque(lemien, ennemi, attaquejoueur, matricecoef);//degats s'infligent
			if (ennemi.ps_getpvrestant() == 0)
			{
				std::cout << "Pokemon vaincu !" << std::endl;
				win = true;
				//le pokemon qui s'est battu gagne des points d�pendant des evs de la cible vaincue
				endcombat = false;
				return;
			}
			//si encore en vie, l'autre pok�mon contre attaque ! 
			nombre = (rand() % 4);//l'autre pok�mon doit s�lectionner une attaque
			deroulementattaque(ennemi, lemien, nombre, matricecoef);
			if (lemien.ps_getpvrestant() == 0)//cr�er un attribut + m�thode pv actuel dans pokemon//donc mnt si il est ko le combat s'arr�te ! 
			{
				std::cout << "Mon Pok�mon ko !" << std::endl;
				for (int c = 0; i < 6; i++)
				{
					if (dress.d_getpokemon(c).ps_getpvrestant() == 0)
					{
						i++;
					}
	
				}
				if (i == 6)
				{
					std::cout << "gameover" <<std::endl;
				}
				std::cout << "changer de pkmn?" << std::endl;
				//afficher un choix yes/no
				//if yes, switch p = true, je charge un autre
				if (switchp == true)
				{
					dress.d_getpokemon(i).ps_fincombat(lemien, ennemi, win);
					std::cout << "quel pokemon selectionner?" << std::endl;
					/*do {
						//selection dans sous menu
					}while()*///tant que la selection n'a pas des pvs actifs !=0
				}
				else//switchp=false
				{
					//terminer le combat
					std::cout << "fuite" << std::endl;
					endcombat = false;
				}
			}
		}
		else//meme boucle de d�gats � l'envers, c'est donc le pok�mon sauvage le plus rapide
		{
			nombre = (rand() % 4);//l'autre pok�mon doit s�lectionner une attaque
			deroulementattaque(ennemi, lemien, nombre, matricecoef);//degats s'infligent
			if (lemien.ps_getpvrestant() == 0)//cr�er un attribut + m�thode pv actuel dans pokemon//donc mnt si il est ko le combat s'arr�te ! 
			{
				std::cout << "Mon Pok�mon ko !" << std::endl;
				for (int c = 0; i < 6; i++)
				{
					if (dress.d_getpokemon(c).ps_getpvrestant() == 0)
					{
						i++;
					}

				}
				if (i == 6)
				{
					std::cout << "gameover" << std::endl;
				}
				std::cout << "changer de pkmn?" << std::endl;
				//afficher un choix yes/no
				//if yes, switch p = true, je charge un autre
				if (switchp == true)
				{
					dress.d_getpokemon(i).ps_fincombat(lemien, ennemi, win);
					std::cout << "quel pokemon selectionner?" << std::endl;
					/*do {
						//selection dans sous menu
					}while()*///tant que la selection n'a pas des pvs actifs !=0
				}
				else//switchp=false
				{
					//terminer le combat
					std::cout << "fuite" << std::endl;
					endcombat = false;
				}
			}
			//�� va avoir un comportement bizzare ��, � fix ! 
			//si encore en vie, l'autre pok�mon contre attaque ! 
			deroulementattaque(lemien, ennemi, attaquejoueur, matricecoef);
			if (ennemi.ps_getpvrestant() == 0)
			{
				std::cout << "Pokemon vaincu !" << std::endl;
				win = true;
				//le pokemon qui s'est battu gagne des points d�pendant des evs de la cible vaincue
				endcombat = false;
				return;
			}
		}
	}
	if (selection == 2)//capture
	{

	}
	if (selection == 3)//switch
	{

	}
	if (selection == 4)//fuite
	{
		std::cout << "fuite !"<<std::endl;
		endcombat = false;
	}

}
