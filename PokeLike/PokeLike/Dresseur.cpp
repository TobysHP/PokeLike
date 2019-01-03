#pragma once
#include "Dresseur.h"

//constructeur par d�faut
Dresseur::Dresseur()
{

}
//construit un dresseur (juste les sprites charg�), a surtout servi pour les tests
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
//param�tre x : facteur graphique
//param�tre idDresseur : l'id du dresseur � construire
//param�tre nomDresseur : le nom du dresseur
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
//D�finition de la fonction update, qui permet de bouger le dresseur
void Dresseur::update(std::vector<bool> collision, int pas, float x)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) // V�rifie si la fl�che "Down" du clavier est appuy�
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
			d_sprite.move(x * 0, x * 2);// Dans le cas ou la condition du "if" est v�rifi�e La fonction "move" d�place le sprite selon le vecteur (x,y) sachant que l'axe -y est dirig� vers le bas et l'axe -x vers la droite
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
//retoure le pok�mon de l'�quipe � la position donn� en param�tre
Pokemonstock Dresseur::d_getPokemonEquipe(int n)
{
	return d_equipe[n];
}
//retoure le pok�mon de la boite � la position donn� en param�tre
Pokemonstock Dresseur::d_getPokemonBoite(int n)
{
	return d_boite[n];
}
//soigner tout les pok�mons de l'�quipe, et les mettre � jour dans la base de donn�es
void Dresseur::d_healequipe()
{
	for (int i = 0; i < d_equipe.size(); i++)
	{
		d_equipe[i].ps_heal();
		//faire l'update dans la db
		d_equipe[i].ps_updateDansDB(d_idEquipe);
	}

}
//r�cup�rer l'id du dresseur
int Dresseur::d_getId()
{
	return d_id;
}
//r�cup�rer le nom du dresseur
std::string Dresseur:: d_getNom()
{
	return d_nom;
}
//r�cup�rer l'id de la boite du dresseur (de la base de donn�es)
int Dresseur::d_getIDBoite()
{
	return d_idBoite;
}
//r�cup�rer l'id de l'�quipe du dresseur (de la base de donn�es)
int Dresseur::d_getIDEquipe()
{
	return d_idEquipe;
}
//changer l'id de la boite du dresseur (servait pour des tests)
void Dresseur::d_setIDBoite(int idboite)
{
	d_idBoite = idboite;
}
//changer l'id de l'�quipe du dresseur (servait pour des tests)
void Dresseur::d_setIDEquipe(int idequipe)
{
	d_idEquipe = idequipe;
}
//rend un vecteur contenant la position des pok�mons pas ko
//on se servira en g�n�ral que de la premi�re position
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
//r�cup�rer la taille de l'�quipe
int Dresseur::d_getSizeEquipe() {
	return d_equipe.size();
}
//r�cup�rer la taille de la boite
int Dresseur::d_getSizeBoite() {
	return d_boite.size();
}
//apr�s un combat, on utilise cette fonction pour mettre le pok�mon � jour, aussi bien dans le code que dans la base de donn�es
void Dresseur::d_setPokemonEquipe(Pokemoncombat lepoke, int pos) {
	/*je remet mon pokemon dans l'�quipe + maj dans la db !*/
	d_equipe[pos] = lepoke;
	//declencher maj dans DB
	d_equipe[pos].ps_updateDansDB(d_idEquipe);
}