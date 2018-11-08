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

Dresseur::Dresseur(float x)
{
	//il faudrait faire une requete sql pour charger le bon dresseur
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
	//faut aussi charger ses pokemons => requete sql !
	/*
	std::string myConnString = "Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb";
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	//une requete avec un innerjoin
	char SQLQuery[] = "SELECT * FROM pokeunique WHERE b_idboite==0";//ecrire la requete sql
	do
	{
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
		{
			break;
		}
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		{
			break;
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
		{
			break;
		}
		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
		{
			break;
		}
		SQLCHAR retConString[1024];
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
		//switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokeliketestlocal.accdb", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokeliketestlocal.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
		//remplacer la ligne commenté par celle effective évite l'erreur HY090 (nom trop long poiur la source de DB)
		//maintenant gérons l'erreur IM002 : datasource not found
		{
		case SQL_SUCCESS:
			break;
		case SQL_SUCCESS_WITH_INFO:
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}
		if (retCode == -1)
		{
			break;
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
		{
			break;
		}
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			std::cout << "je rentre ici" << std::endl;
			char name[256];
			char type[256];
			int xsprite;
			int ysprite;
			int pv = 80;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_INTEGER, &xsprite, sizeof(xsprite), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &ysprite, sizeof(ysprite), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_INTEGER, &pv, sizeof(pv), NULL);
				std::cout << name << "  " << type << xsprite << "  " << ysprite << "  " << pv << std::endl;
				//SQL_C_DEFAULT
				//SQL_VARBINARY vs SQL_C_BINARY : type dans sql vs type dans c
				//SQL_INTEGER, 
			}
		}
	} while (FALSE);//do required to break loop if pb happens
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);*/
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
void Dresseur::d_healequipe()
{
	for (int i = 0; i < 6; i++)
	{
		d_equipe[i].ps_heal();
	}
}