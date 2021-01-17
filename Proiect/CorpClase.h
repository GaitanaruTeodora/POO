#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

using namespace std;

enum tipColoana { tip_text = 1, tip_integer = 2, tip_float = 3 };

class Coloana
{
private:
	char* nume_coloana;
	char* valoareImplicita;
	int lungime_coloana;
	tipColoana tip;

public:
	Coloana()
	{
		nume_coloana = new char[9];
		strcpy_s(nume_coloana, 9, "DEFAULT");
		valoareImplicita = new char[9];
		strcpy_s(nume_coloana, 9, "IMPLICIT");
		lungime_coloana = 0;
		tip = (tipColoana)1;
	}
	Coloana(char* nume_coloana, int lungime_coloana = 255)
	{
		this->nume_coloana = new char[strlen(nume_coloana) + 1];
		strcpy_s(this->nume_coloana, strlen(nume_coloana) + 1, nume_coloana);
		this->lungime_coloana = lungime_coloana;
	}
	Coloana(char* nume_coloana, char* valoareImplicita, int lungime_coloana, tipColoana tip)
	{
		this->nume_coloana = new char[strlen(nume_coloana) + 1];
		strcpy_s(this->nume_coloana, strlen(nume_coloana) + 1, nume_coloana);
		this->lungime_coloana = lungime_coloana;
		this->valoareImplicita = new char[strlen(valoareImplicita) + 1];
		strcpy_s(this->valoareImplicita, strlen(valoareImplicita) + 1, valoareImplicita);
		this->tip = tip;
	}
	Coloana(const Coloana& c)
	{
		this->lungime_coloana = c.lungime_coloana;
		this->nume_coloana = new char[strlen(c.nume_coloana) + 1];
		strcpy_s(this->nume_coloana, strlen(c.nume_coloana) + 1, c.nume_coloana);
		this->tip = c.tip;
		this->valoareImplicita = new char[strlen(c.valoareImplicita) + 1];
		strcpy_s(valoareImplicita, strlen(c.valoareImplicita) + 1, c.valoareImplicita);
	}
	Coloana& operator = (const Coloana& c)
	{
		if (this->nume_coloana != nullptr)
		{
			delete[]this->nume_coloana;
		}
		if (this->valoareImplicita != nullptr)
		{
			delete[]this->valoareImplicita;
		}
		this->lungime_coloana = c.lungime_coloana;

		this->nume_coloana = new char[strlen(c.nume_coloana) + 1];
		strcpy_s(this->nume_coloana, strlen(c.nume_coloana) + 1, c.nume_coloana);
		this->tip = c.tip;
		this->valoareImplicita = new char[strlen(c.valoareImplicita) + 1];
		strcpy_s(this->valoareImplicita, strlen(c.valoareImplicita) + 1, c.valoareImplicita);

		return *this;
	}
	bool operator == (const Coloana& c)
	{
		if (strcmp(this->nume_coloana, c.nume_coloana) != 0 || strcmp(this->valoareImplicita, c.valoareImplicita) != 0 || this->lungime_coloana != c.lungime_coloana || this->tip != tip)
		{
			return false;
		}
		return true;
	}
	bool operator <= (const Coloana& c)
	{
		return (this->lungime_coloana <= c.lungime_coloana);

	}
	Coloana operator+(int valoare)
	{
		if (valoare > 0)
		{

			Coloana copie = *this;
			copie.lungime_coloana += valoare;
			return copie;
		}
		else
			throw exception("Valoare nula");
	}
	bool operator!()
	{
		return lungime_coloana > 0;
	}
	Coloana operator++(int i)
	{
		Coloana copie = *this;
		copie.lungime_coloana++;
		return copie;
	}
	Coloana operator++()
	{
		this->lungime_coloana++;
		return *this;
	}
	explicit operator char*()
	{
		return nume_coloana;
	}
	~Coloana()
	{
		if (this->nume_coloana != nullptr)
		{
			delete[]this->nume_coloana;
		}
		if (this->valoareImplicita != nullptr)
		{
			delete[]this->valoareImplicita;
		}
	}
	char* getValoareImplicita()
	{
		return valoareImplicita;
	}
	char* setValoareImplicita(char* val)
	{
		valoareImplicita = new char[strlen(val) + 1];
		strcpy_s(valoareImplicita, strlen(val) + 1, val);
		return valoareImplicita;
	}
	void setNumeColoana(char* nume_coloana)
	{
		this->nume_coloana = new char[strlen(nume_coloana) + 1];
		strcpy_s(this->nume_coloana, strlen(nume_coloana) + 1, nume_coloana);
	}
	bool setLungimeColoana(char* lungime)
	{
		bool ok = true;
		int nr = 0;
		for (int i = 0; i < strlen(lungime); i++)
		{
			if (!isdigit(lungime[i]))
			{
				ok = false;
				break;
			}
			else
			{
				int x = (int)lungime[i] - 48;
				nr = nr * 10 + x;
			}

		}
		if (ok == false)
		{

			return false;
		}
		else
		{

			this->lungime_coloana = nr;
			return true;
		}
	}

	void setLungimeColoana(int lungimeColoana)
	{
		this->lungime_coloana = lungimeColoana;
	}
	
	bool setTipColoana(char* tip)
	{

		if (isdigit(tip[0]) && strlen(tip) == 1)
		{
			if (strcmp("2", tip) == 0)
			{
				tipColoana  tipN = (tipColoana)2;
				this->tip = tipN;

				return true;
			}
			else if (strcmp("1", tip) == 0)
			{
				tipColoana  tipN = (tipColoana)1;
				this->tip = tipN;

				return true;
			}
			else if (strcmp("0", tip) == 0)
			{
				tipColoana  tipN = (tipColoana)0;
				this->tip = tipN;

				return true;
			}
			else
			{
				return false;
			}


		}

		return false;

	}
	tipColoana getTipColoana()
	{
		return tip;
	}

	char* getDenumire()
	{
		return nume_coloana;
	}
	int getLungimeColoana()
	{
		return lungime_coloana;
	}

	friend ostream& operator<<(ostream&, Coloana);
	friend istream& operator>>(istream&, Coloana&);
};

istream& operator>>(istream& in, Coloana& c)
{
	cout << "Lungime coloana: ";
	char lungime[200];
	bool ok = true;
	bool verificComanda = false;

	cin.getline(lungime, 200);
	for (int i = 0; i < strlen(lungime); i++)
	{
		if (!isdigit(lungime[0]))
		{
			ok = false;
			break;
		}
	}
	if (ok == true)
	{
		c.lungime_coloana = (int)lungime;
		verificComanda = true;
	}
	else
	{
		cout << "Lungimea trebuie sa fie numar intreg ";
		c.lungime_coloana = 0;
	}
	cout << "Nume coloana: ";
	string buffer;
	in >> buffer;
	if (c.nume_coloana != nullptr)
	{
		delete[] c.nume_coloana;
	}
	c.nume_coloana = new char[buffer.length() + 1];
	strcpy_s(c.nume_coloana, buffer.length() + 1, buffer.c_str());

	string buffer2;
	cout << "Valoare implicita: ";
	in >> buffer2;
	if (c.valoareImplicita != nullptr)
	{
		delete[] c.valoareImplicita;
	}
	c.valoareImplicita = new char[buffer2.length() + 1];
	strcpy_s(c.valoareImplicita, buffer2.length() + 1, buffer2.c_str());

	cout << "Tipul coloanei: ";
	char buffer3[20];
	in >> buffer3;

	char* x = new char[strlen(buffer3)];
	strcpy(x, buffer3);

	if (strlen(x) == 1 && isdigit(x[0]))
	{
		int n = (int)(x[0]);

		if (n > 0 && n <= 3)
		{
			tipColoana tipNou = (tipColoana)(x[0]);
			c.tip = tipNou;
		}
		else
		{
			cout << "Valoarea unui tip este intre 1 si 3";
			tipColoana tipNou = (tipColoana)(1);
			c.tip = tipNou;
		}

	}
	else
	{
		cout << "Tipul  trebuie sa fie un numar  intreg intre 1 si 3";
	}
	return in;
}

ostream& operator<<(ostream& out, Coloana c)
{

	out << "Denumirea coloanei: ";
	if (c.nume_coloana != nullptr)
	{
		out << c.nume_coloana << endl;
	}
	out << "Lungimea coloanei: " << c.lungime_coloana << endl;
	
	out << "Valoarea implicita: ";
	if (c.valoareImplicita != nullptr)
	{
		out << c.valoareImplicita << endl;

	}
	out << "Tip coloana " << c.tip;
	return out;
}

class Rand
{
private:
	int nr_coloane;
	char** elemente;

public: 
	    


	Rand()
	{
		elemente = nullptr;
		nr_coloane = 0;
	}
	Rand(int nr_coloane, char** elemente)
	{
		this->nr_coloane = nr_coloane;
		this->elemente = new char* [nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->elemente[i] = elemente[i];
		}
	}
	Rand(int nr_coloane)
	{
		this->nr_coloane = nr_coloane;
		elemente = nullptr;
	}

	Rand(const Rand& r)
	{
		this->nr_coloane = r.nr_coloane;
		this->elemente = new char* [nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->elemente[i] = new char[strlen(r.elemente[i]) + 1];
			strcpy(this->elemente[i], r.elemente[i]);
		}
	}
	Rand& operator = (const Rand& r)
	{
		this->nr_coloane = r.nr_coloane;
		delete[]elemente;
		this->elemente = new char* [nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->elemente[i] = new char[strlen(r.elemente[i]) + 1];
			strcpy_s(this->elemente[i], strlen(r.elemente[i]) + 1, r.elemente[i]);

		}

		return *this;
	}
	bool operator < (const Rand& r)
	{
		for (int i = 0; i < nr_coloane; i++)
		{
			if (elemente[i] < r.elemente[i])
			{
				return true;
			}
			if (elemente[i] > r.elemente[i])
			{
				return false;
			}
		}
		return true;
	}
	char* operator[](int index)
	{
		if (index >= 0 && index < nr_coloane)
		{
			return elemente[index];
		}
		throw exception("INDEX INVALID!");
	}
	bool operator!()
	{
		return nr_coloane > 0;
	}
	Rand operator++()
	{
		this->nr_coloane++;
		return *this;
	}
	Rand operator ++(int i)
	{
		Rand copie = *this;
		this->nr_coloane++;
		return copie;
	}
	Rand operator+(int valoare)
	{
		if (valoare > 0)
		{
			Rand copie = *this;
			copie.nr_coloane += valoare;
			return copie;
		}
	}
	explicit operator int()
	{
		return nr_coloane;
	}
	bool operator == (const Rand& r)
	{

		if (this->nr_coloane != r.nr_coloane)
		{
			return false;
		}
		else {
			for (int i = 0; i < nr_coloane; i++)
			{
				if (strcmp(this->elemente[i], r.elemente[i]) != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool operator <= (const Rand& r)
	{
		return (this->nr_coloane <= r.nr_coloane);

	}
	~Rand()
	{
		delete[] elemente;
	}
	void setNrColoane(int nr_coloane)
	{
		this->nr_coloane = nr_coloane;
	}
	void setElemente(char** elemente, int nr_coloane)
	{
		this->nr_coloane = nr_coloane;
		delete[]this->elemente;

		this->elemente = new char* [nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->elemente[i] = new char[strlen(elemente[i]) + 1];
			strcpy(this->elemente[i], elemente[i]);

		}
	}
	int getNrColoane()
	{
		return nr_coloane;
	}
	char* elementPozitie(int index)
	{
		return elemente[index];
	}
	Rand setElementPozitie(int index, string val)
	{
		
		char* x = new char[val.length() + 1];
		strcpy_s(x, val.length() + 1, val.c_str());
		elemente[index] = new char[strlen(x) + 1];
		strcpy_s(elemente[index], strlen(x) + 1, x);
		
		return *this;

	}

	friend ostream& operator<<(ostream&, Rand);
	friend istream& operator>>(istream&, Rand&);
	friend ofstream& operator<<(ofstream&, Rand);
};

ostream& operator << (ostream& out, Rand r)
{
	for (int i = 0; i < r.getNrColoane(); i++)
	{
		cout << r.elemente[i] << " ";
	}
	cout << endl;
	return out;
}

istream& operator >> (istream& in, Rand& r)
{
	cout << "Numar coloane: ";
	char lungime[200];
	bool ok = true;
	in >> r.nr_coloane;
	if (r.elemente != nullptr)
	{
		delete[] r.elemente;
	}
	r.elemente = new char* [r.nr_coloane];
	for (int i = 0; i < r.nr_coloane; i++)
	{
		cout << "Citeste elementul " << i + 1 << endl;
		string buffer;
		in >> buffer;

		r.elemente[i] = new char[buffer.length() + 1];
		strcpy_s(r.elemente[i], buffer.length() + 1, buffer.c_str());
	}

	/*cin.getline(lungime, 200);
	for (int i = 0; i < strlen(lungime); i++)
	{
		if (!isdigit(lungime[i]))
		{
			ok = false;
			break;
		}
	}
	if (ok == true)
	{
		if (int(lungime) > 0)
		{
			r.nr_coloane = (int)lungime;

			for (int k = 0; k < r.nr_coloane; k++)
			{
				cout << "Citeste elementul " << k+1 << endl;
				cin >> r.elemente[k];
			}
		}
		else
		{
			cout << "Numarul de coloane trebuie sa fie un numar pozitiv" << endl;
		}



	}
	else
	{
		cout << "Lungimea trebuie sa fie numar intreg ";


	}*/

	return in;
}

class Tabela
{
private:
	Rand* randuri;
	int nr_randuri;
	Coloana* coloane;
	int nr_coloane;
	char* denumire_tabela;
	static string denumire_BD;
	const int numarMaximColoane;
	int lungimiColoane[20];
	int numberOfBytes ;

public:
	bool verificaNumar(char* element)
	{
		for (int i = 0; i < strlen(element); i++)
		{
			if (!isdigit(element[i]))
			{
				return false;
			}
		}
		return true;
	}
	Rand inlocuiesteValoareaImplicita(Rand rand)
	{
		for (int i = 0; i < nr_coloane; i++)
		{
			Coloana coloanaActuala = coloane[i];
			if (strcmp(rand.elementPozitie(i), " ") == 0)
			{
				rand.setElementPozitie(i, coloanaActuala.getValoareImplicita());
			}
		}
		return rand;

	}
	int verificaRestrictii(Rand rand)
	{
		int ok = 0;
		for (int i = 0; i < nr_coloane; i++)
		{
			Coloana coloanaActuala = coloane[i];
			char* element = rand.elementPozitie(i);
			if (strlen(element) > coloanaActuala.getLungimeColoana())
			{
				
				cout << "Coloana " << coloanaActuala.getDenumire() << " are lungimea maxima " << coloanaActuala.getLungimeColoana() << ". Dimensiunea elementului " << element << " depaseste aceasta conditie" << endl;
				return 1;
			}
			if (coloanaActuala.getTipColoana() == 1)
				{
				if (verificaNumar(element) == true)
				{
					cout << "Elementul " << element << " nu este de tip text";
					return 1;
				}

			}
			else if (coloanaActuala.getTipColoana() == 2)
			{
				if (verificaNumar(element) == false)
				{
					cout << "Elementul " << element << " nu este de tip integer";
					return 1;
				}
			}
			else if (coloanaActuala.getTipColoana() == 3)
			{
				if (verificaNumar(element) == false)
				{
					cout << "Elementul " << element << " nu este de tip float";
					return 1;
				}
			}
		}
		return 0;
	}
	Tabela() :numarMaximColoane(20)
	{
		randuri = nullptr;
		nr_randuri = 0;
		coloane = nullptr;
		nr_coloane = 0;
		denumire_tabela = nullptr;

	}
	int verificaColoana(char* numeColoana)
	{
		int index = -1;
		for (int i = 0; i < nr_coloane; i++)
		{
			if (strcmp(coloane[i].getDenumire(), numeColoana) == 0)
			{
				index = i;
			}
		}
		return index;
	}
	void select(char* numeColoana)
	{
		int index = -1;
		for (int i = 0; i < nr_coloane; i++)
		{
			if (strcmp(coloane[i].getDenumire(), numeColoana) == 0)
			{
				index = i;
			}
		}
		if (index != -1)
		{
			cout << "Coloana : " << numeColoana << endl;
			for (int i = 0; i < nr_randuri; i++)
			{
				cout << randuri[i].elementPozitie(index) << endl;

			}
		}

	}
	Tabela(char* denumire, int nr_coloane, Coloana* coloane) :numarMaximColoane(20)
	{

		randuri = nullptr;
		nr_randuri = 0;
		this->nr_coloane = nr_coloane;
		denumire_tabela = new char[strlen(denumire) + 1];
		strcpy(denumire_tabela, denumire);

		this->coloane = new Coloana[nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->coloane[i] = coloane[i];
		}

		for (int i = 0; i < nr_coloane; i++)
		{
			lungimiColoane[i] = coloane[i].getLungimeColoana();
		}

	}
	Tabela(int nr_coloane, Coloana* coloane) :numarMaximColoane(20)
	{
		randuri = nullptr;
		nr_randuri = 0;
		this->nr_coloane = nr_coloane;
		denumire_tabela = nullptr;


		this->coloane = new Coloana[nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->coloane[i] = coloane[i];
		}

		for (int i = 0; i < nr_coloane; i++)
		{
			lungimiColoane[i] = coloane[i].getLungimeColoana();
		}
	}
	Tabela(const Tabela& t) :numarMaximColoane(20)
	{
		this->denumire_tabela = new char[strlen(t.denumire_tabela) + 1];
		strcpy(this->denumire_tabela, t.denumire_tabela);
		this->nr_randuri = t.nr_randuri;
		this->nr_coloane = t.nr_coloane;
		this->randuri = new Rand[nr_randuri];
		for (int i = 0; i < nr_randuri; i++)
		{
			this->randuri[i] = t.randuri[i];
		}
		this->coloane = new Coloana[nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->coloane[i] = t.coloane[i];
		}
	}
	void serializare()
	{
		string den = denumire_tabela;
		string d = "Detalii/" + den + ".bin";
		char* x = new char[d.length() + 1];
		strcpy(x, d.c_str());

		if (remove(x) != 0)
			cout << "";
		else
			cout << "";
		ofstream f("Detalii/" + den + ".bin", ios::binary);

		f.write((char*)&nr_randuri, sizeof(nr_randuri));
		for (int i = 0; i < nr_randuri; i++)
		{
			for (int j = 0; j < randuri[i].getNrColoane(); j++)
			{
				int lenght = strlen(randuri[i].elementPozitie(j));
				f.write((char*)&lenght, sizeof(lenght));
				f.write((char*)randuri[i].elementPozitie(j), lenght+1);
				/*	cout << "am serializat" << randuri[i].elementPozitie(j) << endl;*/

			}

		}

		f.close();
	}
	int getNumberOfBytes()
	{
		return numberOfBytes;
	}
	void deserializare()
	{
		string den = denumire_tabela;
		ifstream f("Detalii/" + den + ".bin", ios::binary);

		int length = 0;
		f.read((char*)&nr_randuri, sizeof(nr_randuri));
		

	/*	cout << "Deserializare nr randuri " << nr_randuri << endl;*/
		randuri = new Rand[nr_randuri];
		randuri->setNrColoane(nr_coloane);
		/*cout << "Deserializare nr COLOANE " << nr_coloane << endl;*/

		for (int i = 0; i < nr_randuri; i++)
		{
			char** el = new char* [nr_coloane];
			int nr = 0;
			for (int j = 0; j < nr_coloane; j++)
			{
				length = 0;
				f.read((char*)&length, sizeof(length));
				el[nr] = new char[length + 1];


				f.read((char*)el[nr], length+1);

				nr++;
			}
			randuri[i].setElemente(el, nr_coloane);
		}
		f.close();
	}

	Tabela& operator = (const Tabela& t)
	{
		this->denumire_tabela = new char[strlen(t.denumire_tabela) + 1];
		strcpy(this->denumire_tabela, t.denumire_tabela);
		this->nr_randuri = t.nr_randuri;
		this->nr_coloane = t.nr_coloane;
		this->randuri = new Rand[nr_randuri];
		for (int i = 0; i < nr_randuri; i++)
		{
			this->randuri[i] = t.randuri[i];
		}
		this->coloane = new Coloana[nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->coloane[i] = t.coloane[i];
		}
		return *this;
	}
	bool operator == (const Tabela& t)
	{

		if (this->nr_randuri != t.nr_randuri)
		{
			return false;
		}
		return true;
	}
	Rand operator[](int index)
	{
		if (index >= 0 && index < nr_coloane)
		{
			return randuri[index];
		}
		throw exception("INDEX INVALID!");
	}

	bool operator <= (const Tabela& t)
	{
		return (this->nr_randuri <= t.nr_randuri);

	}
	Tabela operator+(Rand rand)
	{


		Tabela copie = *this;
		delete[]copie.randuri;
		copie.nr_randuri++;
		copie.randuri = new Rand[copie.nr_randuri];
		for (int i = 0; i < copie.nr_randuri - 1; i++)
		{
			copie.randuri[i] = this->randuri[i];
		}
		copie.randuri[copie.nr_randuri - 1] = rand;

		return copie;


	}
	bool operator!()
	{
		return nr_randuri > 0;
	}
	Tabela operator++(int i)
	{
		Tabela copie = *this;
		delete[]copie.randuri;
		Rand rand;
		copie.nr_randuri++;
		copie.randuri = new Rand[copie.nr_randuri];
		for (int i = 0; i < copie.nr_randuri - 1; i++)
		{
			copie.randuri[i] = this->randuri[i];
		}
		copie.randuri[copie.nr_randuri - 1] = rand;
		return copie;
	}
	Tabela operator++()
	{

		Tabela copie = *this;
		delete[]copie.randuri;
		Rand rand;
		copie.nr_randuri++;
		copie.randuri = new Rand[copie.nr_randuri];
		for (int i = 0; i < copie.nr_randuri - 1; i++)
		{
			copie.randuri[i] = this->randuri[i];
		}
		copie.randuri[copie.nr_randuri - 1] = rand;
		return copie;
	}
	~Tabela()
	{
		delete[]randuri;
		delete[]coloane;
	}
	explicit operator char* ()
	{
		return denumire_tabela;
	}

	Rand* getRanduri()
	{
		return randuri;
	}

	void setDenumire(char* denumire)
	{
		denumire_tabela = new char[strlen(denumire) + 1];
		strcpy(denumire_tabela, denumire);

	}
	void setNrColoane(int nr_coloane)
	{
		this->nr_coloane = nr_coloane;
	}
	void setColoane(Coloana* coloane)
	{
		this->coloane = new Coloana[nr_coloane];
		for (int i = 0; i < nr_coloane; i++)
		{
			this->coloane[i] = coloane[i];
		}
	}
	Rand getRand(int index)
	{
		return randuri[index];
	}
	void setRand(int index, Rand rand)
	{
		randuri[index] = rand;
	}
	Coloana getColoane(int index)
	{
		return coloane[index];
	}
	Coloana* getColoane()
	{
		return coloane;
	}
	int getNrRanduri() {
		return nr_randuri;
	}
	int getNrColoane()
	{
		return nr_coloane;
	}
	char* getDenumire()
	{
		return denumire_tabela;
	}

	void display()// select *
	{
		for (int i = 0; i < nr_randuri; i++)
		{
			cout << randuri[i] << endl;

		}
	}
	void select(char** conditie, int dim)
	{
		bool gasit = false;
		int index;
		for (int i = 0; i < nr_coloane; i++)
		{
			if (coloane[i].getDenumire() == conditie[0])
			{
				index = i;
				gasit = true;
				break;
			}
		}
		if (gasit == true)
		{
			for (int i = 0; i < nr_randuri; i++)
			{
				if (conditie[1] == "=")
				{
					if (randuri[i].elementPozitie(index) == conditie[2])
					{
						Rand bun = randuri[i];
						cout << bun;
					}
				}
				if (conditie[1] == ">")
				{
					if (randuri[i].elementPozitie(index) > conditie[2])
					{
						Rand bun = randuri[i];
						cout << bun;
					}
				}
				if (conditie[1] == "=")
				{
					if (randuri[i].elementPozitie(index) == conditie[2])
					{
						Rand bun = randuri[i];
						cout << bun;
					}
				}

			}

		}

	}


	void afiseaza() {
		cout << "Denumire tabela " << denumire_tabela << endl;
	}
	void DELETE(string numeColoana, string valoare)
	{
		int pozitie;
		for (int i = 0; i < nr_coloane; i++)
		{
			if (numeColoana == coloane[i].getDenumire())
			{
				pozitie = i;
			}
		}
		int nr = 0;

		
		if (nr_randuri == 1)
		{
			nr_randuri = 0;
			delete[]randuri;
		}
		else
		{
			
			/*Rand* randNou = new Rand[nr_randuri-1];
			for (int i = 0; i < nr_randuri; i++)
			{
				if (valoare != randuri[i].elementPozitie(pozitie))
				{
					randNou[nr] = randuri[i];
					nr++;
				}
			}
			delete[]randuri;
			nr_randuri = nr_randuri - 1;
			this->randuri = randNou;*/
		}
		
	}
	void insereazaRand(Rand rand)
	{

		Rand* copie = new Rand[nr_randuri];
		copie = this->randuri;
		this->nr_randuri = this->nr_randuri + 1;

		delete[]this->randuri;
		this->randuri = new Rand[this->nr_randuri + 1];

		if (this->nr_randuri == 1)
		{
			this->randuri[0] = rand;
		}
		else if (this->nr_randuri == 2)
		{

			this->randuri[0] = copie[0];

			this->randuri[1] = rand;

		}
		else
		{
			for (int i = 0; i < nr_randuri - 1; i++)
			{
				cout << copie[i] << endl;

			}

			/*this->randuri[nr_randuri - 1] = rand;*/

		}
	}

	void actualizeazaColoana(Coloana coloana)
	{
		Coloana* copie = coloane;
		nr_coloane++;
	}
	void setNumberOfBytes(int nr)
	{
		numberOfBytes = nr;
	}
	friend ofstream& operator << (ofstream&, Tabela);
	friend ostream& operator<<(ostream&, Tabela);
	friend istream& operator>>(istream&, Tabela&);
	friend ifstream& operator >>(ifstream&, Tabela&);
};

string Tabela::denumire_BD = "Database";
ifstream& operator>>(ifstream& in, Tabela& t)
{
	int nrOfBytes = 0;
	string buffer, buffer1, buffer2, buffer3, buffer4;
	in >> ws;
	getline(in, buffer);

	t.denumire_tabela = new char[buffer.length() + 1];
	nrOfBytes = nrOfBytes + buffer.length()+2;
	strcpy_s(t.denumire_tabela, buffer.length() + 1, buffer.c_str());

	in >> ws;
	getline(in, buffer);


	t.nr_coloane = atoi(buffer.c_str());
	nrOfBytes = nrOfBytes + buffer.length() + 2;
	t.coloane = new Coloana[t.nr_coloane];
	for (int i = 0; i < t.nr_coloane; i++)
	{
		in >> ws;
		getline(in, buffer1);
		nrOfBytes = nrOfBytes + buffer1.length() + 1;
		char* numeColoana = new char[buffer1.length() + 1];
		strcpy_s(numeColoana, buffer1.length() + 1, buffer1.c_str());

		t.coloane[i].setNumeColoana(numeColoana);

		in >> ws;

		getline(in, buffer2);
		nrOfBytes = nrOfBytes + buffer2.length() +2;
		char* tipColoana = new char[buffer2.length() + 1];
		strcpy(tipColoana, buffer2.c_str());
		t.coloane[i].setTipColoana(tipColoana);
		in >> ws;
		getline(in, buffer3);
		nrOfBytes = nrOfBytes + buffer3.length() + 2;
		char* lungimeColoana = new char[buffer3.length() + 1];
		strcpy(lungimeColoana, buffer3.c_str());
		t.coloane[i].setLungimeColoana(lungimeColoana);
		in >> ws;
		getline(in, buffer4);
		nrOfBytes = nrOfBytes + buffer4.length() + 2;
		char* valoareImplicita = new char[buffer4.length() + 1];
		strcpy(valoareImplicita, buffer4.c_str());
		t.coloane[i].setValoareImplicita(valoareImplicita);


	}
	t.numberOfBytes = nrOfBytes;
	return in;
}
ofstream& operator << (ofstream& out, Tabela t)
{
	out << t.denumire_tabela << endl;
	out << t.nr_coloane << endl;
	for (int i = 0; i < t.nr_coloane; i++)
	{
		out << t.coloane[i].getDenumire() << endl;
		out << t.coloane[i].getTipColoana() << endl;
		out << t.coloane[i].getLungimeColoana() << endl;
		out << t.coloane[i].getValoareImplicita() << endl;
	}
	out << t.nr_randuri << endl;

	return out;
}
ostream& operator << (ostream& out, Tabela t)
{
	out << "Denumire tabela: " << t.denumire_tabela << endl;
	
	for (int i = 0; i < t.nr_coloane; i++)
	{
		out << t.coloane[i] << " ";
	}
	cout << endl;
	if (t.nr_randuri == 0)
	{
		cout << "Nu exista randuri in tabel.";
	}
	else
	{
		out << "Nr Randuri: " << t.nr_randuri << endl;
		for (int i = 0; i < t.nr_coloane; i++)
		{
			out << t.coloane[i].getDenumire() << " ";
		}
		cout << endl;
		for (int i = 0; i < t.nr_randuri; i++)
		{
			out << t.randuri[i];
		}

	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Tabela& t)
{
	cout << "Denumire tabela: ";

	string buffer;
	in >> buffer;
	if (t.denumire_tabela != nullptr)
	{
		delete[] t.denumire_tabela;
	}
	t.denumire_tabela = new char[buffer.length() + 1];
	strcpy_s(t.denumire_tabela, buffer.length() + 1, buffer.c_str());
	cout << "Numar coloane";
	in >> t.nr_coloane;
	t.coloane = new Coloana[t.nr_coloane];
	for (int i = 0; i < t.nr_coloane; i++)
	{
		in >> t.coloane[i];
	}
	cout << "Nr randuri: ";
	int nr;
	in >> nr;
	t.nr_randuri = nr;

	t.randuri = new Rand[t.nr_randuri];
	for (int i = 0; i < t.nr_randuri; i++)
	{
		cout << "Cisteste randul " << i + 1 << endl;;
		in >> t.randuri[i];
	}


	return in;
}

class Comenzi
{
private:
	Tabela* vector_tabele;
	int nr_tabele;
	char** elemente;
	int dim;
public:
	Comenzi()
	{
		nr_tabele = 0;
		dim = 1;
		elemente = nullptr;
		vector_tabele = nullptr;
	}
	Comenzi(int nr_tabele, Tabela* vector_tabele, int dim, char** elemente)
	{
		this->nr_tabele = nr_tabele;
		this->vector_tabele = new Tabela[nr_tabele];
		for (int i = 0; i < nr_tabele; i++)
		{
			this->vector_tabele[i] = vector_tabele[i];
		}
		this->dim = dim;
		this->elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			this->elemente[i] = new char[strlen(elemente[i]) + 1];
			strcpy_s(this->elemente[i], strlen(elemente[i]) + 1, elemente[i]);
		}

	}
	Comenzi(const Comenzi& c)
	{
		this->nr_tabele = c.nr_tabele;
		this->vector_tabele = new Tabela[nr_tabele];
		for (int i = 0; i < nr_tabele; i++)
		{
			this->vector_tabele[i] = c.vector_tabele[i];
		}
		this->dim = c.dim;
		this->elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			this->elemente[i] = new char[strlen(c.elemente[i]) + 1];
			strcpy_s(this->elemente[i], strlen(c.elemente[i]) + 1, c.elemente[i]);
		}
	}
	bool operator!()
	{
		return nr_tabele > 0;
	}
	/*Comenzi operator++(int i)
	{
		Comenzi copie = *this;
		delete[]copie.vector_tabele;
		Tabela tabela;
		copie.nr_tabele++;
		copie.vector_tabele = new Tabela[copie.nr_tabele];
		for (int i = 0; i < copie.nr_tabele - 1; i++)
		{
			copie.vector_tabele[i] = this->vector_tabele[i];
		}
		copie.vector_tabele[copie.nr_tabele - 1] = tabela;
		return copie;
	}
	Comenzi operator++()
	{

		Comenzi copie = *this;
		delete[]copie.vector_tabele;
		Tabela tabela;
		copie.nr_tabele++;
		copie.vector_tabele = new Tabela[copie.nr_tabele];
		for (int i = 0; i < copie.nr_tabele - 1; i++)
		{
			copie.vector_tabele[i] = this->vector_tabele[i];
		}
		copie.vector_tabele[copie.nr_tabele - 1] = tabela;
		return copie;
	}*/
	explicit operator int()
	{
		return nr_tabele;
	}
	bool operator == (const Comenzi& c)
	{

		if (this->nr_tabele != c.nr_tabele)
		{
			return false;
		}
		return true;
	}
	Tabela operator[](int index)
	{
		if (index >= 0 && index < nr_tabele)
		{
			return vector_tabele[index];
		}
		throw exception("INDEX INVALID!");
	}

	bool operator <= (const Comenzi& c)
	{
		return (this->nr_tabele <= c.nr_tabele);

	}
	Comenzi& operator = (const Comenzi& c)
	{
		this->nr_tabele = c.nr_tabele;
		this->vector_tabele = new Tabela[nr_tabele];
		for (int i = 0; i < nr_tabele; i++)
		{
			this->vector_tabele[i] = c.vector_tabele[i];
		}
		this->dim = c.dim;
		this->elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			this->elemente[i] = new char[strlen(c.elemente[i]) + 1];
			strcpy_s(this->elemente[i], strlen(c.elemente[i]) + 1, c.elemente[i]);
		}

		return *this;
	}

	Comenzi(int dim, char** elemente)
	{
		this->dim = dim;
		this->elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			this->elemente[i] = new char[strlen(elemente[i]) + 1];
			strcpy(this->elemente[i], elemente[i]);
		}
	}
	void incarcaTabele()
	{
		//deschidem fisierele cu detalii despre crearea tabellelor si cream fiecare tabel in parte.
		  // deschidem fisierele cu descrieri si populam tabelele
		  //actualizam vectorul de tabele
	}

	int tipComanda()
	{
		string ins = "INSERT";
		string into = "INTO";
		string values = "VALUES";
		string wh = "WHERE";
		string sel = "SELECT";
		string upd = "UPDATE";
		string disp = "DISPLAY";
		string del = "DELETE";
		string from = "FROM";
		string drop = "DROP";
		string create = "CREATE";
		string table = "TABLE";
		string valoare = "";
		string imp = "IMPORT";
		if (ins == elemente[0] || del == elemente[0] || upd == elemente[0] || sel == elemente[0] || imp == elemente[0])
		{
			return 0;
		}
		else if (create == elemente[0] || drop == elemente[0] || disp == elemente[0])
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	int getDim()
	{
		return dim;
	}
	void setDim(int dim)
	{
		this->dim = dim;
	}
	char** getElemente()
	{
		return elemente;
	}
	void afiseazaTabele()
	{

		for (int i = 0; i < nr_tabele; i++)
		{
			cout << vector_tabele[i];
		}
	}
	void setElemente(char** elemente, int dim)
	{
		delete[]this->elemente;
		this->dim = dim;
		this->elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			this->elemente[i] = new char[strlen(elemente[i] + 1)];
			strcpy(this->elemente[i], elemente[i]);
		}

	}
	Tabela* getVectorTabele()
	{
		return vector_tabele;

	}
	void setVectorTabele(Tabela* tab, int nr_tabele)
	{

		this->nr_tabele = nr_tabele;
		this->vector_tabele = new Tabela[nr_tabele];
		for (int i = 0; i < nr_tabele; i++)
		{
			this->vector_tabele[i] = tab[i];
		}

	}

	int getNrTabele()
	{
		return nr_tabele;
	}
	void setNrTabele(int nr_tabele)
	{
		this->nr_tabele = nr_tabele;
	}

	char** verificaParanteze(int i, char** v, int dim, int& nr)
	{
		int p1 = 0;
		int p2 = 0;
		string deschisa = "(";
		string inchisa = ")";
		string semn = ";";
		string virgula = ",";

		char** valori;
		valori = new char* [dim - i - 1];
		for (int j = i; j < dim; j++)
		{

			//cout << v[j] << endl;
			/*if (deschisa == v[j])
			{

				p1++;
			}
			if (inchisa==v[j])
			{
				p2++;
			}*/
			if (numaraParantezaDeschisa(v[j]) == 1)
			{
				p1 = p1 + numaraParantezaDeschisa(v[j]);
				char* cuv = strtok(v[j], "(");
				valori[nr] = cuv;
				nr++;

			}
			else if (numaraParantezaInchisa(v[j]) == 1)
			{
				p2 = p2 + numaraParantezaInchisa(v[j]);
				char* cuv = strtok(v[j], ")");
				valori[nr] = cuv;
				nr++;

			}
			else if (j < dim - 1)
			{
				valori[nr] = v[j];
				nr++;
			}


		}
		/*cout << endl;
		cout << v[dim - 1] << endl;
		cout << strlen(v[dim - 1]) << endl;
		cout << v[dim - 1][strlen(v[dim - 1]) - 1];*/

		if (p1 == p2 && p1 == 1 && v[dim - 1][strlen(v[dim - 1]) - 1] == ';')
		{
			return valori;
		}
		else
		{
			nr = 0;
			return valori;
		}

	}
	int numaraParantezaDeschisa(char* cuv)
	{
		int nr = 0;
		for (int i = 0; i < strlen(cuv); i++)
		{
			if (cuv[i] == '(')
			{
				nr++;
			}
		}
		return nr;
	}
	int numaraParantezaInchisa(char* cuv)
	{
		int nr = 0;
		for (int i = 0; i < strlen(cuv); i++)
		{
			if (cuv[i] == ')')
			{
				nr++;
			}
		}
		return nr;
	}

	int contineParanteza(char* pch)
	{

		for (int i = 0; i < strlen(pch); i++)
		{
			if (pch[i] == '(') return 1;
			if (pch[i] == ')') return 2;
		}
		return 0;
	}


	char** desparteE(char* sir, int& dim)
	{
		int nr = 1;
		char delim[] = "=;";
		char** v;
		v = new char* [nr];

		char* token = strtok(sir, delim);
		while (token)
		{
			if (nr == 1)
			{

				v[0] = token;
			}
			else {
				char** copie = v;
				v = new char* [nr];
				for (int i = 0; i < nr - 1; i++)
				{
					v[i] = copie[i];
				}
				v[nr - 1] = token;
			}
			nr++;

			token = strtok(NULL, delim);
		}
		dim = nr;
		return v;
	}
	char** desparteE(char* sir, int& dim, char* car)
	{
		int nr = 1;
		char* delim = new char[2];
		strcpy(delim, car);
		char** v;
		v = new char* [nr];

		char* token = strtok(sir, delim);
		while (token)
		{
			if (nr == 1)
			{

				v[0] = token;
			}
			else {
				char** copie = v;
				v = new char* [nr];
				for (int i = 0; i < nr - 1; i++)
				{
					v[i] = copie[i];
				}
				v[nr - 1] = token;
			}
			nr++;

			token = strtok(NULL, delim);
		}
		dim = nr;
		return v;
	}
	char** desparteP(char* sir, int& dim)
	{
		int nr = 1;
		char delim[] = "()";
		char** v;
		v = new char* [nr];

		char* token = strtok(sir, delim);
		while (token)
		{
			if (nr == 1)
			{

				v[0] = token;
			}
			else {
				char** copie = v;
				v = new char* [nr];
				for (int i = 0; i < nr - 1; i++)
				{
					v[i] = copie[i];
				}
				v[nr - 1] = token;
			}
			nr++;

			token = strtok(NULL, delim);
		}
		dim = nr;
		return v;
	}
	int primaParanteza(char* v)
	{
		for (int i = 0; i < strlen(v); i++)
		{
			if (v[i] == '(') return 0;
			if (v[1] == ')') return 1;
		}
		return -1;
	}
	int numarVirgule(char* x)
	{
		int nr = 0;

		for (int i = 0; i < strlen(x); i++)
		{
			if (x[i] == ',') { nr++; }

		}

		return nr;


	}

	bool toateVirgule(char* x)
	{
		int nr = 0;
		bool ok = true;
		for (int i = 0; i < strlen(x); i++)
		{
			if (x[i] != ',')
			{
				ok = false;
				break;
			}
		}
		if (ok == true)
		{
			return true;
		}

		return false;

	}
	void desparte(char* str, int dim) // Id = 2 
	{
		this->dim = dim;
		char** v;
		char* pch;
		v = new char* [dim];

		pch = strtok(str, " ");
		while (pch != NULL)
		{
			char* el = pch;

			if (dim == 1)
			{

				v[0] = new char[strlen(el) + 1];
				v[0] = el;
				dim++;

			}
			else
			{

				char** copie = v;
				v = new char* [dim];
				for (int i = 0; i < dim - 1; i++)
				{
					v[i] = new char[strlen(copie[i]) + 1];
					v[i] = copie[i];
				}
				v[dim - 1] = new char[strlen(pch) + 1];
				v[dim - 1] = pch;

				dim++;


			}



			pch = strtok(NULL, " ");
		}
		dim--;
		delete[]elemente;
		this->dim = dim;
		this->elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			this->elemente[i] = new char[strlen(v[i]) + 1];
			this->elemente[i] = v[i];
		}

		litereMari();
		desparteC(';');
		eliminaParanteze();
	
		
		desparteVirgule();
		desparteC('=');

		
		

		/*parseazaComanda();*/
	}
	
	void litereMari()
	{
		char** copie = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			string el = elemente[i];
			transform(el.begin(), el.end(), el.begin(), ::toupper);
			copie[i] = new char[el.length()];
			strcpy(copie[i], el.c_str());

		}
		delete[]elemente;
		elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			
			elemente[i] = new char[strlen(copie[i])+1];
			strcpy(elemente[i], copie[i]);

		}
	}

	~Comenzi()
	{
		delete[]elemente;

	}




	void desparteC(char  car)
	{
		int nr = 0;
		char* egal = new char[2];
		if (car == '=')
		{
			strcpy(egal, "=");
		}
		else
		{
			strcpy(egal, ";");
		}

		for (int i = 0; i < dim; i++)
		{
			if (numara(elemente[i], car) > 0)
			{
				if (strlen(elemente[i]) == 1)
				{
					nr = nr + 0;
				}
				else if (elemente[i][0] != car && elemente[i][strlen(elemente[i]) - 1] != car)
				{
					nr = nr + 2;
				}
				else
				{
					nr = nr + 1;
				}
			}
		}
		int dimNou = dim + nr;

		char** c;
		c = new char* [dimNou];
		nr = 0;
		for (int i = 0; i < dim; i++)
		{
			if (numara(elemente[i], car) > 0)
			{
				if (elemente[i][0] != car && elemente[i][strlen(elemente[i]) - 1] != car)
				{
					int n = 1;
					char** x = desparteE(elemente[i], n, egal);
					c[nr] = new char[strlen(x[0])];
					strcpy(c[nr], x[0]);
					nr++;
					c[nr] = new char[strlen(egal)];
					strcpy(c[nr], egal);
					nr++;
					c[nr] = new char[strlen(x[1])];
					strcpy(c[nr], x[1]);
					nr++;
				}
				else if (elemente[i][0] == car && strlen(elemente[i]) > 1)
				{

					char* x = strtok(elemente[i], egal);
					/*	cout << x;*/
					c[nr] = new char[strlen(egal)];
					strcpy(c[nr], egal);
					nr++;
					c[nr] = new char[strlen(x)];
					strcpy(c[nr], x);
					nr++;
				}
				else if (elemente[i][strlen(elemente[i]) - 1] == car && strlen(elemente[i]) > 1)
				{

					char* x = strtok(elemente[i], egal);
					c[nr] = new char[strlen(x)];
					strcpy(c[nr], x);
					nr++;
					c[nr] = new char[strlen(egal)];
					strcpy(c[nr], egal);
					nr++;

				}
				else if (elemente[i][strlen(elemente[i]) - 1] == car && strlen(elemente[i]) > 1)
				{

					int n = 1;
					char** x = desparteE(elemente[i], n, egal);
					/*cout << x;*/
					for (int i = 0; i < strlen(elemente[i]) - 1; i++)
					{
						c[nr] = new char[strlen(x[0])];
						strcpy(c[nr], x[0]);
						nr++;
					}

					c[nr] = new char[strlen(egal)];
					strcpy(c[nr], egal);
					nr++;
				}
				else if (strlen(elemente[i]) == 1)
				{
					c[nr] = new char[strlen(elemente[i])];
					strcpy(c[nr], elemente[i]);
					nr++;
				}
				else
				{
					char* x = strtok(elemente[i], egal);

					c[nr] = new char[strlen(x)];
					strcpy(c[nr], x);
					nr++;
					c[nr] = new char[strlen(egal)];
					strcpy(c[nr], egal);
					nr++;
				}
			}
			else
			{
				c[nr] = new char[strlen(elemente[i])];
				strcpy(c[nr], elemente[i]);
				nr++;

			}

		}


		dim = nr;
		delete[]elemente;
		elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			elemente[i] = c[i];
		}

	}
	int numara(char* v, char caracter)
	{
		int nr = 0;
		for (int i = 0; i < strlen(v); i++)
		{
			if (v[i] == caracter)
			{
				nr++;
			}
		}
		return nr;
	}
	void eliminaParantezeRecursiv()
	{
		int nrParanteze = 0;
		for (int i = 0; i < dim; i++)
		{
			int pDeschisa = numaraParantezaDeschisa(elemente[i]);
			int pInchisa = numaraParantezaInchisa(elemente[i]);
			if (pDeschisa > 0 && elemente[i][0] == '(')
			{
				nrParanteze = nrParanteze + 1;
			}
			else if (pInchisa > 0 && elemente[i][strlen(elemente[i]) - 1] == ')')
			{
				nrParanteze = nrParanteze + 1;
			}
			
		}
		char** c;
		int dimNou = dim + nrParanteze;
		c = new char* [dimNou];
		
		int nr = 0; 
		char* car;
		char* car2;
		car = new char[2];
		car2 = new char[2];
		strcpy(car, "(");
		strcpy(car2, ")");
		for (int i = 0; i < dim; i++)
		{
			char* cop = new char[strlen(elemente[i])];
			strcpy(cop, elemente[i]);
			if (strlen(cop) > 1)
			{
				if (cop[0] == '(')
				{
					c[nr] = new char[strlen(car)];
					strcpy(c[nr], car);
					nr++;
					char* el = new char[strlen(cop) - 1];
						for (int k = 1; k<strlen(cop) ; k++)
						{ 
							
							el[k-1] = cop[k];
						}
					
					c[nr] = new char[strlen(el)];
					strcpy(c[nr], el);
					nr++;
					
				}
				else if (cop[strlen(cop) - 1] == ')')
				{
				
					char* el = new char[strlen(cop) - 1];
					
					for (int k = 0; k<strlen(cop)-1; k++)
					{
						el[k] = cop[k];
					}
					
					c[nr] = new char[strlen(el)];
					strcpy(c[nr], el);
					nr++;
					c[nr] = new char[strlen(car2)];
					strcpy(c[nr], car2);
					nr++;
				}
				else
				{
					c[nr] = new char[strlen(cop)];
					strcpy(c[nr], cop);
					nr++;
				}
			}
			else
			{
				c[nr] = new char[strlen(cop)];
				strcpy(c[nr], cop);
				nr++;
			}
		}
		dim = nr;
		delete[]elemente;
		elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			elemente[i] = new char[strlen(c[i])];
			strcpy(elemente[i], c[i]);
		}

	}
	void  eliminaParanteze()
	{
		char** c;
		int nrParanteze = 0;

		for (int i = 0; i < dim; i++)
		{
			int pDeschisa = numaraParantezaDeschisa(elemente[i]);
			int pInchisa = numaraParantezaInchisa(elemente[i]);
			if (pDeschisa == pInchisa && pDeschisa == 1)
			{
				if ((pInchisa) == strlen(elemente[i]))
				{
					nrParanteze = nrParanteze + pInchisa - 1;
				}
				else if ((pDeschisa) == strlen(elemente[i]))
				{
					nrParanteze = nrParanteze + pDeschisa - 1;

				}
				else if (((elemente[i][0] == ')' || elemente[i][0] == '(')) && ((elemente[i][strlen(elemente[i]) - 1] == ')' || elemente[i][strlen(elemente[i]) - 1] == '(')))
				{
					nrParanteze = nrParanteze + 2;

				}
				else if ((elemente[i][0] == ')' || elemente[i][0] == '('))
				{
					nrParanteze = nrParanteze + 3;

				}
				else if ((elemente[i][strlen(elemente[i]) - 1] == ')' || elemente[i][strlen(elemente[i]) - 1] == '('))
				{
					nrParanteze = nrParanteze + 3;

				}
				else
				{
					nrParanteze = nrParanteze + 4;

				}

			}
			else
			{
				nrParanteze = nrParanteze + pDeschisa + pInchisa;
			}

		}
		int dimNou = dim + nrParanteze;
		c = new char* [dimNou];
		int nr = 0;
		char* car;
		char* car2;
		car = new char[2];
		car2 = new char[2];
		strcpy(car, "(");
		strcpy(car2, ")");
		char* carDes = new char[2];
		char* carInch = new char[2];
		strcpy(carDes, "(");
		strcpy(carInch, ")");
		for (int i = 0; i < dim; i++)
		{

			char* cop = new char[strlen(elemente[i])];
			strcpy(cop, elemente[i]);
			if (numaraParantezaDeschisa(elemente[i]) == strlen(elemente[i]))
			{

				for (int j = 0; j < strlen(elemente[i]); j++)
				{
					c[nr] = new char[strlen(carDes)];
					strcpy(c[nr], carDes);
					nr++;
				}
			}
			else if (numaraParantezaInchisa(elemente[i]) == strlen(elemente[i]))
			{

				for (int j = 0; j < strlen(elemente[i]); j++)
				{
					c[nr] = new char[strlen(carInch)];
					strcpy(c[nr], carInch);
					nr++;
				}
			}
			else if (elemente[i][0] == '(' && elemente[i][strlen(elemente[i]) - 1] == ')')
			{

				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
				char* el = strtok(elemente[i], ")(");
				c[nr] = new char[strlen(el)];
				strcpy(c[nr], el);
				nr++;
				c[nr] = new char[strlen(car2)];
				strcpy(c[nr], car2);
				nr++;
			}
			else if (strlen(elemente[i]) > 1 && numaraParantezaDeschisa(elemente[i]) == 1 && numaraParantezaInchisa(elemente[i]) == 1)
			{

				int dimN;
				char** el = desparteP(elemente[i], dimN);


				if (cop[0] == '(')
				{

					c[nr] = new char[strlen(car) + 1];
					strcpy(c[nr], car);
					nr++;
					c[nr] = new char[strlen(el[0]) + 1];
					strcpy(c[nr], el[0]);
					nr++;
					c[nr] = new char[strlen(car2) + 1];
					strcpy(c[nr], car2);
					nr++;
					c[nr] = new char[strlen(el[1]) + 1];
					strcpy(c[nr], el[1]);
					nr++;


				}
				else if (cop[strlen(cop) - 1] == ')')
				{


					c[nr] = new char[strlen(el[0]) + 1];
					strcpy(c[nr], el[0]);
					nr++;
					c[nr] = new char[strlen(car) + 1];
					strcpy(c[nr], car);
					nr++;
					c[nr] = new char[strlen(el[1]) + 1];
					strcpy(c[nr], el[1]);
					nr++;
					c[nr] = new char[strlen(car2) + 1];
					strcpy(c[nr], car2);
					nr++;
				}

				else
				{

					c[nr] = new char[strlen(el[0]) + 1];
					strcpy(c[nr], el[0]);
					nr++;
					c[nr] = new char[strlen(car) + 1];
					strcpy(c[nr], car);
					nr++;
					c[nr] = new char[strlen(el[1]) + 1];
					strcpy(c[nr], el[1]);
					nr++;
					c[nr] = new char[strlen(car) + 1];
					strcpy(c[nr], car2);
					nr++;
					c[nr] = new char[strlen(el[2]) + 1];
					strcpy(c[nr], el[2]);
					nr++;
				}

			}
			else if (strlen(elemente[i]) > 1 && elemente[i][0] == '(')
			{
				char* car;
				car = new char[2];
				strcpy(car, "(");
				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
				char* el = strtok(elemente[i], "(");
				c[nr] = new char[strlen(el)];
				strcpy(c[nr], el);
				nr++;
			}
			else if (strlen(elemente[i]) > 1 && elemente[i][0] == ')')
			{
				char* car;
				car = new char[2];
				strcpy(car, ")");
				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
				char* el = strtok(elemente[i], ")");
				c[nr] = new char[strlen(el)];
				strcpy(c[nr], el);
				nr++;
			}
			else if (strlen(elemente[i]) > 1 && elemente[i][strlen(elemente[i]) - 1] == ')')
			{

				char* car;
				car = new char[2];
				strcpy(car, ")");
				char* el = strtok(elemente[i], ")");
				c[nr] = new char[strlen(el)];
				strcpy(c[nr], el);
				nr++;
				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
			}
			else if (strlen(elemente[i]) > 1 && elemente[i][strlen(elemente[i]) - 1] == '(')
			{

				char* car;
				car = new char[2];
				strcpy(car, "(");
				char* el = strtok(elemente[i], "(");
				c[nr] = new char[strlen(el)];
				strcpy(c[nr], el);
				nr++;
				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
			}

			else if (strlen(elemente[i]) > 1 && numaraParantezaDeschisa(elemente[i]) == 1)
			{
				char* car;
				car = new char[2];
				strcpy(car, "(");
				int dim;
				char** el = desparteP(elemente[i], dim);
				c[nr] = new char[strlen(el[0])];
				strcpy(c[nr], el[0]);
				nr++;
				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
				c[nr] = new char[strlen(el[1])];
				strcpy(c[nr], el[1]);
				nr++;

			}
			else if (strlen(elemente[i]) > 1 && numaraParantezaInchisa(elemente[i]) == 1)
			{
				char* car;
				car = new char[2];
				strcpy(car, ")");
				int dim;
				char** el = desparteP(elemente[i], dim);
				c[nr] = new char[strlen(el[0])];
				strcpy(c[nr], el[0]);
				nr++;
				c[nr] = new char[strlen(car)];
				strcpy(c[nr], car);
				nr++;
				c[nr] = new char[strlen(el[1])];
				strcpy(c[nr], el[1]);
				nr++;

			}
			else
			{
				c[nr] = new char[strlen(elemente[i])];
				strcpy(c[nr], elemente[i]);
				nr++;
			}

		}

		dim = nr;
		delete[]elemente;
		elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			elemente[i] = new char[strlen(c[i])];
			strcpy(elemente[i], c[i]);
		}


	}
	bool contineParanteza()
	{
		char paranteza1 ='(';
		char paranteza2 =')';
		for (int i = 0; i < dim; i++)
		{
			if (strlen(elemente[i]) > 1)
			{
				for (int j = 0; j < strlen(elemente[i]); j++)
				{
					if (paranteza1 == elemente[i][j] || paranteza2 == elemente[i][j])
					{
						return true;
					}
				}
			}
			
		}
		return false;

	}
	void desparteVirgule()
	{
		int  nrVirgule = 0;

		for (int i = 0; i < dim; i++)
		{
			int nr = numarVirgule(elemente[i]);

			if (nr > 0 && toateVirgule(elemente[i]))
			{
				nrVirgule = nrVirgule + nr - 1;
			}
			else if (nr > 0)
			{
				nrVirgule = nrVirgule + nr;
			}

		}
		int dimNou;
		dimNou = dim + nrVirgule;
		char** c;
		c = new char* [dimNou];
		char* virgula;
		virgula = new char[2];
		strcpy(virgula, ",");
		string x = "";
		int nr = 0;
		for (int i = 0; i < dim; i++)
		{
			char* copie = new char[strlen(elemente[i]) + 1];
			strcpy(copie, elemente[i]);

			if (toateVirgule(copie) == true)
			{

				for (int i = 0; i < strlen(copie); i++)
				{
					c[nr] = new char[2];
					strcpy(c[nr], virgula);
					nr++;
				}
			}
			else
			{
				int ok = 1;

				for (int j = 0; j < strlen(copie); j++)
				{
					if (copie[j] == ',')
					{
						if (x.length() > 0)
						{

							c[nr] = new char[x.length()];
							strcpy(c[nr], x.c_str());
							nr++;
							x = "";
							c[nr] = new char[strlen(virgula)];
							strcpy(c[nr], virgula);
							nr++;
						}
						else
						{
							c[nr] = new char[strlen(virgula)];
							strcpy(c[nr], virgula);
							nr++;
						}

					}
					else
					{
						x = x + copie[j];

					}
				}
				if (x.length() > 0)
				{

					c[nr] = new char[x.length() + 1];
					strcpy(c[nr], x.c_str());
					nr++;
					x = "";
				}
			}
		}

		dim = nr;
		delete[]elemente;
		elemente = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			elemente[i] = new char[strlen(c[i])];
			strcpy(elemente[i], c[i]);
		}
	}

	virtual void parseazaComanda() = 0;
	virtual void afiseazaComanda() = 0;
	


	void display(string denumire)
	{
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele[i].getDenumire() == denumire)
			{
				//cout << vector_tabele[i]; de facut supraicnarcarea << >> in toate clasele
				vector_tabele[i].display();
				gasit = true;
				break;
			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumire;
		}
	}
	void SELECT(string denumire, char** conditie, int dim) {

		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele[i].getDenumire() == denumire)
			{
				vector_tabele[i].select(conditie, dim);
				gasit = true;
				cout << "Am introdus un rand cu succes in tabela :" << denumire << endl;
				break;
			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumire;
		}
	}


	void DELETE(string denumireTabela, string numeColoana, string valoare)
	{
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele[i].getDenumire() == denumireTabela)
			{
				vector_tabele[i].DELETE(numeColoana, valoare);
				gasit = true;
				setVectorTabele(vector_tabele, nr_tabele);
				break;
			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumireTabela;
		}
	}
	friend istream& operator >>(istream&, Comenzi&);
	friend ostream& operator << (ostream&, Comenzi);
};

istream& operator >>(istream& in, Comenzi& c)
{
	cout << "Numar de tabele";
	in >> c.nr_tabele;
	c.vector_tabele = new Tabela[c.nr_tabele];
	for (int i = 0; i < c.nr_tabele; i++)
	{
		in >> c.vector_tabele[i];
	}
	return in;
}
//ostream& operator << (ostream& out, Comenzi c)
//{
//	cout << "Numar tabele : " << endl;
//	out << c.nr_tabele << endl;
//	for (int i = 0; i < c.nr_tabele; i++)
//	{
//		out << c.vector_tabele[i];
//	}
//	return out;
//}

class Comenzi_DML : virtual public Comenzi
{

public:
	Comenzi_DML() :Comenzi()
	{

	}
	

	bool verificaNumeTabel(char* denumire)
	{
		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool verifica = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele->getDenumire() == denumire)
			{
				verifica = true;
				break;
			}
		}
		return verifica;
	}
	void parseazaComanda() override
	{
		char** elemente = getElemente();
		int dim = getDim();

		string denumireTabel;
		string numeColoana = "";
		string egal = "=";
		string ins = "INSERT";
		string valoare = "";
		string upd = "UPDATE";
		string sel = "SELECT";
		string del = "DELETE";
		string into = "INTO";
		string set = "SET";
		string values = "VALUES";
		string table = "TABLE";
		string create = "CREATE";
		string from = "FROM";
		string al = "ALL";
		string wh = "WHERE";
		string terminal = ";";
		string virgula = ",";
		string denumire;
		string imp = "IMPORT";
		char* elDefault = new char[8];
		strcpy(elDefault, "default");
		string parantezaDeschisa = "(";
		string parantezaInchisa = ")";
		const char* lista[6] = { "INSERT","UPDATE","DELETE" };
		bool ok = true;

		if (dim == 4)
		{
			if (imp == elemente[0] && terminal == elemente[3])
			{
				string nume_tabela = elemente[1];
				string nume_fisier = elemente[2];
				IMPORT(nume_tabela, nume_fisier);
			}
		}

		else if (dim == 5)
		{
			if ((sel == elemente[0]) && (al == elemente[1]) && (from == elemente[2]) && (terminal == elemente[4]) && (dim == 5))
			{

				string numeTabel = elemente[3];
				selectAll(numeTabel);
			}
			else
			{
				cout << "Comanda gresita";
			}
		}

		else if (dim > 5)
		{

			if ((ins == elemente[0]) && (into == elemente[1]) && (values == elemente[3]) && terminal == elemente[dim - 1])
			{
				/*denumireTabel = new char[strlen(elemente[2]) + 1];*/
				denumireTabel = elemente[2];
				Rand rand;
				if (parantezaDeschisa == elemente[4] && parantezaInchisa == elemente[dim - 2])
				{
					/*Rand* rand =new Rand[]*/
					char** el = new char* [dim - 7];
					int nr = 0;
					for (int i = 5; i < dim - 2; i++)
					{

						if (virgula == elemente[i] && virgula == elemente[i + 1])
						{
							el[nr] = new char[strlen(elDefault)];
							strcpy(el[nr], elDefault);
							nr++;
							i++;


						}
						else
						{
							if (virgula != elemente[i])
							{
								el[nr] = new char[strlen(elemente[i])];
								strcpy(el[nr], elemente[i]);
								nr++;
							}


						}
					}

					Rand rand(nr, el);
					/*cout << "Nr este " << nr;
					for (int k = 0; k < nr; k++)
					{
						cout << el[k] << endl;
					}*/

					INSERT_INTO(denumireTabel, rand);
				}
				else
				{
					cout << "Comanda gresita";
				}


			}
			else if ((del == elemente[0]) && (from == elemente[1]) && (wh == elemente[3]) && terminal == elemente[dim - 1] && (egal == elemente[5]))
			{
				denumireTabel = elemente[2];
				numeColoana = elemente[4];
				valoare = elemente[6];
				DELETE(denumireTabel, numeColoana, valoare);

			}//UPDATE nume_tabela SET nume_coloană = valoare WHERE nume_coloană = valoare
			else if ((upd == elemente[0]) && (set == elemente[2]) && (egal == elemente[4]) && (wh == elemente[6]) && (egal == elemente[8]) && (dim == 11) && terminal == elemente[dim - 1] && (strcmp(elemente[3], elemente[7]) == 0))
			{
				string val1, val2;
				denumireTabel = elemente[1];
				numeColoana = elemente[3];
				val1 = elemente[5];
				val2 = elemente[9];
				UPDATE(denumireTabel, numeColoana, val1, val2);
			}
			else if ((sel == elemente[0]) && (parantezaDeschisa == elemente[1]) && (terminal == elemente[dim - 1]) && (from == elemente[dim - 3]) && (parantezaInchisa == elemente[dim - 4]))
			{
				string denTabela = elemente[dim - 2];
				bool ver = true;
				int nr_col = (dim - 4) / 2;

				char** coloaneSelect = new char* [nr_col];
				int nr = 0;
				for (int i = 2; i < dim - 4; i++)
				{
					if (i % 2 == 1)
					{
						if (virgula != elemente[i])
						{
							ver = false;
						}

					}
					else
					{

						coloaneSelect[nr] = new char[strlen(elemente[i]) + 1];
						strcpy(coloaneSelect[nr], elemente[i]);
						nr++;
					}
				}
				SELECT(denTabela, coloaneSelect, nr);
			}
			else
			{
				cout << "Comanda gresita";
			}
		}
		else
		{

			cout << "Comanda gresita";
		}
	}
	void IMPORT(string denumireTabela, string numeFisier)
	{
		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool ok = true;
		bool gasit = false;


		for (int i = 0; i < nr_tabele; i++)
		{

			if (denumireTabela == vector_tabele[i].getDenumire())
			{
				gasit = true;

				ifstream ip(numeFisier);
				if (!ip.is_open())
				{
					cout << "Nu se poate deschide fisierul" << numeFisier << endl;
				}
				else {
					string den;
					int nr = 0;
					int nr2 = 0;
					int c = 0;
					while (ip.good())
					{
						c++;
						nr = 0;

						Rand rand;
						rand.setNrColoane(vector_tabele[i].getNrColoane());
						char** elemente = new char* [vector_tabele[i].getNrColoane()];
						for (int j = 0; j < vector_tabele[i].getNrColoane(); j++)
						{
							getline(ip, den, ',');

							elemente[nr] = new char[den.length() + 1];
							strcpy(elemente[nr], den.c_str());
							nr++;
							nr2++;
						}
						if (nr != vector_tabele[i].getNrColoane())
						{

							ok = false;
							break;
						}
						else
						{
							rand.setElemente(elemente, nr);

							vector_tabele[i] = vector_tabele[i] + rand;
						}


					}
					if (c * vector_tabele[i].getNrColoane() != nr2)
					{
						cout << "Numarul de elemente de pe o linie nu corespunde ";
						ok = false;
					}
				}

			}
		}
		if (gasit == false)
		{

			cout << "Nu exista tabelul cu denumirea" << denumireTabela << endl;
		}
		else
		{

			if (ok == true)
			{
				setVectorTabele(vector_tabele, nr_tabele);
			}

		}

	}


	void selectAll(string denumireTabela)
	{
		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool ok = true;
		bool gasit = false;
		ofstream f;
		f.open("SELECT_1.txt");
		for (int i = 0; i < nr_tabele; i++)
		{

			if (denumireTabela == vector_tabele[i].getDenumire())
			{
				gasit = true;
				for (int j = 0; j < vector_tabele[i].getNrColoane(); j++)
				{
					cout << vector_tabele[i].getColoane()[j].getDenumire() << " ";
					f << vector_tabele[i].getColoane()[j].getDenumire() << " ";
				}
				cout << endl;
				f << endl;
				for (int j = 0; j < vector_tabele[i].getNrRanduri(); j++)
				{
					cout << vector_tabele[i].getRand(j);
					/*Rand rand = vector_tabele[i].getRand(j);
					f << rand;*/
					Rand rand = vector_tabele[i].getRand(j);
					for (int k = 0; k < rand.getNrColoane(); k++)
					{
						f << rand.elementPozitie(k)<<endl;
					}
					
				}


			}
			f.close();
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumireTabela;
		}
	}
	void SELECT(string denumireTabela, char** coloane, int nr)
	{

		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool ok = true;
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{

			if (denumireTabela == vector_tabele[i].getDenumire())
			{
				gasit = true;

				for (int j = 0; j < nr; j++)
				{
					if (vector_tabele[i].verificaColoana(coloane[j]) == -1)
					{
						cout << "Coloana " << coloane[j] << " nu exista";
						ok = false;
						break;
					}
				}
				if (ok == true)
				{
					for (int j = 0; j < nr; j++)
					{
						vector_tabele[i].select(coloane[j]);
					}

				}


			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumireTabela;
		}
	}
	void INSERT_INTO(string denumireTabela, Rand rand)
	{
		//INSERT INTO nume_tabela VALUES(...); valorile sunt separate prin, și au numărul și ordinea exacta ca definiția tabelului

		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();

		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{

			if (denumireTabela == vector_tabele[i].getDenumire())
			{
				gasit = true;
				if (rand.getNrColoane() == vector_tabele[i].getNrColoane())
				{
					vector_tabele[i].inlocuiesteValoareaImplicita(rand);
					if ( vector_tabele[i].verificaRestrictii(rand) == 0)
					{
						vector_tabele[i] = vector_tabele[i] + (rand);

						vector_tabele[i].serializare();
						
						cout << "Am introdus un rand cu succes in tabela :" << denumireTabela;
						setVectorTabele(vector_tabele, nr_tabele);
						
				}
					
					

				
				}
				else
				{
					cout << "Tabela " << denumireTabela << " accepta " << vector_tabele[i].getNrColoane() << " elemente in rand";
				}

			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumireTabela;
		}
	}

	void DELETE(string denumireTabela, string numeColoana, string valoare)
	{
		//DELETE FROM nume_tabela WHERE nume_coloană = valoare (DELETE permite doar o coloană în clauza WHERE)

		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele[i].getDenumire() == denumireTabela)
			{
				vector_tabele[i].DELETE(numeColoana, valoare);
				gasit = true;
				break;
			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumireTabela;
		}
		else
		{
			setVectorTabele(vector_tabele, nr_tabele);
		}
	}
	void SELECT(string denumire, char** conditie, int dim, int c)
	{
		//SELECT (cel_putin_o_coloana, ...) | ALL FROM nume_tabela [WHERE nume_coloană = valoare] - clauza WHERE este opțională

		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele[i].getDenumire() == denumire)
			{
				vector_tabele[i].select(conditie, dim);
				gasit = true;
				break;
			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea " << denumire;
		}
	}
	void UPDATE(string denumire, string numeColoana, string val2, string val1)
	{
		//UPDATE nume_tabela SET nume_coloană = valoare WHERE nume_coloană = valoare (coloana SET poate fi diferită de cea WHERE; UPDATE merge doar pentru o coloana)

		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool gasit = false;
		int index = -1;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (vector_tabele[i].getDenumire() == denumire)
			{
				Coloana* col = vector_tabele[i].getColoane();
				for (int j = 0; j < vector_tabele[i].getNrColoane(); j++)
				{
					if (numeColoana == col[j].getDenumire())
					{
						index = j;
					}
				}
				if (index != -1)
				{

					for (int k = 0; k < vector_tabele[i].getNrRanduri(); k++)
					{

						if (val1 == vector_tabele[i].getRand(k).elementPozitie(index))
						{

							vector_tabele[i].setRand(k, vector_tabele[i].getRand(k).setElementPozitie(index, val2));

						}
					}
					vector_tabele[i].serializare();
					setVectorTabele(vector_tabele, nr_tabele);
					cout << "Update facut cu succes";

				}
				else
				{
					cout << "Nu exista coloana " << numeColoana;
				}


				gasit = true;
				break;
			}
		}
		if (gasit == false)
		{
			cout << "Nu am gasit tabelul cu denumirea" << denumire;
		}

	}
	void afiseazaComanda() override
	{
		cout << "Comanda de tip DML" << endl;
	}
};

class Comenzi_DDL :virtual public  Comenzi
{
private:

public:
	Comenzi_DDL() :Comenzi()
	{

	}
	Comenzi_DDL(const Comenzi_DDL& c) :Comenzi(c)
	{

	}

	void parseazaComanda()  override
	{
		bool verifica = true;
		char* denumireTabel;
		string numeColoana = "";
		string egal = "=";
		string ins = "INSERT";
		string valoare = "";
		string upd = "UPDATE";
		string del = "DELETE";
		string dis = "DISPLAY";
		string drop = "DROP";
		string into = "INTO";
		string values = "VALUES";
		string table = "TABLE";
		string create = "CREATE";
		string from = "FROM";
		string wh = "WHERE";
		string terminal = ";";
		string virgula = ",";
		string denumire;
		char* elDefault = new char[8];
		strcpy(elDefault, "default");
		string parantezaDeschisa = "(";
		string parantezaInchisa = ")";
		const char* lista[6] = { "INSERT","UPDATE","DELETE" };
		bool ok = true;
		char** elemente = getElemente();
		int dim = getDim();
		int nr = 0;

		if (dim > 14 || dis == elemente[0] || drop == elemente[0])
		{
			if ((create == elemente[0]) && (table == elemente[1]))
			{
				denumireTabel = new char[strlen(elemente[2]) + 1];

				strcpy(denumireTabel, elemente[2]);

				Coloana* coloane;
				coloane = new Coloana[dim - 5];

				if (parantezaDeschisa == elemente[3] && terminal == elemente[dim - 1] && parantezaInchisa == elemente[dim - 2])
				{

					for (int j = 4; j < dim - 3; j = j + 9)
					{

						if (j == 4)
						{
							if ((parantezaDeschisa == elemente[j]) && (parantezaInchisa == elemente[j + 8]) && (virgula == elemente[j + 2]) && (virgula == elemente[j + 4]) && (virgula == elemente[j + 6]))
							{

								if ((coloane[nr].setLungimeColoana(elemente[j + 5]) == true) && (coloane[nr].setTipColoana(elemente[j + 3]) == true))
								{

									coloane[nr].setNumeColoana(elemente[j + 1]);
									coloane[nr].setTipColoana(elemente[j + 3]);
									coloane[nr].setLungimeColoana(elemente[j + 5]);
									coloane[nr].setValoareImplicita(elemente[j + 7]);
									nr++;

								}
								else
								{
									cout << "Comanda gresita !";
									verifica = false;
									break;
								}
							}
							else
							{
								cout << "Comanda gresita";
								verifica = false;
								break;
							}
						}
						else
						{
							if ((virgula == elemente[j]) && (parantezaDeschisa == elemente[j + 1]) && (parantezaInchisa == elemente[j + 9]) && (virgula == elemente[j + 3]) && (virgula == elemente[j + 5]) && (virgula == elemente[j + 7]))
							{
								if (coloane[nr].setLungimeColoana(elemente[j + 6]) == true && coloane[nr].setTipColoana(elemente[j + 4]) == true)
								{

									coloane[nr].setNumeColoana(elemente[j + 2]);
									coloane[nr].setTipColoana(elemente[j + 4]);
									coloane[nr].setLungimeColoana(elemente[j + 6]);
									coloane[nr].setValoareImplicita(elemente[j + 8]);
									nr++;
								}
								else
								{
									cout << "Comanda gresita";
									verifica = false;
									break;
								}
							}
							else
							{
								cout << "Comanda gresita";
								verifica = false;
								break;
							}
						}


					}
					if (verifica == true)
					{
						/*cout << "denumire " << denumireTabel << endl;
						cout << "nr " << nr;
						for (int i = 0; i < nr; i++)
						{
							cout << coloane[i];
						}*/
						CREATE_TABLE(denumireTabel, nr, coloane);
					}
				}


			}
			else if ((dis == elemente[0]) && (dim == 3) && (terminal == elemente[2]))
			{
				string de = elemente[1];
				DISPLAY(de);
			}
			else if ((drop == elemente[0]) && (dim == 3) && (terminal == elemente[2]))
			{
				
				string de = elemente[1];
				
				DROP(de);
			}


			else
			{
				cout << "Comanda gresita" << endl;
			}
		}
		else
		{
			cout << "Comanda gresita" << endl;
		}


	}
	void CREATE_TABLE(char* denumire, int nr_coloane, Coloana* coloane)
	{
		//CREATE TABLE nume_tabel [IF NOT EXISTS] ((nume_coloan?_1, tip, dimensiune, valoare_implicit?), 
		//(nume_coloan?_2, tip, dimensiune, valoare_implicit?), ...) - comanda ar trebui s? primeasc? cel pu?in 1 coloan?
		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (strcmp(vector_tabele[i].getDenumire(), denumire) == 0)
			{
				gasit = true;
				break;
			}
		}
		if (gasit == false)
		{
			nr_tabele++;
			Tabela tabel;
			tabel.setDenumire(denumire);
			tabel.setNrColoane(nr_coloane);
			tabel.setColoane(coloane);
			Tabela* copie = vector_tabele;
			vector_tabele = new Tabela[nr_tabele];
			if (nr_tabele == 1)
			{
				vector_tabele[0] = tabel;
			}
			else
			{
				for (int i = 0; i < nr_tabele - 1; i++)
				{
					vector_tabele[i] = copie[i];
				}
				vector_tabele[nr_tabele - 1] = tabel;
			}
			setVectorTabele(vector_tabele, nr_tabele);
			string x = denumire;
			ofstream h;
			h.open("Configurari/" + x + ".txt");
			h << tabel;
			h.close();
			h.open("Tabele.txt", ios::app);
			h << denumire << endl;

			h.close();
			cout << "Tabelul a fost creat cu succes " << endl;
		}
		else
		{
			cout << "Denumirea tabelului " + string(denumire) + " exista deja in BD" << endl;
		}
	}

	void DROP(string denumire)
	{
		//DROP TABLE table_name

		Tabela* vector_tabele = getVectorTabele();
		char* den = new char[denumire.length() + 1];
		strcpy(den, denumire.c_str());
		int nr_tabele = getNrTabele();
		int nr_copie = nr_tabele - 1;
		Tabela* copie = new Tabela[nr_copie];
		bool gasit = false;
		int nr = 0;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (strcmp(den, vector_tabele[i].getDenumire()) == 0)
			{


				gasit = true;
			}
			else

			{
				copie[nr] = vector_tabele[i];
				nr++;
			}
		}
		if (gasit == false)
		{
			cout << "Nu exista tabelul cu denumirea " << denumire;
		}
		else
		{
			string d = "Tabele.txt";
			char* x = new char[d.length() + 1];
			strcpy(x, d.c_str());
			string denumireConfigurare = "Configurari/" + denumire + ".txt";
			
			char* y = new char[denumireConfigurare.length() + 1];
			strcpy(y, denumireConfigurare.c_str());
			string denumireDetalii = "Detalii/" + denumire + ".bin";
			
			char* z = new char[denumireDetalii.length() + 1];
			strcpy(z, denumireDetalii.c_str());
			if (remove(x) != 0)
				cout << "";
			else
				if (remove(y) != 0)
					cout << "";
				else
					cout << "";
			if (remove(z) != 0)
				cout << "";
			else
				cout << "";



			ofstream h("Tabele.txt");
			for (int i = 0; i < nr_tabele; i++)
			{
				if (strcmp(den, vector_tabele[i].getDenumire()) != 0)
				{
					h << vector_tabele[i].getDenumire() << endl;
				}
			}

			h.close();
			setVectorTabele(copie, nr_copie);
		}
	}

	void DISPLAY(string denumire)
	{
		//DISPLAY TABLE table_name

		Tabela* vector_tabele = getVectorTabele();
		int nr_tabele = getNrTabele();
		bool gasit = false;
		for (int i = 0; i < nr_tabele; i++)
		{
			if (denumire == vector_tabele[i].getDenumire())
			{

				cout << vector_tabele[i];
				gasit = true;
			}
		}
		if (gasit == false)
		{
			cout << "Nu exista tabelul cu denumirea " << denumire;
		}
	}
	void afiseazaComanda() override
	{
		cout << "Comanda de tip DDL" << endl;
	}
	//CREATE INDEX [IF NOT EXISTS] index_name ON table_name (column_name) - opțional pentru faza 1; definește un index pentru coloana column_name
	//DROP INDEX index_name - opțional pentru faza 1. tipurile acceptate sunt text, integer, float
};


class Romb : public Comenzi_DML, public Comenzi_DDL
{
private:

public:
	Romb() :Comenzi_DDL(), Comenzi_DML()
	{

	}
	void parseazaComanda()
	{

	}
	void afiseazaComanda() override
	{
		cout << "Comanda de tip DML si DDL" << endl;
	}
};

class Fisier
{
private:
	string numeFisier;
	string numeBinar;
	Tabela tabela;
	int numerOfBytes;
public:
	Fisier()
	{

	}
	virtual void setNumeFisier(string numeFisier)
	{
		this->numeFisier = numeFisier;
	}
	Fisier(string numeFisier) {
		this->numeFisier = numeFisier;
	}
	virtual Tabela getTabela() {
		return tabela;
	}
	bool is_file_exist(string fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}
	virtual void setNumeBinar(string nume)
	{
		numeBinar = nume;
	}
	string getNumeBinar()
	{
		return numeBinar;
	}
	virtual void citesteTabela()
	{
		ifstream h;
		char* denumire = new char[numeFisier.length()];
		strcpy(denumire, numeFisier.c_str());
		Tabela copieTabela;
		copieTabela.setDenumire(denumire);
		
		h.open("Configurari/"+ numeFisier);
		h >> tabela;
		
		numerOfBytes = tabela.getNumberOfBytes();
		if (is_file_exist(numeBinar))
		{
			
			this->tabela.deserializare();
			
		}
		h.close();
	} 
	virtual void afiseazaRestrictii()
	{
		cout << "Nu exista restrictii pentru TABELUL " << numeFisier << endl;
	}
	int getNumberOfB()
	{
		return numerOfBytes;
	}
	string getNumeFisier()
	{
		return numeFisier;
	}

};

class FisierRestrictie : public Fisier
{
	list<string>restrictii;

public:
	FisierRestrictie()
	{

	}
	 Tabela getTabela() override {
		return Fisier::getTabela();
	}
	FisierRestrictie(string numeFisier) : Fisier(numeFisier)
	{

	}
	void setNumeFisier(string numeFisier) override
	{
		Fisier::setNumeFisier(numeFisier);

	}
	void setNumeBinar(string numebinar) override
	{
		Fisier::setNumeBinar(numebinar);
	}
	void citesteTabela() override
	{
		Fisier::citesteTabela();
		int numberOfBytes = getNumberOfB();
		
		string denumireFisier = getNumeFisier();
		char* den = new char[denumireFisier.length()];
		strcpy(den, denumireFisier.c_str());
		ifstream f("Configurari/"+ denumireFisier);
		f.seekg(numberOfBytes);
		
		string line;
		while (getline(f, line))
		{
			
			restrictii.push_back(line);
		}
	}
	list<string> getRestrictii()
	{
		return restrictii;
	}
	void afiseazaRestrictii()
	{
		if (restrictii.size() < 3)
		{
			cout << "Nu exista restrictii pentru tabelul " << getNumeFisier() << endl;
		}
		else
		{
			cout << "Restrictii pentru tabelul :" << getNumeFisier() << endl;
			list<string> ::iterator it ;
			int nr = 0;
			for (it = restrictii.begin(); it!= restrictii.end();it++,nr++)
			{
				if ( nr > 1)
				cout <<"  " <<nr-1<<"."<< *it << endl;
			}
		}
		
	}
	void afiseazaTabel()
	{
		cout << getTabela();
	}

};


class GestioneazaFisiere
{
private:
	static string detalii;
	static string configurari;
	Tabela* vector_tabele;
	set<string> numeFisiere;
	
	vector<Fisier*> fisiere;
	int nr_tabele;

public:


	bool is_file_exist(string fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}
	string compuneDenumire(string str)
	{
		char* den = new char[str.length() + 1];
		char* denNou;
		strcpy_s(den, str.length() + 1, str.c_str());

		if (den[strlen(den) - 1] == ' ')
		{
			den[strlen(den) - 1] = '\0';
		}

		string denum = den;
		string denumire = denum + ".txt";

		return denumire;
	}
	string compuneDenumireBinar(string str)
	{
		char* den = new char[str.length() + 1];
		char* denNou;
		strcpy_s(den, str.length() + 1, str.c_str());

		if (den[strlen(den) - 1] == ' ')
		{
			den[strlen(den) - 1] = '\0';
		}

		string denum = den;
		string denumire = "Detalii/" + denum + ".bin";

		return denumire;
	}
	void getTabele()
	{
		ifstream f;
		string line;
		int number_of_lines = 0;
		ifstream myfile("Tabele.txt");
		while (getline(myfile, line))
			++number_of_lines;
		myfile.close();
		f.open("Tabele.txt");
		if (number_of_lines == 0)
		{
			cout << "Nu exista tabele pentru incarcare" << endl;
		}
		else
		{
			Tabela* vectorTabele = new Tabela[number_of_lines];
			int nr = 0;
			string denumire;
			string str;
			f >> ws;
			Fisier* fisierr;
			while (getline(f, str))
			{

			
				numeFisiere.insert(str);
				bool ok = true;
				string r = "";
				try
				{
					r = str.substr(str.length() - 11, str.length());
				}
				catch (exception e)
				{
					ok = false;
				}
				if (ok == true && r == "_restrictie")
				{
					fisierr = new FisierRestrictie();
				}
				else
				{
					fisierr = new Fisier();
				}
				fisierr->setNumeFisier(compuneDenumire(str));
				string denSer = compuneDenumireBinar(str);
				fisierr->setNumeBinar(denSer);
				fisierr->citesteTabela();
				
				
				fisiere.push_back(fisierr);
				nr++;

				/*FisierRestrictie fisier(compuneDenumire(str));
				fisier.setNumeBinar(denSer);
				fisier.citesteTabela();
				cout << "Restrictii TABEL " <<str<< endl;
				fisier.afiseazaRestrictii();*/
				
				f >> ws;
			}
			f.close();
			this->vector_tabele = vectorTabele;
			this->nr_tabele = nr;
		}

	}
	
	Tabela* getVectorTabele()
	{
		delete[]vector_tabele;
		vector_tabele = new Tabela[fisiere.size()];
		for (int i = 0; i < fisiere.size(); i++)
		{
			
			vector_tabele[i] = fisiere[i]->getTabela();
		}
		return vector_tabele;
	}
	int getNrTabele()
	{
		return nr_tabele;
	}
	void afiseazaNumeFisiereOrdine()
	{
		set<string> ::iterator it;
		cout << endl << "Fisierele incarcate in ordine alfabetica sunt :" << endl;
		int nr = 1;
		for (it = numeFisiere.begin(); it != numeFisiere.end(); it++,nr++)
		{
			cout <<nr<<". " << *it << endl;
			string denumire = *it + ".txt";
			Fisier* f = cautaDupaDenumire(compuneDenumire(*it));
			f->afiseazaRestrictii();
		}
	}
	Fisier* cautaDupaDenumire(string nume)
	{
		for (int i = 0; i < fisiere.size(); i++)
		{
			if (fisiere[i]->getNumeFisier() == nume)
			{
				return fisiere[i];
			}
		}
	}

};

string GestioneazaFisiere::detalii = "Detalii/";
string GestioneazaFisiere::configurari = "Configurari/";