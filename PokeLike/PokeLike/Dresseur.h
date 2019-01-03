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
	//constructeur par défaut
	Dresseur();
	//construit un dresseur (juste les sprites chargé), a surtout servi pour les tests
	Dresseur(float);
	//construit un dresseur
	//paramètre x : facteur graphique
	//paramètre idDresseur : l'id du dresseur à construire
	//paramètre nomDresseur : le nom du dresseur
	Dresseur(float, int idDresseur, std::string nomDresseur);
	//récupérer l'id du dresseur
	int d_getId();
	//récupérer le nom du dresseur
	std::string d_getNom();
	//destructeur 
	~Dresseur();
	//Définition de la fonction update, qui permet de bouger le dresseur
	void update(std::vector<bool> collision, int pas, float x); //une fonction membre
	sf::Sprite d_sprite;
	//retoure le pokémon de l'équipe à la position donné en paramètre
	Pokemonstock d_getPokemonEquipe(int n);
	//retoure le pokémon de la boite à la position donné en paramètre
	Pokemonstock d_getPokemonBoite(int n);
	//soigner tout les pokémons de l'équipe, et les mettre à jour dans la base de données
	void d_healequipe();
	//récupérer l'id de l'équipe du dresseur (de la base de données)
	int d_getIDEquipe();
	//récupérer l'id de la boite du dresseur (de la base de données)
	int d_getIDBoite();
	//changer l'id de la boite du dresseur (servait pour des tests)
	void d_setIDEquipe(int idequipe);
	//changer l'id de l'équipe du dresseur (servait pour des tests)
	void d_setIDBoite(int idboite);
	//pour ces 2 fcts à suivre, on suppose que le numéro de boite et d'équipe du dresseur a bien été chargé
	//ces méthodes étant des fct qui font des requetes sql, elles sont définies dans fctsql.h


	void d_chargerEquipe();
	void d_chargerBoite();
	//après un combat, on utilise cette fonction pour mettre le pokémon à jour, aussi bien dans le code que dans la base de données
	void d_setPokemonEquipe(Pokemoncombat lepoke, int pos);
	//rend un vecteur contenant la position des pokémons pas ko
	//on se servira en général que de la première position
	std::vector<int> d_getPokePasKO();
	//récupérer la taille de l'équipe
	int d_getSizeEquipe();
	//récupérer la taille de la boite
	int d_getSizeBoite();
private:
	//les différentes textures du dresseur
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
	int d_idBoite;//le numéro de sa boite de pokémon dans la base de données
	int d_idEquipe;//le numéro de son équipe dans la base de données
	std::vector<Pokemonstock> d_equipe;//équipe du dresseur
	std::vector<Pokemonstock> d_boite;//boite du dresseur
};
#endif