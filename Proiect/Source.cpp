#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include "Clase.h"

using namespace std;

int main()
{
	Comenzi_DDL x;
	Comenzi_DML m;
	Romb d;
	char** sir;
	sir = new char* [100];
	int nr = 0;
	//char* numeColoana = new char[20];
	//strcpy(numeColoana, "nume");
	//char* valoareImplicita = new char[20];
	//strcpy(valoareImplicita, "nume");
	//int lungimeColoana = 10;
	//tipColoana tip = (tipColoana)1;
	//
	//Coloana c,f;

	//f.setLungimeColoana(-1);
	//cout << (c <= f) << endl;
	//cout << (c == f) << endl;
	//c.setLungimeColoana(20);
	//cout << (c == f) << endl;
	//c = c + 10;
	//c =  ++c;
	//c = c++;
	//cout << !c << endl;
	//cout << (char*)(c) << endl;
	//cout << c.getLungimeColoana() << endl;
	//Tabela  t;
	//cin >> t;
	//cout << t;
	cout << "Introduceti comanda cu litere mari (FAZA 1)";
	while (true)
	{

		try
		{	
			cout << endl;
			cout << "Introduceti o comanda valida: ";
			sir[nr] = new char[200];
			cin.getline(sir[nr], 200);
			d.desparte(sir[nr], 1);
			nr++;
			if (d.tipComanda() == 0)
			{
				/*d.afiseazaComanda();*/
				d.Comenzi_DML::parseazaComanda();


			}
			else if (d.tipComanda() == 1)
			{
				/*d.afiseazaComanda();*/
				d.Comenzi_DDL::parseazaComanda();

			}
			else
			{
				cout << "Comanda este gresita" << endl;
			}
		}

		catch (exception& e)
		{
			cout << "Standard exception: " << e.what() << endl;
		}

	}
}