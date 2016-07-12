#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {

	ifstream plik_pier;
	plik_pier.open("napisy.txt");

	if(!plik_pier.good()){
		cout<<"Blad podczas proby otwarcia pliku napisy.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	string linia;
	int suma_zer = 0;
	int suma_jedynek = 0;
	int suma_liczb = 0;
	int zer = 0;
	int jedynek = 0;
	int napisy_zera_i_jedynki = 0;
	int dlugosc = 0;
	int ilosc_parzystej_dlugosci = 0;
	vector<int> wektor(20);
	while(getline(plik_pier, linia)){
		dlugosc = linia.length();

		if(dlugosc % 2 == 0){
			ilosc_parzystej_dlugosci++;
		}

		jedynek = 0;
		zer = 0;

		for(int i = 0; i < dlugosc; i++){
			if(linia[i] - '0' == 1){
				jedynek++;
			} else {
				zer++;
			}
		}

		if(zer == jedynek){
			napisy_zera_i_jedynki++;
		}

		suma_liczb = 0;
		for(int k = 0; k < linia.length(); k++){
			suma_liczb = suma_liczb + linia[k] - '0';
		}

		if(suma_liczb == 0){
			suma_zer++;
		} else if(suma_liczb == linia.length()) {
			suma_jedynek++;
		}

		for(int i = 2; i <= 16; i++){
			if(linia.length() == i){
				wektor.at(i) = wektor.at(i) + 1;
			}
		}



	}
	plik_pier.close();
	cout<<"W pliku znajduje sie: "<<ilosc_parzystej_dlugosci<<" znakow o parzystej dlugosci\n";
	cout<<"W pliku jest: "<<napisy_zera_i_jedynki<<" napisow ktore zawieraja taka sama ilosc zer i jedynek\n";
	cout<<"W pliku znajduje sie jedynek: "<<suma_jedynek<<" i zer: "<<suma_zer<<"\n";

	for(int i = 2; i <= 16; i++){
		cout<<"O dlugosci: "<<i<<": "<<wektor.at(i)<<"\n";
	}

	getchar();
	return EXIT_SUCCESS;
} // koniec main