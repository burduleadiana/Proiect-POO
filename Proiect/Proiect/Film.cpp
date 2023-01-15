#include<iostream>
using namespace std;
class Film {
private:
	const int idFilm;
	char* titlu;
	string gen;
	int durata;
	int frecventa;
public:
	//constructor default
	Film() :idFilm(0) {
		titlu = nullptr;
		gen = "Necunoscut";
		durata = 0;
		frecventa = 0;
	}

	//constructor cu parametri
	Film(const char* titlu, string gen, int durata, int frecventa) :idFilm(idFilm) {
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		this->gen = gen;
		this->durata = durata;
		this->frecventa = frecventa;
	}
	//constructor de copiere
	Film(const Film& f):idFilm(f.idFilm) {
		if (f.titlu != nullptr) {
			this->titlu = new char[strlen(f.titlu) + 1];
			strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
		}
		this->gen = f.gen;
		this->durata = f.durata;
		this->frecventa = f.frecventa;
	}
	//operator=
	Film& operator=(const Film& f) {
		if (this != &f) {
			if (titlu != nullptr) {
				delete[] titlu;
			}
			if (f.titlu != nullptr) {
				this->titlu = new char[strlen(f.titlu) + 1];
				strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
			}
			this->gen = f.gen;
			this->durata = f.durata;
			this->frecventa = f.frecventa;
		}
		return *this;
	}
	//getteri si setteri
	char* getTitlu() {
		if (titlu != nullptr) {
			char* copy = new char[strlen(titlu) + 1];
			strcpy_s(copy, strlen(titlu) + 1, titlu);
			return copy;
		}
		else
			return nullptr;
	}
	string getGen() {
		return gen;
	}

	int getDurata() {
		return durata;
	}
	int getFrecventa() {
		return frecventa;
	}
	void setFrecventa(int frecventa) {
		if (frecventa > 0) {
			this->frecventa = frecventa;
		}
		else
			this->frecventa = 0;
	}
	void setDurata(int durata) {
		if (durata > 0) {
			this->durata = durata;
		}
		else
			this->durata = 0;
	}

	//functie care mareste frecventa unui film pe saptamana
	Film operator++(int i) {
		Film copie = *this;
		frecventa++;
		return copie;
	}

	//destructor
	~Film() {
		if (titlu != nullptr) {
			delete[] titlu;
		}
	}
	friend ostream& operator<<(ostream& out, Film f) {
		out << "Titlu: ";
		if (f.titlu != nullptr) {
			out << f.titlu;
		}
		out << endl;
		out << "Gen: " << f.gen << endl;
		out << "Frecventa: " << f.frecventa << endl;
		out << "Durata: " << f.durata << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Film& f) {
			char buffer[100];
			cout << "Titlul filmului: " << endl;
			in >> ws;
			in.getline(buffer, 99);
			if (f.titlu != nullptr) {
				delete[] f.titlu;
			}
			f.titlu = new char[strlen(buffer) + 1];
			strcpy_s(f.titlu, strlen(buffer)+1, buffer);
			cout << "Genul filmului: " << endl;
			in >> f.gen;
			cout << "Durata filmului: " << endl;
			in >> f.durata;
			cout << "Frecventa difuzarii: " << endl;
			in >> f.frecventa;
		
			return in;
	}
	
};


//istream& operator>>(istream& in, Film& f) {
//	string buffer;
//	cout << "Titlul filmului: " << endl;
//	in >> buffer;
//	if (f.titlu != nullptr) {
//		delete[] f.titlu;
//	}
//	f.titlu = new char[buffer.length() + 1];
//	strcpy_s(f.titlu, buffer.length(), buffer.c_str());
//	cout << "Genul filmului: " << endl;
//	in >> f.gen;
//	cout << "Durata filmului: " << endl;
//	in >> f.durata;
//	cout << "Frecventa difuzarii: " << endl;
//	in >> f.frecventa;
//
//	return in;
//}
