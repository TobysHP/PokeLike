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
	Dresseur(float);
	~Dresseur();
	void update(std::vector<bool> collision, int pas, float x); //une fonction membre
	sf::Sprite d_sprite;
	Pokemonstock d_getpokemon(int n);
	Pokemonstock d_getequipe();
	void d_healequipe();
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
	Pokemonstock d_equipe[6];
	std::vector<Pokemonstock> d_boite;
};
#endif