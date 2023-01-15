#include<iostream>
using namespace std;
class Bilet {
private:
	const int codBilet;
	static int bileteEmise;
	string dataEmitere;
	string oraFilm;
	int codFilm;
	float pret;
	string tipPlata;
	int loc;
	int rand;
public:
	//constructor default
	Bilet():codBilet(0) {
		dataEmitere = "Necunoscuta";
		oraFilm = "Necunoscuta";
		codFilm = 0;
		pret = 0.0f;
		tipPlata = "Necunoscuta";
		loc = 0;
		rand = 0;
	}
	//constructor cu parametri
	Bilet(int codBilet, string dataEmitere, string oraFilm, int codFilm, float pret, string tipPlata, int loc, int rand) :codBilet(codBilet) {
		this->dataEmitere = dataEmitere;
		this->oraFilm = oraFilm;
		this->codFilm = codFilm;
		this->pret = pret;
		this->tipPlata = tipPlata;
		this->loc = loc;
		this->rand = rand;
	}
	//getteri si setteri
	string getDataEminere() {
		return dataEmitere;
	}
	string getOraFilm() {
		return oraFilm;
	}
	int getCodFilm() {
		return codFilm;
	}
	float getPret() {
		return pret;
	}
	string getTipPlata() {
		return tipPlata;
	}
	int getLoc() {
		return loc;
	}
	int getRand() {
		return rand;
	}

	void setRand(int rand) {
		if (rand < 0 && rand >= 10) {
			rand = 0;
		}
		else
			this->rand = rand;
	}
	void setLoc(int loc) {
		if (loc < 0 && loc >=200 ) {
			loc = 0;
		}
		else
			this->loc = loc;
	}
	void setTipPlata(string tipPlata) {
		if (tipPlata == "Cash") {
			this->tipPlata = tipPlata;
		}
		else
			if (tipPlata == "Card") {
				this->tipPlata = tipPlata;
			}
			else
				this->tipPlata = "Necunoscuta";
	}

	void setPret(float pret){
		if (pret < 0) {
			this->pret = pret;
		}
	}
	friend ostream& operator<<(ostream& out, Bilet b) {
		out << "Data emitere: " << b.dataEmitere << endl;
		out << "Ora film: " << b.oraFilm << endl;
		out << "Cod film: " << b.codFilm << endl;
		out << "Pret: " << b.pret << endl;
		out << "Tip plata: " << b.tipPlata << endl;
		out << "Rand: " << b.rand << endl;
		out << "Loc: " << b.loc << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Bilet& b) {
		cout << "Data emitere bilet: " << endl;
		in >> b.dataEmitere;
		cout << "Ora filmului: " << endl;
		in >> b.oraFilm;
		cout << "Codul filmului: " << endl;
		in >> b.codFilm;
		cout << "Pretul biletului: " << endl;
		in >> b.pret;
		cout << "Tipul platii (Cash/Card): " << endl;
		in >> b.tipPlata;
		cout << "Rand: " << endl;
		in >> b.rand;
		cout << "Loc: " << endl;
		in >> b.loc;
		return in;
	}
};
//int Bilet::bileteEmise = 10;
//ostream& operator<<(ostream& out, Bilet b) {
//	out << "Data emitere: " << b.dataEmitere << endl;
//	out << "Ora film: " << b.oraFilm << endl;
//	out << "Cod film: " << b.codFilm << endl;
//	out << "Pret: " << b.pret << endl;
//	out << "Tip plata: " << b.tipPlata << endl;
//	out << "Rand: " << b.rand << endl;
//	out << "Loc: " << b.loc << endl;
//	return out;
//}