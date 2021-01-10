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
	GestioneazaFisiere fisiere;
	fisiere.getTabele();
	int nrTabele = fisiere.getNrTabele();
	if (nrTabele > 0)
	{
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
			// Use a while loop together with the getline() function to read the file line by line
			while (getline(MyReadFile, myText)) {
				// Output the text from the file
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
		char** sir;
		sir = new char* [100];
		int nr = 0;
		while (true)
		{

			try
			{

				cout << endl << "Introduceti o comanda valida: " << endl;
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
}
