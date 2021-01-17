#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include "CorpClase.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{



	Comenzi_DDL x;
	Comenzi_DML m;
	Romb d;
	Comenzi * comanda;
	GestioneazaFisiere fisiere;
	cout << "**********" <<"**************************" <<   "**********" << endl;
	cout << "|         " << " BUN VENIT IN BAZA DE DATE " << "         |" << endl;
	cout << "|         " << "       1.COMENZI DDL       " << "         |" << endl;
	cout << "|         " << "       2.COMENZI DML       " << "         |" << endl;
	cout << "|         " << "       3.EXIT              " << "         |" << endl;
	cout << "**********" << "**************************" << "**********" << endl;

	cout << endl;
	fisiere.getTabele();
	int nrTabele = fisiere.getNrTabele();
	if (nrTabele > 0)
	{
		fisiere.afiseazaNumeFisiereOrdine();
		Tabela* vectorTabele = fisiere.getVectorTabele();
		d.setVectorTabele(vectorTabele, nrTabele);

	}
	if (argc > 5)
	{
		cout << "NU SE POT INTRODUCE MAI MULT DE 5 ARGUMENTE";
	}
	else
	{


		for (int i = 1; i < argc; ++i)
		{
			ifstream MyReadFile(argv[i]);
			string myText;
			
			while (getline(MyReadFile, myText)) {
				
				char* sir = new char[myText.length() + 1];
				strcpy(sir, myText.c_str());

				d.desparte(sir, 1);

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



		}


		cout << endl;
	
		int nr = 0;
		int ok = 0;
	
		
		while (true)
		{
			cout << endl;
			cout << "Introdu numarul optiunii dorite :";
			char op[200];
			cin.getline(op, 200);
			if ((atoi(op) < 0 || atoi(op) > 3) && strlen(op) == 1)
			{
				cout << "Optiunea introdusa nu exista" << endl;
			}
			else
			{
			
				
				char sirul[250];
				switch (atoi(op))
				{
				case 1:
					cout << "Ati ales comenzi DDL" << endl;
					cout << "Comenzi DDL :" << endl;
					cout << "1.CREATE TABLE" << endl;
					cout << "2.DROP TABLE" << endl;
					cout << "3.DISPLAY TABLE" << endl;



					cout << "Introduceti o comanda valida : ";
					
					cin.getline(sirul, 250);
					d.desparte(sirul, 1);
					nr++;
					if (d.tipComanda() == 1)
					{

						d.Comenzi_DDL::parseazaComanda();


					}
					else
					{
						cout << "Comanda gresita" << endl;
					}
					break;
					
				
				case 2:
				
					cout << "Ati ales comenzi DML" << endl;
					cout << "Comenzi DML :" << endl;
					cout << "1.INSERT INTO" << endl;
					cout << "2.SELECT FROM" << endl;
					cout << "3.UPDATE WHERE" << endl;
					cout << "4.DELETE " << endl;

					cout << "Introduceti o comanda valida : ";
					
					cin.getline(sirul, 250);
					d.desparte(sirul, 1);
					nr++;
					if (d.tipComanda() == 0)
					{
						
						d.Comenzi_DML::parseazaComanda();


					}
					else
					{
						cout << "Comanda gresita" << endl;
					}
					break;
					
				
				case 3:
				
					cout << "Va multumim pentru utilizare.Datele introduse au fost salvate !";
					
					return 0;
				
				}
			}
			
			






		}

	}
}
