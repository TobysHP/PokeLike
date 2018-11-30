#pragma once
#include "Dresseur.h"
#include <cstdlib>
#include "Fonctions.h"
#include "Pokemon.h"
#include "Pokemonstock.h"
#include "Pokemoncombat.h"
#include "Combat.h"
#include <chrono>
#include <thread>
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
int const sizemot = 20;
void showSQLError(unsigned int handletype, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	//diagnostic of the record of the input in the fct (return a state in sql state)
	//it tests if an error has occured
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, SQLState, NULL, message, 1024, NULL))
	{
		std::cout << "SQL driver message : " << message << "\nSQL state :" << SQLState << std::endl;
	}
}
void chargerIdsNomsDresseurs(int tableauDesId[], std::string tableauDesNoms[]) {
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery = "Select * from dresseur";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			int i = 0;
			
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS&&i<4)
			{
				char nom[sizemot];
				int id;
				std::string lenom;
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &nom, sizeof(nom), NULL);
				tableauDesId[i] = id;
				lenom=nom;
				tableauDesNoms[i] = lenom;
				std::cout << tableauDesNoms[i] << std::endl;
				i++;
			}
		}
	} while (false);
	std::cout << "je vais sortir de la fct" << std::endl;
	system("pause");
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}
std::vector<Pokemon> chargerLePokedex()
{
	std::vector<Pokemon> lePokedex;
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery = "SELECT * FROM pokemonpokedex";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		

		else//c'est ici que je get mes données !
		{
			std::cout << "Chargement du Pokedex, veuillez patientez" << std::endl;
			int const sizemot = 20;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				int id;
				char name[sizemot];
				char type[sizemot];
				int xsprite;
				int ysprite;
				int pvmax;
				int atk;
				int def;
				int atkspe;
				int defspe;
				int vit;
				int evdonne;
				char typeev[sizemot];
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_INTEGER, &xsprite, sizeof(xsprite), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &ysprite, sizeof(ysprite), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_INTEGER, &pvmax, sizeof(pvmax), NULL);
				SQLGetData(SQLStatementHandle, 7, SQL_INTEGER, &atk, sizeof(atk), NULL);
				SQLGetData(SQLStatementHandle, 8, SQL_INTEGER, &def, sizeof(def), NULL);
				SQLGetData(SQLStatementHandle, 9, SQL_INTEGER, &atkspe, sizeof(atkspe), NULL);
				SQLGetData(SQLStatementHandle, 10, SQL_INTEGER, &defspe, sizeof(defspe), NULL);
				SQLGetData(SQLStatementHandle, 11, SQL_INTEGER, &vit, sizeof(vit), NULL);
				SQLGetData(SQLStatementHandle, 12, SQL_INTEGER, &evdonne, sizeof(evdonne), NULL);
				SQLGetData(SQLStatementHandle, 13, SQL_CHAR, &typeev, sizeof(typeev), NULL);
				std::string leName(name);
				std::string leType(type);
				std::string leTypeEv(typeev);
				Pokemon lePokemon(id, leName, leType, xsprite, ysprite, pvmax, atk, atkspe, def, defspe, vit, evdonne, leTypeEv);
				lePokedex.push_back(lePokemon);
				//SQL_C_DEFAULT
				//SQL_VARBINARY vs SQL_C_BINARY : type dans sql vs type dans c
				//SQL_INTEGER, 
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	std::cout << "Fin Chargement" << std::endl;

	std::system("pause");
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	return lePokedex;
}   
Dresseur chargerDresseur(int idDresseurACharger, int facteurGraphique)
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	Dresseur monDresseur;
	int compteur = 0;
	std::string SQLQuery = "SELECT * FROM dresseur WHERE d_iddresseur="+std::to_string(idDresseurACharger);
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			//std::cout << "je rentre ici" << std::endl;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS&&compteur<1)
			{
				//std::cout << "je charge mes datas" << std::endl;
				int id;
				char name[sizemot];
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
				std::string lenom(name);
				monDresseur = Dresseur(facteurGraphique, id, lenom);
				compteur = 1;
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	//je vais charger ensuite son numéro de boite et d'équipe
	compteur = 0;
	SQLQuery = "SELECT b_idboite FROM boite WHERE d_iddresseur = " +std::to_string(idDresseurACharger) + " ORDER BY b_idboite" ;
	//order by car quand on crée les boites, on sait que la première sera toujours l'équipe et la seconde la boite
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			std::cout << "je rentre ici" << std::endl;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS && compteur < 1)
			{
				int idequipe;
				int idboite;
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &idequipe, sizeof(idequipe), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_INTEGER, &idboite, sizeof(idboite), NULL);
				monDresseur.d_setIDEquipe(idequipe);
				monDresseur.d_setIDBoite(idboite);
				compteur = 1;
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	return monDresseur;
} 
void creerDresseurEtBoite() {
	std::cout << "veillez saisir le nom du dresseur à insérer" << std:: endl;
	std::string nomDresseurACreer;
	std::cin.clear();
	do 
	{
		std::getline(std::cin, nomDresseurACreer);
	} while (nomDresseurACreer.size() > sizemot);
	//insérer le dresseur dans la db
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery = "INSERT INTO dresseur (d_nomdresseur) values('" + nomDresseurACreer + "')";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			/*if (SQL_SUCCESS != SQLEndTran(SQL_HANDLE_ENV, SQLEnvHandle, SQL_COMMIT))//commit : il faut trouver une fct pour commit ! 
			{
				std::cout << "commit est un echec" << std::endl;
			}
			else {
				std::cout << "Insertion du Dresseur" << nomDresseurACreer << " réussie !" << std::endl;
			}*/
			std::cout << "insert dresseur reussie" << std::endl;
			//system("pause");
		}
	} while (false);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//maintenant faut retrieve son id pour créer les boites
	SQLQuery = "SELECT Max(d_iddresseur) from dresseur";//le dresseur venant d'être créer ayant l'id maximal (id à increment auto), c'est le plus simple pour retrieve le name du dresseur
	//evite le problème de 2 dresseurs ont le meme name
	int id;
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				std::cout << "j'ai récupéré mon id, elle vaut : "<< id << std::endl;
			}
		}
	} while (false);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//maintenant je vais lui coller une equipe et une boite, pas oublier de commit ces opérations
	SQLQuery = "insert into boite (b_nomboite, d_iddresseur) values ('Equipe'," + std::to_string(id) + ")";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			/*if (SQL_SUCCESS != SQLEndTran(SQL_HANDLE_ENV, SQLEnvHandle, SQL_COMMIT))//commit : il faut trouver une fct pour commit ! 
			{
				std::cout << "commit est un echec" << std::endl;
			}
			else {
				std::cout << "Insertion de l'équipe  réussie !" << std::endl;
			}*/
			std::cout << "Insertion de l'équipe  réussie !" << std::endl;
			//system("pause");
		}
	} while (false);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	SQLQuery = "insert into boite (b_nomboite, d_iddresseur) values ('Boite'," + std::to_string(id) + ")";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			/*if (SQL_SUCCESS != SQLEndTran(SQL_HANDLE_ENV, SQLEnvHandle, SQL_COMMIT))//commit : il faut trouver une fct pour commit ! 
			{
				std::cout << "commit est un echec" << std::endl;
			}
			else {
				std::cout << "Insertion de la boite réussie !" << std::endl;
			}*/
			std::cout << "Insertion de la boite réussie !" << std::endl;
		}
	} while (false);
	//mnt libérer les ressources
	std::system("pause");
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

}    
void supprimerUnDresseurDansDB(int idDresseurASupprimer)
{
	/*pour supprimer un dresseur dans la db, il faut : 
		-vider la table de jointure attaquepokede-pokeunique des attaques possédées par les pokemon possédé par le dresseur
		-supprimer les pokémons du dresseur, aussi bien dans sa boite que dans son équipe
		-supprimer la boite et l'équipe du dresseur
		-supprimer l'enregistrement correspondant au dresseur
	ces 4 "étapes" seront gérées à l'aide de 4 requêtes, 
	le "problème" est qu'on supprimer depuis le menu principal, du coup on a seulement accès à l'id et au nom du dresseur
	de fait je dois d'abord charger le numéro de sa boite et de son équipe pour procéder à la suppression
	et c'est aussi pour cela que le paramètre à passer à cette fonction est un entier et pas un dresseur
	donc cette étape de récupérer ces chiffres est la première priorité ! 
	en fait non : en y réfléchissant bien y'a moyen de construct d'autres query qui permettent de se passer de çà, voir les query que je suggère ici
	*/

	//charger le numéro de la boite et de l'équipe
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery = "DELETE *FROM attaquepokeunique WHERE pu_idpokeunique in (SELECT pu_idpokeunique FROM pokeunique INNER JOIN boite ON pokeunique.b_idboite=boite.b_idboite WHERE boite.d_iddresseur="+std::to_string(idDresseurASupprimer) +")";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			std::cout << "j'ai clean attaque pokéunique pour le dresseur" << std::endl;
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//ici suppression de tout les pokéuniques associé au dresseur à supp
	SQLQuery = "DELETE * from pokeunique WHERE pu_idpokeunique IN (SELECT pu_idpokeunique FROM pokeunique INNER JOIN boite ON pokeunique.b_idboite=boite.b_idboite WHERE boite.d_iddresseur=" + std::to_string(idDresseurASupprimer) + ")";
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			std::cout << "j'ai clean pokéunique pour le dresseur" << std::endl;
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//ici on supprime la boite et "l'équipe" du dresseur
	SQLQuery = "DELETE * FROM boite WHERE d_iddresseur=" + std::to_string(idDresseurASupprimer);
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			std::cout << "j'ai clean boite et équipe pour le dresseur" << std::endl;
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//enfin mnt on supprime le dresseur à proprement parler
	SQLQuery = "DELETE * FROM dresseur WHERE d_iddresseur=" + std::to_string(idDresseurASupprimer);
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			std::cout << "j'ai clean le dresseur" << std::endl;
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
} 

void chargerPokemonDresseur(Dresseur &leDresseur)
{
	//va devenir 2 méthodes de dresseur : chargerEquipe et chargerBoite
}
void chargerAttaquePokemonDresseur(Dresseur &leDresseur)
{
	//chaque pokémon aura une méthode chargerAttaque
	//il suffira de l'appeler quand nécéssaire, ou au chargement des pokémons (! de bien fermer une requete avant d'en faire une autre, donc de charger d'abord les pkmns betement, puis pour chacun load ses attaques
} 


void Dresseur::d_chargerEquipe()
{
	//on vide toujours quand on charge
	d_equipe.empty();
	//puis seulement je load
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery = "SELECT * FROM pokeunique WHERE b_idboite=" + std::to_string(d_idEquipe);
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}


		else//c'est ici que je get mes données !
		{
			int const sizemot = 20;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				int id;
				char name[sizemot];
				char type[sizemot];
				int xsprite;
				int ysprite;
				int pvmax;
				int atk;
				int def;
				int atkspe;
				int defspe;
				int vit;
				int evdonne;
				char typeev[sizemot];
				int rare=0;
				int pvActifs;
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_INTEGER, &xsprite, sizeof(xsprite), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &ysprite, sizeof(ysprite), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_INTEGER, &pvmax, sizeof(pvmax), NULL);
				SQLGetData(SQLStatementHandle, 7, SQL_INTEGER, &atk, sizeof(atk), NULL);
				SQLGetData(SQLStatementHandle, 8, SQL_INTEGER, &def, sizeof(def), NULL);
				SQLGetData(SQLStatementHandle, 9, SQL_INTEGER, &atkspe, sizeof(atkspe), NULL);
				SQLGetData(SQLStatementHandle, 10, SQL_INTEGER, &defspe, sizeof(defspe), NULL);
				SQLGetData(SQLStatementHandle, 11, SQL_INTEGER, &vit, sizeof(vit), NULL);
				SQLGetData(SQLStatementHandle, 12, SQL_INTEGER, &evdonne, sizeof(evdonne), NULL);
				SQLGetData(SQLStatementHandle, 13, SQL_CHAR, &typeev, sizeof(typeev), NULL);
				SQLGetData(SQLStatementHandle, 14, SQL_INTEGER, &pvActifs, sizeof(rare), NULL);
				std::string leName(name);
				std::string leType(type);
				std::string leTypeEv(typeev);
				Pokemonstock lePokemon(id, leName, leType, xsprite, ysprite, pvmax, atk, atkspe, def, defspe, vit,  evdonne, leTypeEv, pvActifs);
				d_equipe.push_back(lePokemon);
				//SQL_C_DEFAULT
				//SQL_VARBINARY vs SQL_C_BINARY : type dans sql vs type dans c
				//SQL_INTEGER, 
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	std::cout << "Fin Chargement" << std::endl;
	std::system("pause");
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//mnt pour toutes les données chargées, il faut charger les attaques ! 
	std::vector<Pokemonstock> ::iterator it;
	for (it = d_equipe.begin(); it != d_equipe.end(); it++)
	{
		it->ps_chargerAttaques();
	}
}
void Dresseur::d_chargerBoite()
{
	//on vide toujours quand on charge
	d_boite.empty();
	//puis seulement je load
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery = "SELECT * FROM pokeunique WHERE b_idboite=" + std::to_string(d_idBoite);
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}


		else//c'est ici que je get mes données !
		{
			int const sizemot = 20;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				int id;
				char name[sizemot];
				char type[sizemot];
				int xsprite;
				int ysprite;
				int pvmax;
				int atk;
				int def;
				int atkspe;
				int defspe;
				int vit;
				int evdonne;
				char typeev[sizemot];
				int rare = 0;
				int pvActifs;
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_INTEGER, &xsprite, sizeof(xsprite), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &ysprite, sizeof(ysprite), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_INTEGER, &pvmax, sizeof(pvmax), NULL);
				SQLGetData(SQLStatementHandle, 7, SQL_INTEGER, &atk, sizeof(atk), NULL);
				SQLGetData(SQLStatementHandle, 8, SQL_INTEGER, &def, sizeof(def), NULL);
				SQLGetData(SQLStatementHandle, 9, SQL_INTEGER, &atkspe, sizeof(atkspe), NULL);
				SQLGetData(SQLStatementHandle, 10, SQL_INTEGER, &defspe, sizeof(defspe), NULL);
				SQLGetData(SQLStatementHandle, 11, SQL_INTEGER, &vit, sizeof(vit), NULL);
				SQLGetData(SQLStatementHandle, 12, SQL_INTEGER, &evdonne, sizeof(evdonne), NULL);
				SQLGetData(SQLStatementHandle, 13, SQL_CHAR, &typeev, sizeof(typeev), NULL);
				SQLGetData(SQLStatementHandle, 14, SQL_INTEGER, &pvActifs, sizeof(rare), NULL);
				std::string leName(name);
				std::string leType(type);
				std::string leTypeEv(typeev);
				Pokemonstock lePokemon(id, leName, leType, xsprite, ysprite, pvmax, atk, atkspe, def, defspe, vit, evdonne, leTypeEv, pvActifs);
				d_boite.push_back(lePokemon);
				//SQL_C_DEFAULT
				//SQL_VARBINARY vs SQL_C_BINARY : type dans sql vs type dans c
				//SQL_INTEGER, 
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	std::cout << "Fin Chargement" << std::endl;

	std::system("pause");
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	//charger les attaques
	std::vector<Pokemonstock> ::iterator it;
	for (it = d_equipe.begin(); it != d_equipe.end(); it++)
	{
		it->ps_chargerAttaques();
	}
}

void Pokemonstock::ps_chargerAttaques()
{
	std::string SQLQuery = "SELECT * FROM attaquepokedex WHERE ap_nomattaque IN (SELECT a_nomattaque FROM attaquepokedex INNER JOIN attaquepokeunique ON attaquepokeunique.a_nomattaque=attaquepokedex.ap_nomattaque WHERE attaquepokeunique.pu_idpokeunique="+std::to_string(this->p_ID)+")";
	int compteur = 0;
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			//std::cout << "je rentre ici" << std::endl;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS && compteur < 1)
			{
				//std::cout << "je charge mes datas" << std::endl;
				char name[sizemot];
				char type[sizemot];
				int valdeg;
				char natdeg[sizemot];
				int coefset;
				char natset[sizemot];
				int statut;
				float precision;
				SQLGetData(SQLStatementHandle, 1, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_INTEGER, &valdeg, sizeof(valdeg), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_CHAR, &natdeg, sizeof(natdeg), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &coefset, sizeof(coefset), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_CHAR, &natset, sizeof(natset), NULL);
				SQLGetData(SQLStatementHandle, 7, SQL_CHAR, &statut, sizeof(statut), NULL);
				SQLGetData(SQLStatementHandle, 8, SQL_FLOAT, &precision, sizeof(precision), NULL);
				std::string lename(name);
				std::string letype(type);
				std::string lenatdeg(natdeg);
				std::string lenatset(natset);
				Attaque rajouter(lename, letype, valdeg, coefset, lenatdeg, lenatset, precision, statut);
				ps_listeatq[compteur] = rajouter;
				compteur++; 
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}  

Pokemonstock creerUnPokemonRandom()
{
	int rarete = (rand() % 3) + 1;
	Pokemonstock lePokemon;
	//premièrement get un pokemon random, le paramètre est géré dans le main, ou pas et il suffit de le faire ici
	std::string SQLQuery = "Select TOP 1 * from pokemonpokedex where ppx_rarete =" +std::to_string(rarete) + " ORDER BY rnd(pokemonpokedex.ppx_idpokemon)";
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			int const sizemot = 20;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				int id;
				char name[sizemot];
				char type[sizemot];
				int xsprite;
				int ysprite;
				int pvmax;
				int atk;
				int def;
				int atkspe;
				int defspe;
				int vit;
				int evdonne;
				char typeev[sizemot];
				SQLGetData(SQLStatementHandle, 1, SQL_INTEGER, &id, sizeof(id), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_INTEGER, &xsprite, sizeof(xsprite), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &ysprite, sizeof(ysprite), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_INTEGER, &pvmax, sizeof(pvmax), NULL);
				SQLGetData(SQLStatementHandle, 7, SQL_INTEGER, &atk, sizeof(atk), NULL);
				SQLGetData(SQLStatementHandle, 8, SQL_INTEGER, &def, sizeof(def), NULL);
				SQLGetData(SQLStatementHandle, 9, SQL_INTEGER, &atkspe, sizeof(atkspe), NULL);
				SQLGetData(SQLStatementHandle, 10, SQL_INTEGER, &defspe, sizeof(defspe), NULL);
				SQLGetData(SQLStatementHandle, 11, SQL_INTEGER, &vit, sizeof(vit), NULL);
				SQLGetData(SQLStatementHandle, 12, SQL_INTEGER, &evdonne, sizeof(evdonne), NULL);
				SQLGetData(SQLStatementHandle, 13, SQL_CHAR, &typeev, sizeof(typeev), NULL);
				std::string leName(name);
				std::string leType(type);
				std::string leTypeEv(typeev);
				Pokemonstock unPokemon(id, leName, leType, xsprite, ysprite, pvmax, atk, atkspe, def, defspe, vit, evdonne, leTypeEv, pvmax);//pv actif = pvmax qunad on rencontre un pokemon
				lePokemon = unPokemon;
				//SQL_C_DEFAULT
				//SQL_VARBINARY vs SQL_C_BINARY : type dans sql vs type dans c
				//SQL_INTEGER, 
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	//maintenant mettre des attaques
	SQLQuery = "SELECT TOP 4 * FROM attaquepokedex WHERE ap_" +lePokemon.p_gettype()+"ok= 1  ORDER BY rnd(attaquepokedex.ap_valdegat)";
	int compteur = 0;
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
		switch (SQLConnect(SQLConnectionHandle, (SQLCHAR*)"Pokelike_test", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0))//(SQLConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"Provider = Microsoft.ACE.OLEDB.12.0; Data Source = D:\Documents\OneDrive\OneDrive - UMONS\Polytech\BAB3 IG\Big Data Base de Données\Projet\Pokelike\Pokelike\Pokelike.accdb", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
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
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.c_str(), SQL_NTS))
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else//c'est ici que je get mes données !
		{
			//std::cout << "je rentre ici" << std::endl;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS && compteur < 1)
			{
				//std::cout << "je charge mes datas" << std::endl;
				char name[sizemot];
				char type[sizemot];
				int valdeg;
				char natdeg[sizemot];
				int coefset;
				char natset[sizemot];
				int statut;
				float precision;
				SQLGetData(SQLStatementHandle, 1, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &type, sizeof(type), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_INTEGER, &valdeg, sizeof(valdeg), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_CHAR, &natdeg, sizeof(natdeg), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_INTEGER, &coefset, sizeof(coefset), NULL);
				SQLGetData(SQLStatementHandle, 6, SQL_CHAR, &natset, sizeof(natset), NULL);
				SQLGetData(SQLStatementHandle, 7, SQL_CHAR, &statut, sizeof(statut), NULL);
				SQLGetData(SQLStatementHandle, 8, SQL_FLOAT, &precision, sizeof(precision), NULL);
				std::string lename(name);
				std::string letype(type);
				std::string lenatdeg(natdeg);
				std::string lenatset(natset);
				Attaque rajouter(lename, letype, valdeg, coefset, lenatdeg, lenatset, precision, statut);
				lePokemon.ps_setUneAttaque(rajouter, compteur);
				compteur++;
			}
		}
	} while (FALSE);//do required to break loop if pb happens*/
	//mnt libérer les ressources
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	return lePokemon;
}





