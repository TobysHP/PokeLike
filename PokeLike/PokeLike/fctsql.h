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