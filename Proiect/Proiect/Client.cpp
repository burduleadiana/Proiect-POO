#include<iostream>
using namespace std;
class Client {
	const int idClient;
	char* nume;
	char* prenume;
	string tipClient;
	bool esteStudent;

	//constructor default
	Client():idClient(0) {
		nume = nullptr;
		prenume = nullptr;
		tipClient = "Necunoscut";
		esteStudent = false;
	}
	//constructor cu parametri
	Client(int idClient, char* nume, char* prenume, string tipClient, bool esteStudent) :idClient(idClient) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->prenume = new char[strlen(prenume) + 1];
		strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
		this->tipClient = tipClient;
		this->esteStudent = esteStudent;
	}
	//constructor de copiere
	Client(const Client& c):idClient(c.idClient) {
		if (c.nume != nullptr) {
			this->nume = new char[strlen(c.nume) + 1];
			strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		}
		if (c.prenume != nullptr) {
			this->prenume = new char[strlen(c.prenume) + 1];
			strcpy_s(this->prenume, strlen(c.prenume) + 1, c.prenume);
		}
		this->tipClient = c.tipClient;
		this->esteStudent = c.esteStudent;
	}
	//operator =
	Client& operator=(const Client& c) {
		if (this != &c) {
			if (nume != nullptr) {
				delete[] nume;
			}
			if (prenume != nullptr) {
				delete[] prenume;
			}
			if (c.nume != nullptr) {
				this->nume = new char[strlen(c.nume) + 1];
				strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
			}
			if (c.prenume != nullptr) {
				this->prenume = new char[strlen(c.prenume) + 1];
				strcpy_s(this->prenume, strlen(c.prenume) + 1, c.prenume);
			}
			this->tipClient = c.tipClient;
			this->esteStudent = c.esteStudent;
		}
	}
	//getteri si setteri
	string getTipClient() {
		return tipClient;
	}
	void setTipClient(string tipClient) {
		if (tipClient == "VIP") {
			this->tipClient = tipClient;
		}
		else
			if (tipClient == "Regular") {
				this->tipClient = tipClient;
			}
			else
				this->tipClient = "Necunoscut";

	}

	bool getEsteStudent() {
		return esteStudent;
	}

	char* getNume() {
		if (nume != nullptr) {
			char* copy = new char[strlen(nume) + 1];
			strcpy_s(copy, strlen(nume) + 1, nume);
			return copy;
		}
		else
			return nullptr;
	}
	
	void setNume(const char* nume) {
		if (nume != nullptr) {
			if (this->nume != nullptr) {
				delete[] this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}
	char* getPrenume() {
		if (prenume != nullptr) {
			char* copy = new char[strlen(prenume) + 1];
			strcpy_s(copy, strlen(prenume) + 1, prenume);
			return copy;
		}
		else
			return nullptr;
	}

	void setPrenume(const char* prenume) {
		if (prenume != nullptr) {
			if (this->prenume != nullptr) {
				delete[] this->prenume;
			}
			this->prenume = new char[strlen(prenume) + 1];
			strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
		}
	}
	//destructor
	~Client() {
		if (nume != nullptr) {
			delete[] nume;
		}
		if (prenume != nullptr) {
			delete[] prenume;
		}
	}

	friend ostream& operator<<(ostream&, Client);
	friend istream& operator>>(istream&, Client&);

};
ostream& operator<<(ostream& out, Client c) {
	out << "Nume: ";
	if (c.nume != nullptr) {
		out << c.nume;
	}
	out << endl;
	out << "Prenume: ";
	if (c.prenume != nullptr) {
		out << c.prenume;
	}
	out << endl;
	out << "Tip client: " << c.tipClient << endl;
	out << "Este student?: " << c.esteStudent << endl;
	return out;
}