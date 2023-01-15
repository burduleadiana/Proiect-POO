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
	Sala(int nrSala, const char* numeSala, string tipSala,int* locuri, int nrLocuri) :nrSala(nrSala) {
		if (numeSala != nullptr) {
			this->numeSala = new char[strlen(numeSala) + 1];
			strcpy_s(this->numeSala, strlen(numeSala) + 1, numeSala);
		}
		else
		{
			this->numeSala = nullptr;
		}
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
			this->numeSala = new char[strlen(s.numeSala)+1];
			strcpy_s(this->numeSala, strlen(s.numeSala)+1, s.numeSala);
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
		{
			return nullptr;
		}
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

	friend ostream& operator<<(ostream& out, Sala s) {
		out << "Nume sala: ";
		if (s.numeSala != nullptr) {
			out << s.numeSala;
		}
		else {
			out << "N/A";
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

	friend istream& operator>>(istream& in, Sala& s) {
			char buffer[100];
			cout << "Denumire sala: " << endl;
			in >> ws;
			in.getline(buffer, 99);
			if (s.numeSala != nullptr) {
				delete[] s.numeSala;
			}
			s.numeSala = new char[strlen(buffer) + 1];
			strcpy_s(s.numeSala, strlen(buffer) + 1, buffer);
			cout << "Tipul salii: " << endl;
			in >> s.tipSala;
			cout << "Numar locuri/sala: " << endl;
			in >> s.nrLocuri;
			if (s.locuri != nullptr)
			{
				delete[] s.locuri;
			}
			if (s.nrLocuri > 0&&in.good())
			{
				s.locuri = new int[s.nrLocuri];
				for (int i = 0; i < s.nrLocuri; i++)
				{
					cout << "Locul cu numarul" << i;
					in >> s.locuri[i];
				}
			}
			else
			{
				s.nrLocuri = 0;
				s.locuri = nullptr;
			}
			return in;
	}
};
//ostream& operator<<(ostream& out, Sala s) {
//	out << "Nume sala: ";
//	if (s.numeSala != nullptr) {
//		out << s.numeSala;
//	}
//	out << endl;
//	out << "Tip sala: " << s.tipSala << endl;
//	out << "Numar locuri: " << s.nrLocuri << endl;
//	out << "Locuri: ";
//	if (s.locuri != nullptr) {
//		for (int i = 0; i < s.nrLocuri; i++) {
//			out << s.locuri[i] << " ";
//		}
//	}
//	return out;
//}
//istream& operator>>(istream& in, Sala& f) {
//	string buffer;
//	cout << "Denumire sala: " << endl;
//	in >> buffer;
//	if (f.numeSala != nullptr) {
//		delete[] f.numeSala;
//	}
//	f.numeSala = new char[buffer.length() + 1];
//	strcpy_s(f.numeSala, buffer.length(), buffer.c_str());
//	cout << "Tipul salii: " << endl;
//	in >> f.tipSala;
//	cout << "Numar locuri/sala: " << endl;
//	in >> f.nrLocuri;
//	if (f.locuri != nullptr)
//	{
//		delete[] f.locuri;
//	}
//	if (f.nrLocuri > 0)
//	{
//		f.locuri = new int[f.nrLocuri];
//		for (int i = 0; i < f.nrLocuri; i++)
//		{
//			cout << "Locul cu numarul" << i;
//			in >> f.locuri[i];
//		}
//	}
//	else
//	{
//		f.nrLocuri = 0;
//		f.locuri = nullptr;
//	}
//	return in;
//
//}