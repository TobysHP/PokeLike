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

int main()
{
	float x = 1.5; // facteur graphique
	sf::RenderWindow maFenetre(sf::VideoMode(x * 1200, x * 1200), "PokeLike", sf::Style::Default);
	maFenetre.setFramerateLimit(60);// nombre de frames par seconde

									//instantiation d'un objet qui appartient à la classe Warrior
									/////////ici
	Dresseur dres/*(x)*/;
	int pas = 0;
	bool boo = TRUE;
	bool selectData = 1;


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
	sf::FloatRect mur_centre_1(x * 550, x * 390, x * 10, x * 290); // murs interne pokecentre
	sf::FloatRect mur_centre_2(x * 560, x * 380, x * 440, x * 10); // murs interne pokecentre
	sf::FloatRect mur_centre_2bis(x * 1000, x * 360, x * 120, x * 10); // murs interne pokecentre
	sf::FloatRect mur_centre_2bisbis(x * 990, x * 360, x * 10, x * 20); // murs interne pokecentre
	sf::FloatRect mur_centre_3(x * 560, x * 680, x * 560, x * 100); // murs interne pokecentre
	sf::FloatRect mur_centre_4(x * 1120, x * 390, x * 10, x * 290); // murs interne pokecentre
	sf::FloatRect mur_centre_5(x * 720, x * 360, x * 240, x * 100); // murs interne pokecentre
	sf::FloatRect mur_centre_table(x * 1000, x * 560, x * 80, x * 52); // murs interne pokecentre
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
	sf::FloatRect porte_enter(x * 800, x * 630, x * 40, x * 30);
	sf::FloatRect porte_out(x * 800, x * 680, x * 80, x * 20);
	sf::FloatRect computer_zone(x * 960, x * 380, x * 40, x * 40);



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
	pokeball_sprite.setScale(2 * x, 2 * x);
	int anim_poke = 0;

	// setup du centre
	sf::Sprite centre_sprite;
	sf::Texture centre;
	centre.loadFromFile("Sprite/centre_inter.png", sf::IntRect(0, 0, 1200, 1200));
	centre_sprite.setTexture(centre);
	centre_sprite.setScale(x, x);

	// setup d'un fond noir
	sf::Sprite sortBackSprite;
	sf::Texture sortBackTexture;
	sortBackTexture.loadFromFile("Sprite/new_saisie.png");
	sortBackSprite.setTexture(sortBackTexture);
	sortBackSprite.setScale(x, x);

	sf::RectangleShape blackScreen;
	blackScreen.setSize(sf::Vector2f(x * 1200, x * 1200));
	blackScreen.setPosition(0, 0);
	blackScreen.setFillColor(sf::Color::Black);
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


	// setup des boites/equipes

	sf::Sprite computer_sprite;
	sf::Texture computer_equipe;
	computer_equipe.loadFromFile("Sprite/menu_equipe.png", sf::IntRect(0, 0, 1200, 1200));
	sf::Texture computer_boite;
	computer_boite.loadFromFile("Sprite/menu_boite.png", sf::IntRect(0, 0, 1200, 1200));
	computer_sprite.setTexture(computer_equipe);

	sf::Sprite equipe_sprite;
	sf::Texture equipe_texture;
	equipe_texture.loadFromFile("Sprite/equipe.png");
	equipe_sprite.setTexture(equipe_texture);

	sf::Sprite poke_info_sprite;
	sf::Texture poke_info_texture;
	poke_info_texture.loadFromFile("Sprite/poke_info_boite.png");
	poke_info_sprite.setTexture(poke_info_texture);

	computer_sprite.setScale(x, x);
	equipe_sprite.setScale(x, x);
	poke_info_sprite.setScale(x, x);

	sf::Sprite newProfileSprite;
	sf::Texture newProfileTexture;
	newProfileTexture.loadFromFile("Sprite/new_saisie.png");
	newProfileSprite.setTexture(newProfileTexture);

	// setup de panneau de sauvegarde


	while (maFenetre.isOpen()) // première boucle
	{
		sf::Event event;
		int tableauDesId[4];
		std::string tableauDesNoms[4];
		bool profilIsCreated[4];
		chargerIdsNomsDresseurs(tableauDesId, tableauDesNoms);

		sf::Sprite save_board_sprite;
		sf::Texture save_board;
		save_board.loadFromFile("Sprite/save_board.png");
		save_board_sprite.setTexture(save_board);
		save_board_sprite.setScale(x, x);

		sf::Sprite save_select_sprite;
		sf::Texture save_select;
		save_select.loadFromFile("Sprite/save_selection.png");
		save_select_sprite.setTexture(save_select);
		save_select_sprite.setScale(x, x);
		int xsave_select = 0;
		int ysave_select = 0;
		bool save_select_tab[] = { 0,0 };

		sf::Font fontSave;
		if (!fontSave.loadFromFile("Century Gothic.ttf"))
		{
			std::cout << "ERROR" << std::endl;
		}


		sf::String save1text;
		sf::Text save1(save1text, fontSave, x * 50);
		sf::String save2text;
		sf::Text save2(save2text, fontSave, x * 50);
		sf::String save3text;
		sf::Text save3(save3text, fontSave, x * 50);
		sf::String save4text;
		sf::Text save4(save4text, fontSave, x * 50);
		save1.setFillColor(sf::Color::White);
		save2.setFillColor(sf::Color::White);
		save3.setFillColor(sf::Color::White);
		save4.setFillColor(sf::Color::White);

		//bool boo = TRUE;
		bool endmap = TRUE;
		bool endcombat = FALSE;
		bool pokecentre_scene = FALSE;
		bool capture = FALSE;
		maFenetre.clear();

		//bool boo = TRUE;
		int compt = 0;
		bool option = 0;
		bool play = 1;
		//selectData = 1;
		while (boo) {
			//maFenetre.clear();
			selectData = true;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				option = 1; // play
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				//option = 0; // option
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) boo = FALSE;

			menu_sprite.setScale(x, x);

			maFenetre.draw(menu_sprite);

			maFenetre.display();
		}

		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}

		if (tableauDesNoms[0] != "") {
			save1text = tableauDesNoms[0] + "\n" + sf::String(std::to_string(tableauDesId[0]));
			save1.setString(save1text);
			save1.setPosition(x*168.5, x * 286);
			profilIsCreated[0] = true;
		}
		else {
			save1text = "new part";
			save1.setString(save1text);
			save1.setPosition(x*168.5, x * 286);
			profilIsCreated[0] = false;
		}

		if (tableauDesNoms[1] != "") {
			save2text = tableauDesNoms[1] + "\n" + sf::String(std::to_string(tableauDesId[1]));
			save2.setString(save2text);
			save2.setPosition(x*653.5, x * 286);
			profilIsCreated[1] = true;
		}
		else {
			save2text = "new part";
			save2.setString(save2text);
			save2.setPosition(x*653.5, x * 286);
			profilIsCreated[1] = false;
		}

		if (tableauDesNoms[2] != "") {
			save3text = tableauDesNoms[2] + "\n" + sf::String(std::to_string(tableauDesId[2]));
			save3.setString(save3text);
			save3.setPosition(x*168.5, x * 772);
			profilIsCreated[2] = true;
		}
		else {
			save3text = "new part";
			save3.setString(save3text);
			save3.setPosition(x*168.5, x * 772);
			profilIsCreated[2] = false;
		}

		if (tableauDesNoms[3] != "") {
			save4text = tableauDesNoms[3] + "\n" + sf::String(std::to_string(tableauDesId[3]));
			save4.setString(save4text);
			save4.setPosition(x*653.5, x * 772);
			profilIsCreated[3] = true;
		}
		else {
			save4text = "new part";
			save4.setString(save4text);
			save4.setPosition(x*653.5, x * 772);
			profilIsCreated[3] = false;
		}

		while (selectData) {
			maFenetre.display();
			maFenetre.draw(save_board_sprite);

			maFenetre.draw(save1);
			maFenetre.draw(save2);
			maFenetre.draw(save3);
			maFenetre.draw(save4);


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				save_select_tab[0] = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				save_select_tab[0] = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
				save_select_tab[1] = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
				save_select_tab[1] = 0;
			}


			// on dessine la séléction de sélection au bon endroit

			if (!save_select_tab[0])
				xsave_select = 130;
			else
				xsave_select = 616;
			if (!save_select_tab[1])
				ysave_select = 130;
			else
				ysave_select = 616;
			save_select_sprite.setPosition(x*ysave_select, x*xsave_select);
			maFenetre.draw(save_select_sprite);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
				selectData = 0;
				if (save_select_tab[0] && save_select_tab[1]) {
					if (profilIsCreated[3])
						dres = chargerDresseur(tableauDesId[3], x);
					else {
						bool loop = true;
						std::string nom = "";
						sf::Text nomText (nom, fontSave, 80);
						nomText.setPosition(600, 600);
						nomText.setFillColor(sf::Color::White);
						while (loop) {
							maFenetre.display();
							maFenetre.draw(sortBackSprite);
							maFenetre.draw(nomText);
							if (Saisie() != NULL)
								nom += Saisie();
							while(sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)){}
							nomText.setString(nom);
							//nomText.setOrigin(600, 600);
							//maFenetre.draw(nomText);
						}
						creerDresseurEtBoite(nom);
						chargerIdsNomsDresseurs(tableauDesId, tableauDesNoms);
						dres = chargerDresseur(tableauDesId[3], x);
						Pokemonstock aInsert = creerUnPokemonRandom();
						aInsert.ps_insererDansDb(dres.d_getIDEquipe());
					}
				}
				else if (save_select_tab[0] && !save_select_tab[1]) {
					if (profilIsCreated[2])
						dres = chargerDresseur(tableauDesId[2], x);
					else {
						bool loop = true;
						std::string nom = "";
						sf::Text nomText(nom, fontSave, 80);
						nomText.setPosition(600, 600);
						nomText.setFillColor(sf::Color::White);
						while (loop) {
							maFenetre.display();
							maFenetre.draw(sortBackSprite);
							maFenetre.draw(nomText);
							if (Saisie() != NULL)
								nom += Saisie();
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) {}
							nomText.setString(nom);
							//nomText.setOrigin(600, 600);
							//maFenetre.draw(nomText);
						}
						creerDresseurEtBoite(nom);
						chargerIdsNomsDresseurs(tableauDesId, tableauDesNoms);
						dres = chargerDresseur(tableauDesId[2], x);
						Pokemonstock aInsert = creerUnPokemonRandom();
						aInsert.ps_insererDansDb(dres.d_getIDEquipe());
					}
				}
				if (!save_select_tab[0] && save_select_tab[1]) {
					if (profilIsCreated[1])
						dres = chargerDresseur(tableauDesId[1], x);
					else {
						while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}
						bool loop = true;
						std::string nom = "";
						sf::Text nomText(nom, fontSave, 80);
						nomText.setPosition(x*140, x*500);
						nomText.setFillColor(sf::Color::White);
						while (loop && nom.size()<20) {
							while (maFenetre.pollEvent(event)) {
								maFenetre.display();
								maFenetre.draw(sortBackSprite);
								/*if (Saisie() != NULL) {
									nom += Saisie();
								}*/
								/*while (sf::Keyboard::isKeyPressed) {
									maFenetre.display();
									maFenetre.draw(sortBackSprite);
									maFenetre.draw(nomText);
								}*/
								if (event.type == sf::Event::TextEntered)
								{
									if (event.text.unicode < 128 && isalpha(event.text.unicode))
										nom += static_cast<char>(event.text.unicode);
								}
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace)&&nom.size()>0) {
									nom.pop_back();
								}
								while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace)){}
								nomText.setString(nom);
								maFenetre.draw(nomText);
							}
						}
						creerDresseurEtBoite(nom);
						chargerIdsNomsDresseurs(tableauDesId, tableauDesNoms);
						dres = chargerDresseur(tableauDesId[1], x);
						Pokemonstock aInsert = creerUnPokemonRandom();
						aInsert.ps_insererDansDb(dres.d_getIDEquipe());
					}
				}
				else if (!save_select_tab[0] && !save_select_tab[1]) {
					if (profilIsCreated[0])
						dres = chargerDresseur(tableauDesId[0], x);
					else {
						bool loop = true;
						std::string nom = "";
						sf::Text nomText(nom, fontSave, 80);
						nomText.setPosition(600, 600);
						nomText.setFillColor(sf::Color::White);
						while (loop) {
							maFenetre.display();
							maFenetre.draw(sortBackSprite);
							maFenetre.draw(nomText);
							if (Saisie() != NULL)
								nom += Saisie();
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) {}
							nomText.setString(nom);
							//nomText.setOrigin(600, 600);
							//maFenetre.draw(nomText);
						}
						creerDresseurEtBoite(nom);
						chargerIdsNomsDresseurs(tableauDesId, tableauDesNoms);
						dres = chargerDresseur(tableauDesId[0], x);
						Pokemonstock aInsert = creerUnPokemonRandom();
						aInsert.ps_insererDansDb(dres.d_getIDEquipe());
					}
				}
				dres.d_chargerEquipe();
				dres.d_chargerBoite();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				selectData = 0;
				endmap = 0;
				boo = 1;
				if (save_select_tab[0] && save_select_tab[1]) {
					supprimerUnDresseurDansDB(tableauDesId[3]);
				}
				else if (save_select_tab[0] && !save_select_tab[1]) {
					supprimerUnDresseurDansDB(tableauDesId[2]);
				}
				if (!save_select_tab[0] && save_select_tab[1]) {
					supprimerUnDresseurDansDB(tableauDesId[1]);
				}
				else if (!save_select_tab[0] && !save_select_tab[1]) {
					supprimerUnDresseurDansDB(tableauDesId[0]);
				}
				dres.d_chargerEquipe();
				dres.d_chargerBoite();
			}
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

			if (Collision(dres.d_sprite.getGlobalBounds(), porte_enter)[2] && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				pokecentre_scene = TRUE;
				endmap = FALSE;
			}
			maFenetre.display();
		} // fin boucle map

		if (pokecentre_scene)
		{
			//set background
			dres.d_sprite.setPosition(x * 800, x * 620);
			std::vector<sf::Text> equipeText;
			std::vector<sf::Text> boiteText;
			std::vector<sf::Text> pokedexText;
			std::string query = "SELECT * FROM pokemonpokedex ORDER BY ppx_idpokemon";
			std::vector<Pokemon> lePokedex = chargerLePokedex(query);
			for (int i = 0; i < lePokedex.size(); i++) {
				sf::Text temp(lePokedex[i].p_getnom(), fontSave, x * 66);
				pokedexText.push_back(temp);
			}

			sf::Text pressEnterToBoite("Appuyez sur ENTER pour\nle placer dans la boite", fontSave, x * 20);
			pressEnterToBoite.setPosition(sf::Vector2f(x * 800, x * 1020));
			pressEnterToBoite.setFillColor(sf::Color::White);

			sf::Text pressEnterToEquipe("Appuyez sur ENTER pour\nle placer dans l'equipe", fontSave, x * 20);
			pressEnterToEquipe.setPosition(sf::Vector2f(x * 800, x * 1020));
			pressEnterToEquipe.setFillColor(sf::Color::White);

			sf::Text pressDtoDelete("Appuyez sur D pour\nle supprimer", fontSave, x * 20);
			pressDtoDelete.setPosition(sf::Vector2f(x * 800, x * 1080));
			pressDtoDelete.setFillColor(sf::Color::White);


			int indexPokemonSelectedEquipe = 0;
			int indexPokemonSelectedBoite = 0;
			int positionDansLaListeBoite = 0;

			while (pokecentre_scene) {
				maFenetre.display();
				std::vector<bool> detectcoll;
				for (int i = 0; i < 4; i++) { // on regarde dans chaques directions
					if (Collision(dres.d_sprite.getGlobalBounds(), mur_centre_1)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_2)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_2bis)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_2bisbis)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_3)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_4)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_5)[i]
						|| Collision(dres.d_sprite.getGlobalBounds(), mur_centre_table)[i])
					{
						detectcoll.push_back(1);
					}
					else
						detectcoll.push_back(0);
				}
				dres.update(detectcoll, pas, x);

				//adapter la fonction draw
				////ici
				maFenetre.draw(centre_sprite); //pour le fond
				maFenetre.draw(dres.d_sprite); //pour le dresseur
				pas++;
				if (pas == 20)
					pas = 0;
				if (Collision(dres.d_sprite.getGlobalBounds(), porte_out)[3] && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
					pokecentre_scene = FALSE;
					dres.d_sprite.setPosition(x * 800, x * 660);
				}
				if (dres.d_sprite.getGlobalBounds().intersects(computer_zone) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}
					bool computer = TRUE;
					bool boite = FALSE;
					bool equipe = FALSE;
					bool pokedex = FALSE;
					bool selection = 0;
					dres.d_healequipe();
					computer_sprite.setTexture(computer_equipe);
					selection = 0;
					while (computer) {
						positionDansLaListeBoite = 0;
						equipeText.clear();
						boiteText.clear();
						for (int i = 0; i < dres.d_getSizeBoite(); i++) {
							sf::Text temp(dres.d_getPokemonBoite(i).p_getnom(), fontSave, x * 66);
							boiteText.push_back(temp);
						}
						for (int i = 0; i < dres.d_getSizeEquipe(); i++) {
							sf::Text temp(dres.d_getPokemonEquipe(i).p_getnom(), fontSave, x * 66);
							equipeText.push_back(temp);
						}
						for (int i = 0; i < equipeText.size(); i++) {
							equipeText[i].setPosition(x * 60, x*(35 + 188 * (i + 1) - 188 / 2));
						}
						maFenetre.display();
						maFenetre.draw(computer_sprite);
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
							computer_sprite.setTexture(computer_boite);
							selection = 1;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
							computer_sprite.setTexture(computer_equipe);
							selection = 0;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
							computer = FALSE;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && sf::Keyboard::isKeyPressed(sf::Keyboard:: P)) {
							pokedex = TRUE;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
							if (!selection)
								equipe = TRUE;
							else if (dres.d_getSizeBoite()>0)
								boite = TRUE;
						}
						while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}

						while (equipe) {
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && indexPokemonSelectedEquipe<equipeText.size() - 1)
								indexPokemonSelectedEquipe++;
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && indexPokemonSelectedEquipe > 0)
								indexPokemonSelectedEquipe--;
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {}
							for (int i = 0; i < equipeText.size(); i++) {
								if (i == indexPokemonSelectedEquipe)
									equipeText[i].setFillColor(sf::Color::Blue);
								else
									equipeText[i].setFillColor(sf::Color::White);
							}

							std::string textPoke = dres.d_getPokemonEquipe(indexPokemonSelectedEquipe).ps_getAffichage();
							Pokemonstock pokestock = dres.d_getPokemonEquipe(indexPokemonSelectedEquipe);
							pokestock.p_setsprite(1.5*x);
							pokestock.p_setSpritePosition(580, 950, x);
							sf::Text textPokeText(textPoke, fontSave, 20 * x);
							textPokeText.setFillColor(sf::Color::White);
							textPokeText.setPosition(x * 610, x * 740);
							maFenetre.display();
							maFenetre.draw(equipe_sprite);
							maFenetre.draw(poke_info_sprite);
							maFenetre.draw(textPokeText);
							maFenetre.draw(pokestock.p_getsprite());
							maFenetre.draw(pressEnterToBoite);
							maFenetre.draw(pressDtoDelete);

							for (int i = 0; i < equipeText.size(); i++) {
								maFenetre.draw(equipeText[i]);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
								equipe = FALSE;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
								if (dres.d_getSizeEquipe() > 1) {
									dres.d_getPokemonEquipe(indexPokemonSelectedEquipe).ps_updateDansDB(dres.d_getIDBoite());
									dres.d_chargerBoite();
									dres.d_chargerEquipe();
									equipe = false;
									boite = false;
									computer = false;
									/*equipeText.clear();
									boiteText.clear();
									for (int i = 0; i < dres.d_getSizeEquipe(); i++) {
									sf::Text temp(dres.d_getPokemonEquipe(i).p_getnom(), fontSave, x * 66);
									equipeText.push_back(temp);
									}
									for (int i = 0; i < equipeText.size(); i++) {
									equipeText[i].setPosition(x * 60, x*(35 + 188 * (i + 1) - 188 / 2));
									}
									for (int i = 0; i < dres.d_getSizeBoite(); i++) {
									sf::Text temp(dres.d_getPokemonBoite(i).p_getnom(), fontSave, x * 66);
									boiteText.push_back(temp);
									}
									computer_sprite.setTexture(computer_boite);*/
									indexPokemonSelectedBoite = 0;
									indexPokemonSelectedEquipe = 0;
									positionDansLaListeBoite = 0;
								}
								else
									pressEnterToBoite.setString("Vous devez garder un Pokemon");
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
								if (dres.d_getSizeEquipe() > 1) {
									supprimerUnPokeDansDB(dres.d_getPokemonEquipe(indexPokemonSelectedEquipe).p_getid());
									dres.d_chargerBoite();
									dres.d_chargerEquipe();
									equipe = false;
									boite = false;
									computer = false;
									indexPokemonSelectedBoite = 0;
									indexPokemonSelectedEquipe = 0;
									positionDansLaListeBoite = 0;
								}
								else
									pressEnterToBoite.setString("Vous devez garder un Pokemon");
							}
							maFenetre.draw(pressEnterToBoite);
							maFenetre.draw(pressDtoDelete);
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}
							pressEnterToBoite.setString("Appuyez sur ENTER pour\nle placer dans la boite");
						}
						while (boite) {
							maFenetre.display();
							maFenetre.draw(computer_sprite);
							maFenetre.draw(equipe_sprite);
							maFenetre.draw(poke_info_sprite);
							maFenetre.draw(pressDtoDelete);
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && indexPokemonSelectedBoite < boiteText.size() - 1) {
								indexPokemonSelectedBoite++;
								if (positionDansLaListeBoite < 5)
									positionDansLaListeBoite++;
							}
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && indexPokemonSelectedBoite > 0) {
								indexPokemonSelectedBoite--;
								if (positionDansLaListeBoite > 0)
									positionDansLaListeBoite--;
							}
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {}
							for (int i = 0; i < boiteText.size(); i++) {
								if (i == indexPokemonSelectedBoite)
									boiteText[i].setFillColor(sf::Color::Blue);
								else
									boiteText[i].setFillColor(sf::Color::White);
							}
							if (boiteText.size() > 6) {
								int j = 0;
								switch (positionDansLaListeBoite) {
								case 0:
									for (int i = indexPokemonSelectedBoite; i < indexPokemonSelectedBoite + 6; i++) {
										boiteText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(boiteText[i]);
									}
									break;
								case 1:
									for (int i = indexPokemonSelectedBoite - 1; i < indexPokemonSelectedBoite + 5; i++) {
										boiteText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(boiteText[i]);
									}
									break;
								case 2:
									for (int i = indexPokemonSelectedBoite - 2; i < indexPokemonSelectedBoite + 4; i++) {
										boiteText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(boiteText[i]);
									}
									break;
								case 3:
									for (int i = indexPokemonSelectedBoite - 3; i < indexPokemonSelectedBoite + 3; i++) {
										boiteText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(boiteText[i]);
									}
									break;
								case 4:
									for (int i = indexPokemonSelectedBoite - 4; i < indexPokemonSelectedBoite + 2; i++) {
										boiteText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(boiteText[i]);
									}
									break;
								case 5:
									for (int i = indexPokemonSelectedBoite - 5; i < indexPokemonSelectedBoite + 1; i++) {
										boiteText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(boiteText[i]);
									}
									break;
								}
							}
							else {
								for (int i = 0; i < boiteText.size(); i++) {
									boiteText[i].setPosition(x * 60, x*(35 + 188 * (i + 1) - 188 / 2));
									maFenetre.draw(boiteText[i]);
								}
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
								if (dres.d_getSizeEquipe() < 6) {
									dres.d_getPokemonBoite(indexPokemonSelectedBoite).ps_updateDansDB(dres.d_getIDEquipe());
									dres.d_chargerBoite();
									dres.d_chargerEquipe();
									boite = false;
									equipe = false;
									computer = false;
									equipeText.clear();
									boiteText.clear();
									indexPokemonSelectedBoite = 0;
									indexPokemonSelectedEquipe = 0;
									positionDansLaListeBoite = 0;

								}
								else {
									pressEnterToEquipe.setString("L'Equipe est pleine!");
								}
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
								supprimerUnPokeDansDB(dres.d_getPokemonBoite(indexPokemonSelectedBoite).p_getid());
								dres.d_chargerBoite();
								dres.d_chargerEquipe();
								boite = false;
								equipe = false;
								computer = false;
								equipeText.clear();
								boiteText.clear();
								indexPokemonSelectedBoite = 0;
								indexPokemonSelectedEquipe = 0;
								positionDansLaListeBoite = 0;
							}
							maFenetre.draw(pressEnterToEquipe);
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) { maFenetre.draw(pressEnterToEquipe); }
							pressEnterToEquipe.setString("Appuyez sur ENTER pour\nle placer dans l'equipe");
							std::string textPoke = dres.d_getPokemonBoite(indexPokemonSelectedBoite).ps_getAffichage();
							Pokemonstock pokestock = dres.d_getPokemonBoite(indexPokemonSelectedBoite);
							pokestock.p_setsprite(1.5*x);
							pokestock.p_setSpritePosition(580, 950, x);
							sf::Text textPokeText(textPoke, fontSave, 20 * x);
							textPokeText.setFillColor(sf::Color::White);
							textPokeText.setPosition(x * 610, x * 740);
							maFenetre.draw(textPokeText);
							maFenetre.draw(pokestock.p_getsprite());

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
								boite = FALSE;
							}
						}
						while (pokedex) {
							maFenetre.display();
							maFenetre.draw(blackScreen);
							//maFenetre.draw(computer_sprite);
							maFenetre.draw(equipe_sprite);
							maFenetre.draw(poke_info_sprite);
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && indexPokemonSelectedBoite < pokedexText.size() - 1) {
								indexPokemonSelectedBoite++;
								if (positionDansLaListeBoite < 5)
									positionDansLaListeBoite++;
							}
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && indexPokemonSelectedBoite > 0) {
								indexPokemonSelectedBoite--;
								if (positionDansLaListeBoite > 0)
									positionDansLaListeBoite--;
							}
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {}
							for (int i = 0; i < pokedexText.size(); i++) {
								if (i == indexPokemonSelectedBoite)
									pokedexText[i].setFillColor(sf::Color::Blue);
								else
									pokedexText[i].setFillColor(sf::Color::White);
							}
							if (pokedexText.size() > 6) {
								int j = 0;
								switch (positionDansLaListeBoite) {
								case 0:
									for (int i = indexPokemonSelectedBoite; i < indexPokemonSelectedBoite + 6; i++) {
										pokedexText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(pokedexText[i]);
									}
									break;
								case 1:
									for (int i = indexPokemonSelectedBoite - 1; i < indexPokemonSelectedBoite + 5; i++) {
										pokedexText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(pokedexText[i]);
									}
									break;
								case 2:
									for (int i = indexPokemonSelectedBoite - 2; i < indexPokemonSelectedBoite + 4; i++) {
										pokedexText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(pokedexText[i]);
									}
									break;
								case 3:
									for (int i = indexPokemonSelectedBoite - 3; i < indexPokemonSelectedBoite + 3; i++) {
										pokedexText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(pokedexText[i]);
									}
									break;
								case 4:
									for (int i = indexPokemonSelectedBoite - 4; i < indexPokemonSelectedBoite + 2; i++) {
										pokedexText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(pokedexText[i]);
									}
									break;
								case 5:
									for (int i = indexPokemonSelectedBoite - 5; i < indexPokemonSelectedBoite + 1; i++) {
										pokedexText[i].setPosition(x * 60, x*(35 + 188 * (j + 1) - 188 / 2));
										j++;
										maFenetre.draw(pokedexText[i]);
									}
									break;
								}
							}
							else {
								for (int i = 0; i < pokedexText.size(); i++) {
									pokedexText[i].setPosition(x * 60, x*(35 + 188 * (i + 1) - 188 / 2));
									maFenetre.draw(pokedexText[i]);
								}
							}
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) { maFenetre.draw(pressEnterToEquipe); }
							pressEnterToEquipe.setString("Appuyez sur ENTER pour\nle placer dans l'equipe");
							std::string textPoke =lePokedex[indexPokemonSelectedBoite].p_getAffichage();

							Pokemon pokestock = lePokedex[indexPokemonSelectedBoite];
							pokestock.p_setsprite(1.5*x);
							pokestock.p_setSpritePosition(580, 950, x);

							sf::Text textPokeText(textPoke, fontSave, 20 * x);
							textPokeText.setFillColor(sf::Color::White);
							textPokeText.setPosition(x * 610, x * 740);
							maFenetre.draw(textPokeText);
							maFenetre.draw(pokestock.p_getsprite());

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
								bool sortOptions = true;
								std::vector <sf::Text> sortedMetod;
								sortedMetod.push_back(sf::Text("sort by ID", fontSave, 66));   // 0
								sortedMetod.push_back(sf::Text("sort by NAME", fontSave, 66)); // 1
								sortedMetod.push_back(sf::Text("sort by TYPE", fontSave, 66)); // 2
								int sortSelected = 0;
								while (sortOptions) {
									positionDansLaListeBoite = 0;
									indexPokemonSelectedBoite = 0;
									maFenetre.display();
									maFenetre.draw(sortBackSprite);
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sortSelected > 0)
										sortSelected--;
									while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {}
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sortSelected < sortedMetod.size()-1)
										sortSelected++;
									while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {}
									for (int i = 0; i < sortedMetod.size(); i++) {
										if (i == sortSelected)
											sortedMetod[i].setFillColor(sf::Color::Blue);
										else
											sortedMetod[i].setFillColor(sf::Color::White);
										sortedMetod[i].setPosition(sf::Vector2f(x * 140, x*(46 + 188 * (i + 1) - 188 / 2)));
										maFenetre.draw(sortedMetod[i]);
									}
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
										while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){}
										switch (sortSelected) {
										case 0: 
											pokedexText.clear();
											lePokedex = chargerLePokedex("SELECT * FROM pokemonpokedex ORDER BY ppx_idpokemon");
											for (int i = 0; i < lePokedex.size(); i++) {
												sf::Text temp(lePokedex[i].p_getnom(), fontSave, x * 66);
												pokedexText.push_back(temp);
											}
											sortOptions = false;
											break;
										case 1:
											pokedexText.clear();
											lePokedex = chargerLePokedex("SELECT * FROM pokemonpokedex ORDER BY ppx_nompokedex");
											for (int i = 0; i < lePokedex.size(); i++) {
												sf::Text temp(lePokedex[i].p_getnom(), fontSave, x * 66);
												pokedexText.push_back(temp);
											}
											sortOptions = false;
											break;
										case 2:
											std::vector <sf::Text> types;
											types.push_back(sf::Text("Combat", fontSave, 40));   // 0
											types.push_back(sf::Text("Dragon", fontSave, 40)); // 1
											types.push_back(sf::Text("Eau", fontSave, 40)); // 2
											types.push_back(sf::Text("Electrique", fontSave, 40)); // 3
											types.push_back(sf::Text("Feu", fontSave, 40)); // 4
											types.push_back(sf::Text("Glace", fontSave, 40)); // 5
											types.push_back(sf::Text("Insecte", fontSave, 40)); // 6
											types.push_back(sf::Text("Normal", fontSave, 40)); // 7
											types.push_back(sf::Text("Plante", fontSave, 40)); // 8
											types.push_back(sf::Text("Poison", fontSave, 40)); // 9
											types.push_back(sf::Text("Psy", fontSave, 40)); // 10
											types.push_back(sf::Text("Roche", fontSave, 40)); // 11
											types.push_back(sf::Text("Sol", fontSave, 40)); // 12
											types.push_back(sf::Text("Spectre", fontSave, 40)); // 13
											types.push_back(sf::Text("Vol", fontSave, 40)); // 14
											int typeSelected = 0;
											while (sortOptions) {
												maFenetre.display();
												maFenetre.draw(sortBackSprite);
												std::cout << typeSelected << std::endl;
												if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && typeSelected > 0)
													typeSelected--;
												while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {}
												if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && typeSelected < types.size() - 1)
													typeSelected++;
												while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {}
												for (int i = 0; i < types.size(); i++) {
													if (i == typeSelected)
														types[i].setFillColor(sf::Color::Blue);
													else
														types[i].setFillColor(sf::Color::White);
													types[i].setPosition(sf::Vector2f(x * 140, x*(116 + (190 * (i + 1) - 188 / 2)/4)));
													maFenetre.draw(types[i]);
												}
												if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
													while (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
													std::string leType;
													switch (typeSelected) {
													case 0: // combat
														leType = "combat";
														break;
													case 1: // dragon
														leType = "dragon";
														break;
													case 2: // eau
														leType = "eau";
														break;
													case 3: // electrik
														leType = "electrik";
														break;
													case 4: // feu
														leType = "feu";
														break;
													case 5: // glace
														leType = "glace";
														break;
													case 6: // insecte
														leType = "insecte";
														break;
													case 7: // normal
														leType = "normal";
														break;
													case 8: // plante
														leType = "plante";
														break;
													case 9: // poison
														leType = "poison";
														break;
													case 10: // psy
														leType = "psy";
														break;
													case 11: // roche
														leType = "roche";
														break;
													case 12: // sol
														leType = "sol";
														break;
													case 13: // spectre
														leType = "spectre";
														break;
													case 14: // vol
														leType = "vol";
														break;
													}
													pokedexText.clear();
													lePokedex = chargerLePokedex("SELECT * FROM pokemonpokedex WHERE ppx_type = \'" + leType + "\' ");
													for (int i = 0; i < lePokedex.size(); i++) {
														sf::Text temp(lePokedex[i].p_getnom(), fontSave, x * 66);
														pokedexText.push_back(temp);
													}
													sortOptions = false;
												}
											}
											break;
										}
									}
								}
							}

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
								pokedex = FALSE;
							}
						}
					}
				}
			}


		}

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
			int position = dres.d_getPokePasKO()[0];
			Pokemoncombat mon_pokemon(dres.d_getPokemonEquipe(position));
			std::cout << "le nom: " << mon_pokemon.p_getnom() << std::endl;
			mon_pokemon.p_setsprite(2 * x);
			mon_pokemon.p_setSpritePosition(310 - 40, 390, x);

			// poke sauvage
			Pokemoncombat pokemon_sauvage(creerUnPokemonRandom());
			std::cout << "la nom: " << pokemon_sauvage.p_getnom() << std::endl;
			pokemon_sauvage.p_setsprite(2 * x);
			pokemon_sauvage.p_setSpritePosition(730 - 70, 390, x);

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

			// win
			sf::Texture winTexture;
			winTexture.loadFromFile("Sprite/win.png");
			sf::Sprite winSprite;
			winSprite.setTexture(winTexture);
			winSprite.setScale(x, x);

			// gameOver
			sf::Sprite gameOverSprite;
			sf::Texture gameOverTexture;
			gameOverTexture.loadFromFile("Sprite/gameover.png");
			gameOverSprite.setTexture(gameOverTexture);
			gameOverSprite.setScale(x, x);

			// barres de vies
			sf::RectangleShape bdv1(sf::Vector2f(x * 470, x * 79));
			sf::RectangleShape bdv2(sf::Vector2f(x * 470, x * 79));
			bdv1.setPosition(x * 67, x * 150);
			bdv2.setPosition(x * 665, x * 150);
			bdv1.setFillColor(sf::Color::Red);
			bdv2.setFillColor(sf::Color::Red);

			while (endcombat) { // boucle lié à un combat
				bdv1.setSize(sf::Vector2f(x * 470 * mon_pokemon.ps_getpvrestant() / mon_pokemon.p_getpvmax(), x * 79));
				bdv2.setSize(sf::Vector2f(x * 470 * pokemon_sauvage.ps_getpvrestant() / pokemon_sauvage.p_getpvmax(), x * 79));
				maFenetre.display();

				maFenetre.draw(backcombat_sprite); //pour l'arene
				maFenetre.draw(pokemon_sauvage.p_getsprite());
				maFenetre.draw(mon_pokemon.p_getsprite());
				maFenetre.draw(combat_selection_sprite);
				maFenetre.draw(bdv1);
				maFenetre.draw(bdv2);

				if (win) {
					endcombat = false;
					for (int i = 0; i < 200; i++) {
						maFenetre.display();

						maFenetre.draw(backcombat_sprite); //pour l'arene
						maFenetre.draw(pokemon_sauvage.p_getsprite());
						maFenetre.draw(mon_pokemon.p_getsprite());
						maFenetre.draw(combat_selection_sprite);
						maFenetre.draw(bdv1);
						maFenetre.draw(bdv2);
						maFenetre.draw(winSprite);
					}
				}
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
					if (arrow_tab[0] && arrow_tab[1]) { // si on est sur fuite
						endcombat = 0;
						mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
						dres.d_setPokemonEquipe(mon_pokemon, position);
					}
					if (!arrow_tab[0] && arrow_tab[1]) // si on est sur capturer
						capture = 1;

					if (!arrow_tab[0] && !arrow_tab[1]) // si on est sur attaquer
					{
						attaque = 1;
						capture = 0;


						sf::String att1text;
						//att1text = "CHARGE";
						att1text = mon_pokemon.ps_getattaque(0).a_getnom();
						att1.setString(att1text);
						if (att1text.getSize() <= 6) {
							att1.setPosition(x*(635 + 25 * (6 - att1text.getSize())), x * 985);
						}
						if (att1text.getSize() > 6) {
							att1.setPosition(x * 635, x * (985 + 3.5*(att1text.getSize() - 6)));
							att1.setCharacterSize(x * 300 / att1text.getSize());
						}

						//att2text = mon_pokemon.p_getnomattaques[1];
						//att2text = "RUGISSEMENT";
						att2text = mon_pokemon.ps_getattaque(1).a_getnom();
						att2.setString(att2text);
						if (att2text.getSize() <= 6) {
							att2.setPosition(x * (950 + 25 * (6 - att2text.getSize())), x * 985);
						}
						if (att2text.getSize() > 6) {
							att2.setPosition(x * 950, x * (985 + 3.5*(att2text.getSize() - 6)));
							att2.setCharacterSize(x * 300 / att2text.getSize());
						}

						//att3text = mon_pokemon.p_getnomattaques[2];
						//att3text = "SURF";
						att3text = mon_pokemon.ps_getattaque(2).a_getnom();
						att3.setString(att3text);
						if (att3text.getSize() <= 6) {
							att3.setPosition(x * 635 + x * 25 * (6 - att3text.getSize()), x * 1105);
						}
						if (att3text.getSize() > 6) {
							att3.setPosition(x * 635, x * 1105 + x * 3.5*(att3text.getSize() - 6));
							att3.setCharacterSize(x * 300 / att3text.getSize());
						}

						//att4text = mon_pokemon.p_getnomattaques[3];
						//att4text = "BITE";
						att4text = mon_pokemon.ps_getattaque(3).a_getnom();
						att4.setString(att4text);
						if (att4text.getSize() <= 6) {
							att4.setPosition(x * 950 + x * 25 * (6 - att4text.getSize()), x * 1105);
						}
						if (att4text.getSize() > 6) {
							att4.setPosition(x * 950, x * 1105 + x * 3.5*(att4text.getSize() - 6));
							att4.setCharacterSize(x * 300 / att4text.getSize());
						}

						while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}
					}

					if (arrow_tab[0] && !arrow_tab[1]) // si on est sur équipe
					{
					}
				}
				if (capture) {
					std::cout << anim_poke << std::endl;
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
						pokeball_sprite.setPosition(x * 800, x * 238 + x * 270 - x * 2 * (anim_poke - 77));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 90) {
						pokeball_sprite.setPosition(x * 800, x * 238 + x * 263 - x * 1 * (anim_poke - 83));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					if (anim_poke == 91) {
						anim_poke = 0;
						capture = false;
						int nbrandom = rand() % 100;
						float seuil = 100 * (1 - pokemon_sauvage.ps_getpvrestant() / pokemon_sauvage.p_getpvmax());
						if (nbrandom < seuil) {
							pokemon_sauvage.ps_insererDansDb(dres.d_getIDBoite());
							dres.d_chargerBoite();
							endcombat = false;
							mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
							dres.d_setPokemonEquipe(mon_pokemon, position);
						}
						else {
							nombre = (rand() % 4);//l'autre pokémon doit sélectionner une attaque
							deroulementattaque(pokemon_sauvage, mon_pokemon, nombre, matricecoef);//degats s'infligent
							std::cout << "pv mon poke : " << mon_pokemon.ps_getpvrestant() << "pv ennemi : " << pokemon_sauvage.ps_getpvrestant();
							if (mon_pokemon.ps_getpvrestant() == 0)
							{
								bdv1.setSize(sf::Vector2f(0, x * 79));
								std::cout << "Mon Pokémon ko !" << std::endl;
								//ICI restocker le pokemon dans l'équipe du pokemostock avec ses pvs mis à jour
								//Puis le save dans la DB actualisé ainsi, çà sera fait dans la fct setpokemonequipe
								mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
								dres.d_setPokemonEquipe(mon_pokemon, position);
								if (dres.d_getPokePasKO().size() == 0)
								{
									std::cout << "gameover" << std::endl;
									//afficher game over
									//soigner toute l'équipe 
									dres.d_healequipe();
									endcombat = false;
								}
								else
								{//sinon j'ai le droit de switch de pokémon ou de fuir!
									position = dres.d_getPokePasKO()[0];
									mon_pokemon = Pokemonstock(dres.d_getPokemonEquipe(position));
									mon_pokemon.p_setsprite(2 * x);
									mon_pokemon.p_setSpritePosition(310 - 40, 390, x);
									attaque = false;
								}
							}
						}
					}
				}
				if (attaque) {
					maFenetre.draw(combat_attaque_sprite);
					maFenetre.draw(att1);
					maFenetre.draw(att2);
					maFenetre.draw(att3);
					maFenetre.draw(att4);
					maFenetre.draw(arrow_sprite);
					bool atkIsSelected = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
						if (arrow_tab[0] && arrow_tab[1]) // si on est sur ATT 4
							attaquejoueur = 3;
						if (!arrow_tab[0] && arrow_tab[1]) // si on est sur ATT 2
							attaquejoueur = 1;
						if (!arrow_tab[0] && !arrow_tab[1]) // si on est sur ATT 1
							attaquejoueur = 0;
						if (arrow_tab[0] && !arrow_tab[1]) // si on est sur ATT 3
							attaquejoueur = 2;
						atkIsSelected = false;
					}

					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {}
					if (!atkIsSelected) {
						if (mon_pokemon.pc_getvitcombat() > pokemon_sauvage.pc_getvitcombat())//mon pokemon attaque donc en premier
						{
							deroulementattaque(mon_pokemon, pokemon_sauvage, attaquejoueur, matricecoef);//degats s'infligent
																										 //bdv2.setSize(sf::Vector2f((pokemon_sauvage.ps_getpvrestant() / pokemon_sauvage.p_getpvmax()) * 470, 150));
							if (pokemon_sauvage.ps_getpvrestant() == 0)
							{
								bdv2.setSize(sf::Vector2f(0, x * 79));
								std::cout << "Pokemon vaincu !" << std::endl;
								std::cout << "pv mon poke : " << mon_pokemon.ps_getpvrestant() << "pv ennemi : " << pokemon_sauvage.ps_getpvrestant();
								win = true;
								/*for (int i = 0; i < 100000; i++) {
								maFenetre.display();
								maFenetre.draw(winSprite);
								}*/
								//ICI le pokemon qui s'est battu gagne des points dépendant des evs de la cible vaincue + mettre à jour les pvs ! 
								//puis s'update dans la database ! 
								mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
								dres.d_setPokemonEquipe(mon_pokemon, position);
								//endcombat = false;
							}
							//si encore en vie, l'autre pokémon contre attaque ! 
							else {//l'autre pokémon doit sélectionner une attaque et doit attaquer
								nombre = (rand() % 4);
								deroulementattaque(pokemon_sauvage, mon_pokemon, nombre, matricecoef);
							}
							if (mon_pokemon.ps_getpvrestant() == 0)//on n'a pas de risque de rentrer ici si j'ai déjà battu le pokemon car l'autre n'attaque pas et je ne perd pas de pvs ! 
							{
								std::cout << "Mon Pokémon ko !" << std::endl;
								//ICI restocker le pokemon dans l'équipe du pokemostock avec ses pvs mis à jour
								//Puis le save dans la DB actualisé ainsi, çà sera fait dans la fct setpokemonequipe
								mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
								dres.d_setPokemonEquipe(mon_pokemon, position);
								if (dres.d_getPokePasKO().size() == 0)
								{
									std::cout << "gameover" << std::endl;
									for (int i = 0; i < 150; i++) {
										maFenetre.display();
										maFenetre.draw(gameOverSprite);
									}
									//afficher game over
									//soigner toute l'équipe 
									dres.d_healequipe();
									endcombat = false;
								}
								else
								{//sinon j'ai le droit de switch de pokémon ou de fuir!
								 //std::cin >> switchp;
								 //pokeequipe = rand() % dres.d_getPokePasKO().size();
								 //equipe[pokeequipe].ps_fincombat(mon_pokemon, pokemon_sauvage, win, 1);
								 //lespokemonspasko.clear();//je parcours mon équipe, je prend ceux qui sont pas ko
									position = dres.d_getPokePasKO()[0];
									mon_pokemon = Pokemonstock(dres.d_getPokemonEquipe(position));
									mon_pokemon.p_setsprite(2 * x);
									mon_pokemon.p_setSpritePosition(310 - 40, 390, x);
									attaque = false;
								}
							}
						}
						else//ici c'est le pokémon sauvage qui attaque en premier
						{
							nombre = (rand() % 4);//l'autre pokémon doit sélectionner une attaque
							deroulementattaque(pokemon_sauvage, mon_pokemon, nombre, matricecoef);//degats s'infligent
							std::cout << "pv mon poke : " << mon_pokemon.ps_getpvrestant() << "pv ennemi : " << pokemon_sauvage.ps_getpvrestant();
							if (mon_pokemon.ps_getpvrestant() == 0)
							{
								bdv1.setSize(sf::Vector2f(0, x * 79));
								std::cout << "Mon Pokémon ko !" << std::endl;
								//ICI restocker le pokemon dans l'équipe du pokemostock avec ses pvs mis à jour
								//Puis le save dans la DB actualisé ainsi, çà sera fait dans la fct setpokemonequipe
								mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
								dres.d_setPokemonEquipe(mon_pokemon, position);
								if (dres.d_getPokePasKO().size() == 0)
								{
									std::cout << "gameover" << std::endl;
									for (int i = 0; i < 150; i++) {
										maFenetre.display();
										maFenetre.draw(gameOverSprite);
									}
									//afficher game over
									//soigner toute l'équipe 
									dres.d_healequipe();
									endcombat = false;
								}
								else
								{//sinon j'ai le droit de switch de pokémon ou de fuir!
									position = dres.d_getPokePasKO()[0];
									mon_pokemon = Pokemonstock(dres.d_getPokemonEquipe(position));
									mon_pokemon.p_setsprite(2 * x);
									mon_pokemon.p_setSpritePosition(310 - 40, 390, x);
									attaque = false;
								}
							}
							else {//mon pokemon peut attaquer si il n'est pas ko 
								deroulementattaque(mon_pokemon, pokemon_sauvage, attaquejoueur, matricecoef);//degats s'infligent
								if (pokemon_sauvage.ps_getpvrestant() == 0)
								{
									std::cout << "Pokemon vaincu !" << std::endl;
									std::cout << "pv mon poke : " << mon_pokemon.ps_getpvrestant() << "pv ennemi : " << pokemon_sauvage.ps_getpvrestant();
									/*for (int i = 0; i < 100000; i++) {
									maFenetre.display();
									maFenetre.draw(winSprite);
									}*/
									win = true;
									//ICI le pokemon qui s'est battu gagne des points dépendant des evs de la cible vaincue + mettre à jour les pvs ! 
									//puis s'update dans la database ! 
									mon_pokemon.ps_fincombat(mon_pokemon, pokemon_sauvage, win);
									dres.d_setPokemonEquipe(mon_pokemon, position);
									//endcombat = false;
								}
							}
						}
						attaque = false;
					}
				}
			}
		}
	}

	// appel du destructeur
	/////ici
	dres.~Dresseur();
	return 0;
}
