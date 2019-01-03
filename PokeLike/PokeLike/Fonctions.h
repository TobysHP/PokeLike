#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>
//cette fonction gère les collisions
//paramètre p1 : le dresseur
//paramètre p2 : l'élément avec lequel on cherche la collision
//return un vecteur de booléen, une colision vaut pour 1 dans le tableau, et 0 si il n'y en a pas
std::vector<bool> Collision(sf::FloatRect p1, sf::FloatRect p2) {
	std::vector<bool> tab; //[gauche, droite, haut, bas]
	// on va prendre la position des 4 segments de chaques sprites
	float h1 = p1.top; // en haut
	float b1 = h1 + p1.height; // en bas
	float g1 = p1.left; // à gauche
	float d1 = g1 + p1.width; // à droite

	float h2 = p2.top; // en haut
	float b2 = h2 + p2.height; // en bas
	float g2 = p2.left; // à gauche
	float d2 = g2 + p2.width; // à droite

	std::vector<bool>::iterator it = tab.begin();

	if (g1 == d2 && ((h1>h2 && h1<b2) || (b1>h2 && b1<b2)))
		tab.push_back(1);
	else
		tab.push_back(0);
	if (d1 == g2 && ((h1>h2 && h1<b2) || (b1>h2 && b1<b2)))
		tab.push_back(1);
	else
		tab.push_back(0);
	if (h1 == b2 && ((d1<d2 && d1>g2) || (g1<d2 && g1>g2)))
		tab.push_back(1);
	else
		tab.push_back(0);
	if (b1 == h2 && ((d1<d2 && d1>g2) || (g1<d2 && g1>g2)))
		tab.push_back(1);
	else
		tab.push_back(0);

	//std::cout << h1 << " " << b1 << " " << g1 << " " << d1 << " -- " << h2 << " " << b2 << " " << g2 << " " << d2 << " -- " << tab[0] << tab[1] << tab[2] << tab[3] << std::endl;
	return tab;
}
