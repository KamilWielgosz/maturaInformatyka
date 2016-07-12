#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() {

	string linia;
	ifstream plik;
	int tab[10];



	plik.open("zapis.txt");

	if(!plik.good()){
		cout<<"Blad przy probie otwarcia pliku zapis.txt";
		return EXIT_FAILURE;
	}

	int k = 0;
	int liczba = 0;
	stringstream pp;
	while(getline(plik, linia)) {
		pp.clear();
		pp<<linia;
		pp>>liczba;

		if(k == 0) {
	   tab[0] = liczba;
	   tab[1] = liczba;
	    k = 1;
		}

	   if(tab[0] > liczba) {
		   tab[0] = liczba;
	   }

	   if(tab[1] <liczba) {
		   tab[1] = liczba;
	   }

	}
	plik.close();
	cout<<"Najmniejsza liczba to: "<<tab[0]<<endl;
	cout<<"Najwieksza liczba to: "<<tab[1];
	getchar();
	return EXIT_SUCCESS;

} // koniec main

