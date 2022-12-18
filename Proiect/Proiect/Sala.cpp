#include<iostream>
using namespace std;
class Sala {
private:
	const int nrSala;
	char* numeSala;
	string tipSala;
	int* locuri;
	int nrLocuri;
public:
	//constructor fara parametri
	Sala():nrSala(0) {
		numeSala = nullptr;
		tipSala = "Necunoscut";
		locuri = nullptr;
		nrLocuri = 0;
	}
	//constructor cu parametri
	Sala(int nrSala, char* numeSala, string tipSala,int* locuri, int nrLocuri) :nrSala(nrSala) {
		this->numeSala = new char[strlen(numeSala) + 1];
		strcpy_s(this->numeSala, strlen(numeSala) + 1, numeSala);
		this->tipSala = tipSala;
		this->nrLocuri = nrLocuri;
		if (locuri != nullptr) {
			this->locuri = new int[nrLocuri + 1];
			for (int i = 0; i < nrLocuri; i++) {
				this->locuri[i] = locuri[i];
			}
		}
	}
	//constructor de copiere
	Sala(const Sala& s):nrSala(nrSala) {
		if (s.numeSala != nullptr) {
			this->numeSala = new char[strlen(s.numeSala)];
			strcpy_s(this->numeSala, strlen(s.numeSala), s.numeSala);
		}
		this->tipSala = s.tipSala;
		this->nrLocuri = s.nrLocuri;
		if (s.locuri != nullptr) {
			this->locuri = new int[s.nrLocuri];
			for (int i = 0; i < s.nrLocuri; i++) {
				this->locuri[i] = locuri[i];
			}
		}
	}
	//operator =
	Sala& operator=(const Sala& s) {
		if (this != &s) {
			if (numeSala != nullptr) {
				delete[] numeSala;
			}
			if (s.numeSala != nullptr) {
				this->numeSala = new char[strlen(s.numeSala) + 1];
				strcpy_s(this->numeSala, strlen(s.numeSala) + 1, s.numeSala);
			}
			this->tipSala = s.tipSala;
			this->nrLocuri = s.nrLocuri;
			if (s.locuri != nullptr) {
				this->locuri = new int[s.nrLocuri];
				for (int i = 0; i < s.nrLocuri; i++) {
					this->locuri[i] = locuri[i];
				}
			}
		}
		return *this;
	}
	//getteri si setteri
	char* getNumeSala() {
		if (numeSala != nullptr) {
			char* copy = new char[strlen(numeSala) + 1];
			strcpy_s(copy, strlen(numeSala) + 1, numeSala);
			return copy;
		}
		else
			return nullptr;
	}
	string getTipSala() {
		return tipSala;
	}
	int getNrLocuri() {
		return nrLocuri;
	}
	int* getLocuri() {
		if (locuri != nullptr) {
			int* copy = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++) {
				copy[i] = locuri[i];
			}
			return copy;
		}
		else
			return nullptr;
	}

	void setNote(int* locuri, int nrLocuri) {
		if (locuri != nullptr && nrLocuri != 0) {
			this->nrLocuri = nrLocuri;
			if (this->locuri != nullptr) {
				delete[] this->locuri;
			}
			this->locuri = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++) {
				this->locuri[i] = locuri[i];
			}
		}
	}
	void setTipSala(string tipSala) {
		if (tipSala == "2D") {
			this->tipSala = tipSala;
		}
		else
			if (tipSala == "3D") {
				this->tipSala = tipSala;
			}
			else
				if (tipSala == "4D") {
					this->tipSala = tipSala;
				}
				else
					this->tipSala == "Necunoscuta";
	}
	//destructor
	~Sala() {
		if (numeSala != nullptr) {
			delete[] numeSala;
		}
		if (locuri != nullptr) {
			delete[] locuri;
		}
	}

	friend ostream& operator<<(ostream&, Sala);
	friend istream& operator>>(istream&, Sala&);
};
ostream& operator<<(ostream& out, Sala s) {
	out << "Nume sala: ";
	if (s.numeSala != nullptr) {
		out << s.numeSala;
	}
	out << endl;
	out << "Tip sala: " << s.tipSala << endl;
	out << "Numar locuri: " << s.nrLocuri << endl;
	out << "Locuri: ";
	if (s.locuri != nullptr) {
		for (int i = 0; i < s.nrLocuri; i++) {
			out << s.locuri[i] << " ";
		}
	}
	return out;
}