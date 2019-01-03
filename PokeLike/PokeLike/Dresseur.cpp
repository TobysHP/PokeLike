#pragma once
#include "Dresseur.h"

//constructeur par défaut
Dresseur::Dresseur()
{

}
//construit un dresseur (juste les sprites chargé), a surtout servi pour les tests
Dresseur::Dresseur(float x)
{
	d_texture_down.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 0, 34, 56));
	d_texture_down_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 0, 34, 56));
	d_texture_down_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 0, 34, 56));
	d_texture_left_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 68, 34, 56));
	d_texture_left_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 68, 34, 56));
	d_texture_left.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 68, 34, 56));
	d_texture_up.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 195, 34, 56));
	d_texture_up_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 195, 34, 56));
	d_texture_up_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 195, 34, 56));
	d_texture_right.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 133, 34, 56));
	d_texture_right_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 133, 34, 56));
	d_texture_right_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 133, 34, 56));
	d_sprite.setTexture(d_texture_down);
	d_sprite.setScale(x, x);
	d_sprite.setPosition(x * 650, x * 650);
}
//construit un dresseur
//paramètre x : facteur graphique
//paramètre idDresseur : l'id du dresseur à construire
//paramètre nomDresseur : le nom du dresseur
Dresseur::Dresseur(float x, int idDresseur, std::string nomDresseur)
{
	d_texture_down.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 0, 34, 56));
	d_texture_down_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 0, 34, 56));
	d_texture_down_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 0, 34, 56));
	d_texture_left_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 68, 34, 56));
	d_texture_left_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 68, 34, 56));
	d_texture_left.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 68, 34, 56));
	d_texture_up.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 195, 34, 56));
	d_texture_up_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 195, 34, 56));
	d_texture_up_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 195, 34, 56));
	d_texture_right.loadFromFile("Sprite/sprites.png", sf::IntRect(0, 133, 34, 56));
	d_texture_right_1.loadFromFile("Sprite/sprites.png", sf::IntRect(64, 133, 34, 56));
	d_texture_right_2.loadFromFile("Sprite/sprites.png", sf::IntRect(192, 133, 34, 56));
	d_sprite.setTexture(d_texture_down);
	d_sprite.setScale(x, x);
	d_sprite.setPosition(x * 650, x * 650);
	d_id = idDresseur;
	d_nom = nomDresseur;
}

//destructeur 
Dresseur::~Dresseur()
{
	
}
//Définition de la fonction update, qui permet de bouger le dresseur
void Dresseur::update(std::vector<bool> collision, int pas, float x)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) // Vérifie si la flèche "Down" du clavier est appuyé
	{
		if (pas < 5)
			d_sprite.setTexture(d_texture_down);
		else if (pas < 10)
			d_sprite.setTexture(d_texture_down_1);
		else if (pas < 15)
			d_sprite.setTexture(d_texture_down);
		else if (pas < 20)
			d_sprite.setTexture(d_texture_down_2);
		if (!collision[3])
			d_sprite.move(x * 0, x * 2);// Dans le cas ou la condition du "if" est vérifiée La fonction "move" déplace le sprite selon le vecteur (x,y) sachant que l'axe -y est dirigé vers le bas et l'axe -x vers la droite
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (pas < 5)
			d_sprite.setTexture(d_texture_left);
		else if (pas < 10)
			d_sprite.setTexture(d_texture_left_1);
		else if (pas < 15)
			d_sprite.setTexture(d_texture_left);
		else if (pas < 20)
			d_sprite.setTexture(d_texture_left_2);
		if (!collision[0])
			d_sprite.move(x * (-2), x * 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (pas < 5)
			d_sprite.setTexture(d_texture_right);
		else if (pas < 10)
			d_sprite.setTexture(d_texture_right_1);
		else if (pas < 15)
			d_sprite.setTexture(d_texture_right);
		else if (pas < 20)
			d_sprite.setTexture(d_texture_right_2);
		if (!collision[1])
			d_sprite.move(x * 2, x * 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (pas < 5)
			d_sprite.setTexture(d_texture_up);
		else if (pas < 10)
			d_sprite.setTexture(d_texture_up_1);
		else if (pas < 15)
			d_sprite.setTexture(d_texture_up);
		else if (pas < 20)
			d_sprite.setTexture(d_texture_up_2);
		if (!collision[2])
			d_sprite.move(x * 0, x * (-2));
	}

}
//retoure le pokémon de l'équipe à la position donné en paramètre
Pokemonstock Dresseur::d_getPokemonEquipe(int n)
{
	return d_equipe[n];
}
//retoure le pokémon de la boite à la position donné en paramètre
Pokemonstock Dresseur::d_getPokemonBoite(int n)
{
	return d_boite[n];
}
//soigner tout les pokémons de l'équipe, et les mettre à jour dans la base de données
void Dresseur::d_healequipe()
{
	for (int i = 0; i < d_equipe.size(); i++)
	{
		d_equipe[i].ps_heal();
		//faire l'update dans la db
		d_equipe[i].ps_updateDansDB(d_idEquipe);
	}

}
//récupérer l'id du dresseur
int Dresseur::d_getId()
{
	return d_id;
}
//récupérer le nom du dresseur
std::string Dresseur:: d_getNom()
{
	return d_nom;
}
//récupérer l'id de la boite du dresseur (de la base de données)
int Dresseur::d_getIDBoite()
{
	return d_idBoite;
}
//récupérer l'id de l'équipe du dresseur (de la base de données)
int Dresseur::d_getIDEquipe()
{
	return d_idEquipe;
}
//changer l'id de la boite du dresseur (servait pour des tests)
void Dresseur::d_setIDBoite(int idboite)
{
	d_idBoite = idboite;
}
//changer l'id de l'équipe du dresseur (servait pour des tests)
void Dresseur::d_setIDEquipe(int idequipe)
{
	d_idEquipe = idequipe;
}
//rend un vecteur contenant la position des pokémons pas ko
//on se servira en général que de la première position
std::vector<int> Dresseur::d_getPokePasKO() {
	std::vector<int>pasKO;
	pasKO.clear();
	int i = 0;
	for (std::vector<Pokemonstock>::iterator it = d_equipe.begin(); it != d_equipe.end(); it++)
	{
		if (it->ps_getpvrestant() > 0)
		{
			pasKO.push_back(i);
			//std::cout << "je boucle une fois"<<std::endl;
		}
		i++;
	}
	return pasKO;
}
//récupérer la taille de l'équipe
int Dresseur::d_getSizeEquipe() {
	return d_equipe.size();
}
//récupérer la taille de la boite
int Dresseur::d_getSizeBoite() {
	return d_boite.size();
}
//après un combat, on utilise cette fonction pour mettre le pokémon à jour, aussi bien dans le code que dans la base de données
void Dresseur::d_setPokemonEquipe(Pokemoncombat lepoke, int pos) {
	/*je remet mon pokemon dans l'équipe + maj dans la db !*/
	d_equipe[pos] = lepoke;
	//declencher maj dans DB
	d_equipe[pos].ps_updateDansDB(d_idEquipe);
}