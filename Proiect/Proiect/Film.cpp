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
	Film(char* titlu, string gen, int durata, int frecventa) :idFilm(idFilm) {
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

	//destructor
	~Film() {
		if (titlu != nullptr) {
			delete[] titlu;
		}
	}
	friend ostream& operator<<(ostream&, Film);
	friend istream& operator>>(istream&, Film&);
	
};
ostream& operator<<(ostream& out, Film f) {
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
