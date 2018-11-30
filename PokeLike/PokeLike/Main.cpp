#include "Dresseur.h"
#include "Fonctions.h"
#include "fctsql.h"
#include "Pokemon.h"
#include "Pokemonstock.h"
#include "Pokemoncombat.h"
#include "Combat.h"
#include <chrono>
#include <thread>
#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

//https://www.youtube.com/watch?v=1g_Xng_uH2w&t=364s //le dieu italien :O 


//main
//int const sizemot = 20;

int main() {
	//creerDresseurEtBoite();//marche bien
	//std::vector<Pokemon> lePokedex=chargerLePokedex();
	Dresseur monDresseur = chargerDresseur(1, 0.75);
	monDresseur.d_chargerEquipe();
	system("pause");
	return 0;
}

int pasmain()
{
	float x = 0.75; // facteur graphique
	sf::RenderWindow maFenetre(sf::VideoMode(x * 1200, x * 1200), "PokeLike");
	maFenetre.setFramerateLimit(60);// nombre de frames par seconde
	std::vector<Pokemon> Pokedex;
	//chargerLePokedex(Pokedex);
	Dresseur dres(x);
	int pas = 0;

	std::chrono::milliseconds dura(150);

	// setup de la carte
	sf::Sprite background_sprite;
	sf::Texture background;
	background.loadFromFile("Sprite/background2.png", sf::IntRect(0, 0, 1200, 1200));
	background_sprite.setScale(x, x);
	background_sprite.setTexture(background);
	// gestions des hautes herbes
	sf::FloatRect hauteHerbes1(x * 160, x * 80, x * 280, x * 360); //hh en haut à gauche
	sf::FloatRect hauteHerbes2(x * 360, x * 640, x * 160, x * 200); //hh au milieu
	sf::FloatRect hauteHerbes3(x * 680, x * 760, x * 360, x * 240); //hh en bas à droite
	sf::FloatRect hauteHerbes4(x * 880, x * 1000, x * 160, x * 80);
	sf::FloatRect hauteHerbes5(x * 560, x * 1080, x * 480, x * 40);
	// gestion des collisions
	sf::FloatRect mur1(x * 0, x * 0, x * 80, x * 1200); // ligne d'arbres à gauche
	sf::FloatRect mur2(x * 80, x * 0, x * 80, x * 376); // arbres à gauche des hh en haut
	sf::FloatRect mur3(x * 80, x * 560, x * 200, x * 360); // partie haute du lac bas
	sf::FloatRect mur4(x * 280, x * 560, x * 80, x * 216); // 3 arbres à droite du lac bas
	sf::FloatRect mur5(x * 260, x * 920, x * 220, x * 80); // partie basse du lac bas
	sf::FloatRect mur6(x * 480, x * 960, x * 80, x * 160); // 2 arbes en bas à droite du lac bas
	sf::FloatRect mur7(x * 560, x * 1120, x * 640, x * 80); // ligne d'arbres en bas des hh à droite
	sf::FloatRect mur8(x * 1040, x * 800, x * 160, x * 400); // ligne d'arbres à droite des hh
	sf::FloatRect mur9(x * 1120, x * 0, x * 80, x * 1200); // ligne d'arbres à droites
	sf::FloatRect mur10(x * 760, x * 330, x * 280, x * 6); // lac haut
	sf::FloatRect mur11(x * 1040, x * 0, x * 80, x * 420); // arbres à droite du lac haut
	sf::FloatRect mur12(x * 720, x * 300, x * 40, x * 76); // aie à droite de l'arène 
	sf::FloatRect mur13(x * 440, x * 0, x * 40, x * 376); // aie à gauche de l'arène
	sf::FloatRect mur14(x * 0, x * 0, x * 440, x * 56); // arbres en haut des hh haut
	sf::FloatRect arena(x * 480, x * (-100), x * 240, x * 416); // arène
	sf::FloatRect hopital(x * 760, x * 600, x * 160, x * 56); // pokestop
	sf::FloatRect shop(x * 960, x * 440, x * 160, x * 56); // pokeshop
	//setup batiments
	sf::Sprite pokestop_sprite;
	sf::Texture pokestop;
	pokestop.loadFromFile("Sprite/pokestop.png", sf::IntRect(0, 0, 162, 154));
	pokestop_sprite.setTexture(pokestop);
	pokestop_sprite.setPosition(x * 759, x * 521);
	pokestop_sprite.setScale(x, x);
	sf::Sprite pokeshop_sprite;
	sf::Texture pokeshop;
	pokeshop.loadFromFile("Sprite/pokeshop.png", sf::IntRect(0, 0, 176, 145));
	pokeshop_sprite.setTexture(pokeshop);
	pokeshop_sprite.setPosition(x * 945, x * 372);
	pokeshop_sprite.setScale(x, x);



	// setup de la zone de combat
	sf::Sprite backcombat_sprite;
	sf::Texture backcombat;
	backcombat.loadFromFile("Sprite/arene.png", sf::IntRect(0, 0, 1200, 1200));
	backcombat_sprite.setTexture(backcombat);
	backcombat_sprite.setScale(x, x);

	// setup d'une pokeball
	sf::Sprite pokeball_sprite;
	sf::Texture pokeball;
	pokeball.loadFromFile("Sprite/all_pokeballs.png", sf::IntRect(168, 4, 19, 32));
	pokeball_sprite.setTexture(pokeball);
	pokeball_sprite.setScale(x, x);
	int anim_poke = 0;

	// setup des menus

	sf::Sprite menu_sprite;

	sf::Texture p1;
	p1.loadFromFile("Sprite/menu1_purple.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture b1;
	b1.loadFromFile("Sprite/menu1_blue.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture g1;
	g1.loadFromFile("Sprite/menu1_green.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture y1;
	y1.loadFromFile("Sprite/menu1_yellow.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture o1;
	o1.loadFromFile("Sprite/menu1_orange.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture r1;
	r1.loadFromFile("Sprite/menu1_red.png", sf::IntRect(0, 0, 1200, 1200));

	sf::Texture p2;
	p2.loadFromFile("Sprite/menu2_purple.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture b2;
	b2.loadFromFile("Sprite/menu2_blue.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture g2;
	g2.loadFromFile("Sprite/menu2_green.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture y2;
	y2.loadFromFile("Sprite/menu2_yellow.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture o2;
	o2.loadFromFile("Sprite/menu2_orange.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture r2;
	r2.loadFromFile("Sprite/menu2_red.png", sf::IntRect(0, 0, 1200, 1200));


	while (maFenetre.isOpen()) // première boucle
	{
		bool endmap = 1;
		bool endcombat = 0;
		bool capture = 0;
		maFenetre.clear();

		bool boo = true;
		int compt = 0;
		bool option = 0;
		while (boo) {
			//maFenetre.clear();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				option = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				option = 0;
			}

			if (compt < 10) {
				if (option) menu_sprite.setTexture(p1);
				else menu_sprite.setTexture(p2);
			}
			if (compt >= 20 && compt < 30) {
				if (option) menu_sprite.setTexture(b1);
				else menu_sprite.setTexture(b2);
			}
			if (compt >= 30 && compt < 40) {
				if (option) menu_sprite.setTexture(g1);
				else menu_sprite.setTexture(g2);
			}
			if (compt >= 40 && compt < 50) {
				if (option) menu_sprite.setTexture(y1);
				else menu_sprite.setTexture(y2);
			}
			if (compt >= 50 && compt < 60) {
				if (option) menu_sprite.setTexture(o1);
				else menu_sprite.setTexture(o2);
			}
			if (compt >= 60 && compt < 70) {
				if (option) menu_sprite.setTexture(r1);
				else menu_sprite.setTexture(r2);
			}
			if (compt == 70) compt = 0;
			compt++;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return 0;//ainsi l'utilsateur sait fermer le jeu depuis le jeu
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)&&option==1) boo = false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && option == 0)
			{
				std::cout << "selection dresseur" << std::endl;
				std::string tableauDesNoms[4];
				int tableauDesId[4];
				for (int i = 0; i < 4; i++)
				{
					tableauDesNoms[i] = "pas de dresseur";
					tableauDesId[i] = 0;
					std::cout << tableauDesNoms[i] << std::endl;//a supprimer ou comemtner c'est pour moi test
				}
				//charger les noms des dresseurs
				chargerIdsNomsDresseurs(tableauDesId,tableauDesNoms);//charger les noms des dresseurs
				std::cout << "retour dans le main, j'affiche mes noms" << std::endl;
				for (int i = 0; i < 4; i++)
				{
					std::cout <<"id : "<<tableauDesId[i]<<"\tnom : "<< tableauDesNoms[i] << std::endl;
				}
				/*std::cout << "veuillez sélectionner le dresseur à charger" << std::endl;
				int choix = 0;
				while (choix < 1 || choix>4)
				{
					std::cin >> choix;
				}
				choix--;
				Dresseur monDresseur=Dresseur(x, tableauDesId[choix], tableauDesNoms[choix]);*/
				//creerDresseurEtBoite();
				boo = false;
			}
			menu_sprite.setScale(x, x);

			maFenetre.draw(menu_sprite);

			maFenetre.display();
		}

		while (endmap) { // boucle liée à la map

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;
			std::vector<bool> detectcoll;
			// appel de la fonction membre "update" pour faire bouger l'objet
			/////ici

			for (int i = 0; i < 4; i++) { // on regarde dans chaques directions
				if (Collision(dres.d_sprite.getGlobalBounds(), mur1)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur2)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur3)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur4)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur5)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur6)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur7)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur8)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur9)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur10)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur11)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur12)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur13)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur14)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), arena)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), hopital)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), shop)[i]
					)
					detectcoll.push_back(1);
				else
					detectcoll.push_back(0);
			}

			// on actualise
			dres.update(detectcoll, pas, x);

			//adapter la fonction draw
			////ici
			maFenetre.draw(background_sprite); //pour la map
			maFenetre.draw(dres.d_sprite); //pour le dresseur
			maFenetre.draw(pokestop_sprite); //pour la supperposition
			maFenetre.draw(pokeshop_sprite);


			if ((dres.d_sprite.getGlobalBounds().intersects(hauteHerbes1)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes2)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes3)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes4)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes5))
				& (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)
					|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
					|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
					|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
			{
				int x = rand() % 100;
				if (x == 8) {
					endmap = 0;
					endcombat = 1;
				}
			}
			pas++;
			if (pas == 20)
				pas = 0;

			std::cout << "0";
			maFenetre.display();
		} // fin boucle map

		if (endcombat)
		{
			//boucle pierre, faudra qu'on combine le tout
			//int nmax = 17;
			//int selection = 0;//1 = combat, 2 : ball,  3 switch, 4 fuite
			int attaquejoueur = 4;//vaudra0,1,2 ou 3 pour se balader dans le tableau des attaques du pkmn du dresseur
			//bool fuite = false;
			bool switchp = false;
			int nombre;
			bool win = false;
			int i = 0;
			bool okdecontinuer = true;
			float matricecoef[17][17] = { { 1,1,1,1,1,1,2,1,1,1,1,1,1,0,1,1,1 },
			{ 1,0.5,2,0.5,1,0.5,1,1,2,1,1,0.5,2,1,1,1,0.5 },
			{ 1,0.5,0.5,2,2,0.5,1,1,1,1,1,1,1,1,1,1,0.5 },
			{ 1,2,0.5,0.5,0.5,2,1,2,0.5,2,1,2,1,1,1,1,1 },
			{ 1,1,1,1,0.5,1,1,1,2,0.5,1,1,1,1,1,1,1 },
			{ 1,2,1,1,1,0.5,2,1,1,1,1,1,2,1,1,1,2 },
			{ 1,1,1,1,1,1,1,1,1,2,2,0.5,0.5,1,1,0.5,1 },
			{ 1,1,1,0.5,1,1,0.5,0.5,2,1,2,0.5,1,1,1,1,1 },
			{ 1,1,2,2,0,2,1,0.5,1,1,1,1,0.5,1,1,1,1 },
			{ 1,1,1,0.5,2,2,0.5,1,0,1,1,0.5,2,1,1,1,1 },
			{ 1,1,1,1,1,1,0.5,1,1,1,0.5,2,1,2,1,2,1 },
			{ 1,2,1,0.5,1,1,0.5,1,0.5,2,1,1,2,1,1,1,1 },
			{ 0.5,0.5,2,2,1,1,2,0.5,2,0.5,1,1,1,1,1,1,2 },
			{ 0,1,1,1,1,1,0,0.5,1,1,1,0.5,1,2,1,2,1 },
			{ 1,0.5,0.5,0.5,0.5,2,1,1,1,1,1,1,1,1,2,1,1 },
			{ 1,1,1,1,1,1,2,1,1,1,0,2,1,0.5,1,0.5,1 },
			{ 0.5,2,1,0.5,1,0.5,2,0,2,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5 } };

			/*while (dres.d_getpokemon(i).ps_getpvrestant() == 0)//faudra s'assurer que quand tout les pkmn du dress sont ko, c'est game over et pokecentre instant
			{
				i++;
			}*/


			// mon poke
			Pokemoncombat mon_pokemon = Pokemoncombat(dres.d_getPokemonEquipe(i));
			/*std::string nom = "Pikachu";
			int tab[4] = { 0,0, 131, 138 };
			Pokemon mon_pokemon;//(nom, tab);
			mon_pokemon.p_sprite.setPosition(326, 409);*/

			// poke sauvage
			Pokemoncombat pokemon_sauvage = Pokemoncombat(dres.d_getPokemonEquipe(i + 1));
			/*std::string nom2 = "Goten";
			int tab2[4] = { 0,0, 109, 142 };
			Pokemon pokemon_sauvage;// (nom2, tab2);
			pokemon_sauvage.p_sprite.setPosition(763, 390);*/

			// interface combat selection
			sf::Sprite combat_selection_sprite;
			sf::Texture combat_selection;
			combat_selection.loadFromFile("Sprite/combat_selection.png", sf::IntRect(0, 0, 600, 242));
			combat_selection_sprite.setTexture(combat_selection);
			combat_selection_sprite.setPosition(x * 600, x * 958);
			combat_selection_sprite.setScale(x, x);

			// interface attaque
			sf::Sprite combat_attaque_sprite;
			sf::Texture combat_attaque;
			combat_attaque.loadFromFile("Sprite/menu_combat_attaques.png", sf::IntRect(0, 0, 600, 242));
			combat_attaque_sprite.setTexture(combat_attaque);
			combat_attaque_sprite.setPosition(x * 600, x * 958);
			combat_attaque_sprite.setScale(x, x);
			bool attaque = 0;

			// flèche de sélection
			float xa, ya;
			sf::Sprite arrow_sprite;
			sf::Texture arrow;
			arrow.loadFromFile("Sprite/arrow.png", sf::IntRect(0, 0, 17, 66));
			arrow_sprite.setTexture(arrow);
			arrow_sprite.setScale(x, x);
			std::vector<bool> arrow_tab = { 0,0 };

			// attaques
			sf::String atttext = "CHAR";
			sf::Font font;
			if (!font.loadFromFile("arial.ttf"))
			{
				std::cout << "ERROR" << std::endl;
			}

			sf::String att1text;
			sf::Text att1(att1text, font, x * 50);
			sf::String att2text;
			sf::Text att2(att2text, font, x * 50);
			sf::String att3text;
			sf::Text att3(att3text, font, x * 50);
			sf::String att4text;
			sf::Text att4(att4text, font, x * 50);
			att1.setFillColor(sf::Color::Black);
			att2.setFillColor(sf::Color::Black);
			att3.setFillColor(sf::Color::Black);
			att4.setFillColor(sf::Color::Black);

			// barres de vies
			sf::RectangleShape bdv1(sf::Vector2f(x * 470, x * 79));
			sf::RectangleShape bdv2(sf::Vector2f(x * 470, x * 79));
			bdv1.setPosition(x * 67, x * 150);
			bdv2.setPosition(x * 665, x * 150);
			bdv1.setFillColor(sf::Color::Red);
			bdv2.setFillColor(sf::Color::Red);

			while (endcombat) { // boucle lié à un combat
				maFenetre.display();

				maFenetre.draw(backcombat_sprite); //pour l'arene
				maFenetre.draw(pokemon_sauvage.p_getsprite());
				maFenetre.draw(mon_pokemon.p_getsprite());
				maFenetre.draw(combat_selection_sprite);
				maFenetre.draw(bdv1);
				maFenetre.draw(bdv2);
				// on regarde la sélection
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
					arrow_tab[0] = 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
					arrow_tab[0] = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
					arrow_tab[1] = 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
					arrow_tab[1] = 0;
				}

				// on dessine la flèche de sélection au bon endroit

				if (arrow_tab[0])
					xa = 1107;
				else
					xa = 986;
				if (arrow_tab[1])
					ya = 912;
				else
					ya = 610;
				arrow_sprite.setPosition(x*ya, x*xa);
				maFenetre.draw(arrow_sprite);


				// si on appuie sur enter

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && attaque == 0 && capture == 0) {
					if (arrow_tab[0] && arrow_tab[1]) // si on est sur fuite
						endcombat = 0;

					if (!arrow_tab[0] && arrow_tab[1]) // si on est sur capturer
						capture = 1;

					if (!arrow_tab[0] && !arrow_tab[1]) // si on est sur attaquer
					{
						attaque = 1;
						capture = 0;

						//att1text = mon_pokemon.p_getnomattaques[0];
						sf::String att1text;
						att1text = "CHARGE";
						att1.setString(att1text);
						if (att1text.getSize() <= 6) {
							att1.setPosition(x*(635 + 25 * (6 - att1text.getSize())), x * 985);
						}
						if (att1text.getSize() > 6) {
							att1.setPosition(x * 635, x * (985 + 3.5*(att1text.getSize() - 6)));
							att1.setCharacterSize(x * 300 / att1text.getSize());
						}

						//att2text = mon_pokemon.p_getnomattaques[1];
						att2text = "RUGISSEMENT";
						att2.setString(att2text);
						if (att2text.getSize() <= 6) {
							att2.setPosition(x * (950 + 25 * (6 - att2text.getSize())), x * 985);
						}
						if (att2text.getSize() > 6) {
							att2.setPosition(x * 950, x * (985 + 3.5*(att2text.getSize() - 6)));
							att2.setCharacterSize(x * 300 / att2text.getSize());
						}

						//att3text = mon_pokemon.p_getnomattaques[2];
						att3text = "SURF";
						att3.setString(att3text);
						if (att3text.getSize() <= 6) {
							att3.setPosition(x * 635 + x * 25 * (6 - att3text.getSize()), x * 1105);
						}
						if (att3text.getSize() > 6) {
							att3.setPosition(x * 635, x * 1105 + x * 3.5*(att3text.getSize() - 6));
							att3.setCharacterSize(x * 300 / att3text.getSize());
						}

						//att4text = mon_pokemon.p_getnomattaques[3];
						att4text = "BITE";
						att4.setString(att4text);
						if (att4text.getSize() <= 6) {
							att4.setPosition(x * 950 + x * 25 * (6 - att4text.getSize()), x * 1105);
						}
						if (att1text.getSize() > 6) {
							att4.setPosition(x * 950, x * 1105 + x * 3.5*(att4text.getSize() - 6));
							att4.setCharacterSize(x * 300 / att4text.getSize());
						}
						while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) { std::cout << 2; }
					}

					if (arrow_tab[0] && !arrow_tab[1]) // si on est sur équipe
					{
					}
				}
				if (capture) {
					if (anim_poke <= 71) {
						pokeball_sprite.setPosition(x * 800, x * 238 + x * 4 * anim_poke);
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 77) {
						pokeball_sprite.setPosition(x * 800, x * 238 + x * 288 - x * 3 * (anim_poke - 72));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 83) {
						pokeball_sprite.setPosition(x * 800, x * 238 + x * 511 - x * 2 * (anim_poke - 77));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 90) {
						pokeball_sprite.setPosition(x * 800, x * 238 + x * 499 - x * 1 * (anim_poke - 83));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke >= 90) {
						anim_poke = 0;
						capture = 0;
					}
				}
				if (attaque) {
					maFenetre.draw(combat_attaque_sprite);
					maFenetre.draw(att1);
					maFenetre.draw(att2);
					maFenetre.draw(att3);
					maFenetre.draw(att4);
					maFenetre.draw(arrow_sprite);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
						attaque = 0;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
						if (arrow_tab[0] && arrow_tab[1]) // si on est sur ATT 4
							attaquejoueur = 3;
						if (!arrow_tab[0] && arrow_tab[1]) // si on est sur ATT 2
							attaquejoueur = 1;
						if (!arrow_tab[0] && !arrow_tab[1]) // si on est sur ATT 1
							attaquejoueur = 0;
						if (arrow_tab[0] && !arrow_tab[1]) // si on est sur ATT 3
							attaquejoueur = 2;
					}
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}
					if (attaquejoueur < 4) {
						std::cout << "-----" << attaquejoueur << std::endl;
						if (mon_pokemon.pc_getvitcombat() > pokemon_sauvage.pc_getvitcombat())//mon pokemon attaque donc en premier
						{
							deroulementattaque(mon_pokemon, pokemon_sauvage, attaquejoueur, matricecoef);//degats s'infligent
							bdv2.setSize(sf::Vector2f((pokemon_sauvage.ps_getpvrestant() / pokemon_sauvage.p_getpvmax()) * 470, 150));
							if (pokemon_sauvage.ps_getpvrestant() == 0)
							{
								std::cout << "Pokemon vaincu !" << std::endl;
								win = true;
								//le pokemon qui s'est battu gagne des points dépendant des evs de la cible vaincue
								endcombat = false;
							}
							//si encore en vie, l'autre pokémon contre attaque ! 
							nombre = (rand() % 4);//l'autre pokémon doit sélectionner une attaque
							deroulementattaque(pokemon_sauvage, mon_pokemon, nombre, matricecoef);
							if (mon_pokemon.ps_getpvrestant() == 0)//créer un attribut + méthode pv actuel dans pokemon//donc mnt si il est ko le combat s'arrête ! 
							{
								std::cout << "Mon Pokémon ko !" << std::endl;
								for (int c = 0; i < 6; i++)
								{
									if (dres.d_getPokemonEquipe(c).ps_getpvrestant() == 0)
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
									dres.d_getPokemonEquipe(i).ps_fincombat(mon_pokemon, pokemon_sauvage, win);
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
						else//meme boucle de dégats à l'envers, c'est donc le pokémon sauvage le plus rapide
						{
							nombre = (rand() % 4);//l'autre pokémon doit sélectionner une attaque
							deroulementattaque(pokemon_sauvage, mon_pokemon, nombre, matricecoef);//degats s'infligent
							if (mon_pokemon.ps_getpvrestant() == 0)//créer un attribut + méthode pv actuel dans pokemon//donc mnt si il est ko le combat s'arrête ! 
							{
								std::cout << "Mon Pokémon ko !" << std::endl;
								for (int c = 0; i < 6; i++)
								{
									if (dres.d_getPokemonEquipe(c).ps_getpvrestant() == 0)
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
									dres.d_getPokemonEquipe(i).ps_fincombat(mon_pokemon, pokemon_sauvage, win);
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
							//çà va avoir un comportement bizzare çà, à fix ! 
							//si encore en vie, l'autre pokémon contre attaque ! 
							deroulementattaque(mon_pokemon, pokemon_sauvage, attaquejoueur, matricecoef);
							if (pokemon_sauvage.ps_getpvrestant() == 0)
							{
								std::cout << "Pokemon vaincu !" << std::endl;
								win = true;
								//le pokemon qui s'est battu gagne des points dépendant des evs de la cible vaincue
								endcombat = false;
							}
						}
						attaque = false;
						attaquejoueur = 4;
					}
				}
				std::cout << "1";
			}
		}
	}

	// appel du destructeur
	/////ici
	dres.~Dresseur();
	return 0;
}