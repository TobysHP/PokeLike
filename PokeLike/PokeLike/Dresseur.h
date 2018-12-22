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
	Dresseur();
	Dresseur(float);
	Dresseur(float, int idDresseur, std::string nomDresseur);
	int d_getId();
	std::string d_getNom();
	~Dresseur();
	void update(std::vector<bool> collision, int pas, float x); //une fonction membre
	sf::Sprite d_sprite;
	Pokemonstock d_getPokemonEquipe(int n);
	Pokemonstock d_getPokemonBoite(int n);
	void d_healequipe();
	int d_getIDEquipe();
	int d_getIDBoite();
	void d_setIDEquipe(int idequipe);
	void d_setIDBoite(int idboite);
	//pour ces 2 fcts, on suppose que le numéro de boite et d'équipe du dresseur a bien été chargé
	//ces méthodes étant des fct qui font des requetes sql, elles sont définies dans fctsql.h
	void d_chargerEquipe();
	void d_chargerBoite();
	//const std::vector<Pokemonstock>&d_getRefVersEquipe() const;
	std::vector<int> d_getPokePasKO();
	int d_getSizeEquipe();
	int d_getSizeBoite();
private:
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
	int d_id;
	std::string d_nom;
	int d_idBoite;
	int d_idEquipe;
	std::vector<Pokemonstock> d_equipe;
	std::vector<Pokemonstock> d_boite;
};
#endif