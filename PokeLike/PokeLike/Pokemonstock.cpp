#pragma once
#include "Pokemonstock.h"
#include "Pokemon.h"
//constructeur par défaut
Pokemonstock::Pokemonstock()
{

} 
//constructeur par paramètre, avec les attaques comme paramètres, nous ne nous en servons plus je pense dans la version finale
Pokemonstock::Pokemonstock(int ID, std:: string nom, std :: string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std:: string typeev, int pvrestant, Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4)
{
	//le démasquage de la fonction parent ne voulait pas fonctionner pour une raison inconnue, et cette remarque est valable PARTOUT (donc dans tout les constructeurs des classes qui héritent de pokémon au départ (inclus donc les pokémoncombat)
	//Pokemon::Pokemon(ID, nom, type, posx, posy, pvmax, atk, atkspe, def, defspe, vit, evdonne, typeev);
	ps_pvrestant = pvrestant;
	p_ID = ID;
	std::cout << p_ID << std::endl;
	p_nom = nom;
	p_type = type;
	p_posx = posx;
	p_posy = posy;
	p_pvmax = pvmax;
	p_atk = atk;
	p_atkspe = atkspe;
	p_def = def;
	p_defspe = defspe;
	p_vit = vit;
	//p_rare = 1;//on en aura pas besoin
	p_evdonne = evdonne;
	p_typeev = typeev;
	//on va le charger sur une autre fonciton pour les temps de calcul lors de chargement
	if (type == "normal") {
		p_nombretype = 0;
	}
	if (type == "feu") {
		p_nombretype = 1;
	}
	if (type == "eau") {
		p_nombretype = 2;
	}
	if (type == "plante") {
		p_nombretype = 3;
	}
	if (type == "electrik") {
		p_nombretype = 4;
	}
	if (type == "glace") {
		p_nombretype = 5;
	}
	if (type == "combat") {
		p_nombretype = 6;
	}
	if (type == "poison") {
		p_nombretype = 7;
	}
	if (type == "sol") {
		p_nombretype = 8;
	}
	if (type == "vol") {
		p_nombretype = 9;
	}
	if (type == "psy") {
		p_nombretype = 10;
	}
	if (type == "insecte") {
		p_nombretype = 11;
	}
	if (type == "roche") {
		p_nombretype = 12;
	}
	if (type == "spectre") {
		p_nombretype = 13;
	}
	if (type == "dragon") {
		p_nombretype = 14;
	}
	if (type == "tenebres") {
		p_nombretype = 15;
	}
	if (type == "acier") {
		p_nombretype = 16;
	}
	ps_listeatq[0] = attaque1;
	ps_listeatq[1] = attaque2;
	ps_listeatq[2] = attaque3;
	ps_listeatq[3] = attaque4;
} 
//constructeur par paramètre, sans les attaques
Pokemonstock::Pokemonstock(int ID, std::string nom, std::string type, int posx, int posy, int pvmax, int atk, int atkspe, int def, int defspe, int vit, int evdonne, std::string typeev, int pvrestant)
{
	//Pokemon::Pokemon(ID, nom, type, posx, posy, pvmax, atk, atkspe, def, defspe, vit, evdonne, typeev);//çà marche pas pour une raison inconnue
	ps_pvrestant = pvrestant;
	p_ID = ID;
	//std::cout << p_ID << std::endl;
	p_nom = nom;
	p_type = type;
	p_posx = posx;
	p_posy = posy;
	p_pvmax = pvmax;
	p_atk = atk;
	p_atkspe = atkspe;
	p_def = def;
	p_defspe = defspe;
	p_vit = vit;
	//p_rare = 1;//on en aura pas besoin
	p_evdonne = evdonne;
	p_typeev = typeev;
	//on va le charger sur une autre fonciton pour les temps de calcul lors de chargement
	if (type == "normal") {
		p_nombretype = 0;
	}
	if (type == "feu") {
		p_nombretype = 1;
	}
	if (type == "eau") {
		p_nombretype = 2;
	}
	if (type == "plante") {
		p_nombretype = 3;
	}
	if (type == "electrik") {
		p_nombretype = 4;
	}
	if (type == "glace") {
		p_nombretype = 5;
	}
	if (type == "combat") {
		p_nombretype = 6;
	}
	if (type == "poison") {
		p_nombretype = 7;
	}
	if (type == "sol") {
		p_nombretype = 8;
	}
	if (type == "vol") {
		p_nombretype = 9;
	}
	if (type == "psy") {
		p_nombretype = 10;
	}
	if (type == "insecte") {
		p_nombretype = 11;
	}
	if (type == "roche") {
		p_nombretype = 12;
	}
	if (type == "spectre") {
		p_nombretype = 13;
	}
	if (type == "dragon") {
		p_nombretype = 14;
	}
	if (type == "tenebres") {
		p_nombretype = 15;
	}
	if (type == "acier") {
		p_nombretype = 16;
	}
} 
//constructeur de copie
Pokemonstock::Pokemonstock(Pokemon acopier)
{
	Pokemon::Pokemon(acopier.p_getid(), acopier.p_getnom(), acopier.p_gettype(), acopier.p_getposx(), acopier.p_getposy(), acopier.p_getpvmax(), acopier.p_getatk(), acopier.p_getatkspe(),
		acopier.p_getdef(), acopier.p_getdefspe(), acopier.p_getvit(), acopier.p_getevdonne(), acopier.p_gettypeev());
	ps_pvrestant = acopier.p_getpvmax();
} 
//pour initialiser toutes lesattaques d'un coup, chaque paramètre est une attaque
void Pokemonstock::ps_setatq(Attaque attaque1, Attaque attaque2, Attaque attaque3, Attaque attaque4)
{
	ps_listeatq[0] = attaque1;
	ps_listeatq[1] = attaque2;
	ps_listeatq[2] = attaque3;
	ps_listeatq[3] = attaque4;
} 
//destructeur par défaut
Pokemonstock :: ~Pokemonstock()
{

} 
//récupérer les pvs restant
int Pokemonstock::ps_getpvrestant()
{
	return ps_pvrestant;
} 
//récupérer l'attaque à la position n
Attaque Pokemonstock::ps_getattaque(int n)
{
	return ps_listeatq[n];
}
//changer l'id, utile à la capture, car l'id temporaire des pokémons est celle du pokédex, on crée une nouvelle id à l'insertion dans boite, donc il faut la changer
void Pokemonstock::ps_setID(int newid)
{
	p_ID = newid;
}
//opération de fin de combat
//si le pokémon a gagné (mis les pvs du pokémon sauvage à 0) alors il gagne des evs dépendant de son ennemi
//mettre les pvs à 0 si il est ko
void Pokemonstock::ps_fincombat(Pokemonstock cepokemon, Pokemonstock ciblevaincue, bool win)
{
	if (win == true)//ajout des evs
	{
		if (ciblevaincue.p_gettypeev() == "atk")
		{
			p_atk += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "atkspe")
		{
			p_atkspe += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "def")
		{
			p_def += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "defspe")
		{
			p_defspe += ciblevaincue.p_getevdonne();
		}
		if (ciblevaincue.p_gettypeev() == "vit")
		{
			p_vit += ciblevaincue.p_getevdonne();
		}
	}
	//dans tout les cas, actualiser les pvs actuels
	ps_pvrestant = cepokemon.ps_getpvrestant();
	if (ps_pvrestant < 0)
	{
		ps_pvrestant = 0;//pas de pvs sous 0
	}
} 
//soigner le pokémon (n'actualise PAS dans la base de données)
void Pokemonstock::ps_heal()
{
	ps_pvrestant = p_pvmax;
} 
//initialiser une attaque donné à la position i
void Pokemonstock::ps_setUneAttaque(Attaque attaque, int i)
{
	ps_listeatq[i] = attaque;
}
//affichage du pokémon avec ses attaques, pour l'affichage dans la boite et l'équipe dans le pc
std::string Pokemonstock::ps_getAffichage()
{
	std::string textString;
	textString = "ID: " + std::to_string(p_ID)
		+ "\nType:\t" + p_type
		+ "\nAttaque:\t" + std::to_string(p_atk) + "\tAttaque Speciale:\t" + std::to_string(p_atkspe)
		+ "\nDefense:\t" + std::to_string(p_def) + "\tDefense Speciale:\t" + std::to_string(p_defspe)
		+ "\nVitesse:\t" + std::to_string(p_vit) + "\tPV:\t" + std::to_string(ps_pvrestant)+"/"+std::to_string(p_pvmax)
		+ "\nAttaques:\n" + ps_listeatq[0].a_getAffichage() + "\n" + ps_listeatq[1].a_getAffichage() + "\n" + ps_listeatq[2].a_getAffichage() + "\n" + ps_listeatq[3].a_getAffichage();
	/*sf::Text text((sf::String) textString, font, 20);

	text.setPosition(610, 740);
	text.setFillColor(sf::Color::White);*/
	return textString;
}