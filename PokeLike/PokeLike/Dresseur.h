#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "Pokemon.h"
#include "Pokemonstock.h"
#include "Pokemoncombat.h"

#ifndef DRESSEUR_H_INCLUDED
#define DRESSEUR_H_INCLUDED
class Dresseur
{
public:
	//constructeur par d�faut
	Dresseur();
	//construit un dresseur (juste les sprites charg�), a surtout servi pour les tests
	Dresseur(float);
	//construit un dresseur
	//param�tre x : facteur graphique
	//param�tre idDresseur : l'id du dresseur � construire
	//param�tre nomDresseur : le nom du dresseur
	Dresseur(float, int idDresseur, std::string nomDresseur);
	//r�cup�rer l'id du dresseur
	int d_getId();
	//r�cup�rer le nom du dresseur
	std::string d_getNom();
	//destructeur 
	~Dresseur();
	//D�finition de la fonction update, qui permet de bouger le dresseur
	void update(std::vector<bool> collision, int pas, float x); //une fonction membre
	sf::Sprite d_sprite;
	//retoure le pok�mon de l'�quipe � la position donn� en param�tre
	Pokemonstock d_getPokemonEquipe(int n);
	//retoure le pok�mon de la boite � la position donn� en param�tre
	Pokemonstock d_getPokemonBoite(int n);
	//soigner tout les pok�mons de l'�quipe, et les mettre � jour dans la base de donn�es
	void d_healequipe();
	//r�cup�rer l'id de l'�quipe du dresseur (de la base de donn�es)
	int d_getIDEquipe();
	//r�cup�rer l'id de la boite du dresseur (de la base de donn�es)
	int d_getIDBoite();
	//changer l'id de la boite du dresseur (servait pour des tests)
	void d_setIDEquipe(int idequipe);
	//changer l'id de l'�quipe du dresseur (servait pour des tests)
	void d_setIDBoite(int idboite);
	//pour ces 2 fcts � suivre, on suppose que le num�ro de boite et d'�quipe du dresseur a bien �t� charg�
	//ces m�thodes �tant des fct qui font des requetes sql, elles sont d�finies dans fctsql.h


	void d_chargerEquipe();
	void d_chargerBoite();
	//apr�s un combat, on utilise cette fonction pour mettre le pok�mon � jour, aussi bien dans le code que dans la base de donn�es
	void d_setPokemonEquipe(Pokemoncombat lepoke, int pos);
	//rend un vecteur contenant la position des pok�mons pas ko
	//on se servira en g�n�ral que de la premi�re position
	std::vector<int> d_getPokePasKO();
	//r�cup�rer la taille de l'�quipe
	int d_getSizeEquipe();
	//r�cup�rer la taille de la boite
	int d_getSizeBoite();
private:
	//les diff�rentes textures du dresseur
	sf::Texture d_texture_down;
	sf::Texture d_texture_down_1;
	sf::Texture d_texture_down_2;
	sf::Texture d_texture_up;
	sf::Texture d_texture_up_1;
	sf::Texture d_texture_up_2;
	sf::Texture d_texture_left;
	sf::Texture d_texture_left_1;
	sf::Texture d_texture_left_2;
	sf::Texture d_texture_right;
	sf::Texture d_texture_right_1;
	sf::Texture d_texture_right_2;
	int d_id;//son id
	std::string d_nom;//son nom
	int d_idBoite;//le num�ro de sa boite de pok�mon dans la base de donn�es
	int d_idEquipe;//le num�ro de son �quipe dans la base de donn�es
	std::vector<Pokemonstock> d_equipe;//�quipe du dresseur
	std::vector<Pokemonstock> d_boite;//boite du dresseur
};
#endif