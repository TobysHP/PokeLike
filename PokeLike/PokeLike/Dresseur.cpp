#include "Dresseur.h"

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


Dresseur::~Dresseur()
{
}

void Dresseur::update(std::vector<bool> collision, int pas, float x)//Définition de la fonction update (qui est maintenant une fonction  membre de la classe "Dresseur")
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

Pokemonstock Dresseur::d_getpokemon(int n)
{
	return d_equipe[n];
}
Pokemonstock Dresseur::d_getequipe()
{
	return *d_equipe;
}
void Dresseur::healequipe()
{
	for (int i = 0; i < 6; i++)
	{
		d_equipe[i].ps_heal();
	}
}