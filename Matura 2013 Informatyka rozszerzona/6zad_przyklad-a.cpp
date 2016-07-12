#include <iostream>
#include <stdlib.h>
#include <fstream> // czytanie i pisanie z pliku 
#include <string>

using namespace std;

int main() {
	ifstream plikdane; // czytanie z pliku
	string linia;
	int tablica[10];
	char literka;
	int jeslirowne = 0;


	literka = '55';

	int liczba = literka - '0';

	cout<<"liczba = "<<liczba<<endl;

	plikdane.open("dane.txt");

	if(plikdane.good()) {
		cout<<"Plik zostal otowrzony poprawnie\n";
	} else {
		cout<<"Blad przy probie otwarcia pliku\n";
	}

	while(!plikdane.eof()) {
		getline(plikdane, linia);

		cout<<linia;
		int rozmiar = linia.length();

		for(int i = 0; i < rozmiar; i++) {
						
			tablica[i] = linia[i] - '0';
		}

		//sorawdzanie czy pierwsza liczba rowna sie ostatniej

		rozmiar = rozmiar - 1;

		if(tablica[0] == tablica[rozmiar]) {
			cout<<"Rowne\n";
			jeslirowne++;
		} else {
			cout<<"Nierowne\n";
		}
	
	} // koniec petli while

	plikdane.close();

	cout<<"Rownych liczb jest: "<<jeslirowne;




	getchar();
	return 0;
}