#include<iostream>
#include "Film.cpp"
#include "Bilet.cpp"
#include "Sala.cpp"
#include "Client.cpp"
using namespace std;

int main() {
	//Sala sala1;
	//cout << sala1.nrLocuri << endl;
	Bilet b1;
	Bilet b2(1, "13.01.2023", "18.30", 1, 15.2, "card", 15, 3);
	cout << b2.getDataEminere() << endl;
	cout << b2.getCodFilm() << endl;
	cout << b2.getLoc() << endl;
	cout << b2.getOraFilm() << endl;
	cout << b2.getRand() << endl;
	cout << b2.getPret() << endl;

	b1.setLoc(20);
	cout << b1.getLoc() << endl;

	cout << b2 << endl;

	Bilet b3;
	//cin >> b3;

	Client c1;
	Client c2(10, "Popescu", "Andrei", "Regular", false);

	c1.setTipClient("VIP");
	cout << c1.getTipClient() << endl;

	cout << c2 << endl;
	Client c3;
	//cin >> c3;


	Sala s1;
	int locuri[] = { 10,12,13,14 };
	Sala s2(12, "Sala 1", "2D", locuri, 4);
	s2.setTipSala("3D");
	cout << s2.getTipSala() << endl;

	//cout << s2 << endl;

	Film f1;
	Film f2("Avatar", "Actiune", 50, 3);
	

	f2.setFrecventa(7);
	cout << f2.getFrecventa() << endl;

	cout << f2 << endl;
	Film f3;
	//cin >> f3;
	//cout << f3 << endl;

	Sala s3;
	//cin >> s3;
	//cout << s3 << endl;

}