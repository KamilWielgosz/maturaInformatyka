#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

	ifstream pierplik;

	pierplik.open("dane.txt");

	if(!pierplik.good()){
		cout<<"Blad przy probie otwarcia pliku dane.txt\n";
		getchar();
		return EXIT_FAILURE;
	}


	vector < vector<string> > wektor(250, vector<string>(5));
	string slowo;

	for(int i = 0; pierplik>>slowo; i++){
		if(i == 250) {
			wektor.resize(wektor.size() + 100, vector<string>(50));
		}
		wektor.at(i).at(0) = slowo;
		pierplik>>slowo;
		wektor.at(i).at(1) = slowo;
	}
	pierplik.close();

	int pierwsze = 0;
	int drugie = 0;
	int palidromy = 0;

	for(int i = 0; !wektor.at(i).at(0).empty(); i++){
		for(int k = 0; k < 2; k++){
			pierwsze = 0;
			drugie = 0;
			slowo = wektor.at(i).at(k);
			for(int j = 0; j < slowo.length(); j++){
				pierwsze = pierwsze * 2 + slowo[j] - '0';
			}
			for(int m = 1; m <= slowo.length(); m ++){
				drugie = drugie * 2 + slowo[slowo.length() - m] - '0';
			}

			if(pierwsze == drugie){
				palidromy++;
			}
		}
	}
	cout<<"W pliku jest: "<<palidromy<<" palidromow\n";

	string pierwszesl;
	string drugiesl;

	// polecenie b)

	int zawartych = 0;
	int li_b = 0;
	int li_a = 0;
	int roznica = 0;

	for(int i = 0; !wektor.at(i).at(0).empty(); i++){
	
		slowo = wektor.at(i).at(1);
		li_b = 0;
		for(int k = 0; k < slowo.length(); k++){
			li_b = li_b * 2 + slowo[k] - '0';
		}
		int dlugosc_dr = slowo.length();
		slowo = wektor.at(i).at(0);

		roznica = slowo.length() - dlugosc_dr;

		for(int m = 0; m <= roznica; m++){
			li_a = 0;
			for(int j = 0; j < dlugosc_dr; j++){
				li_a = li_a * 2 + slowo[m + j] - '0';
			}
			if(li_a == li_b){
				zawartych++;
				break;
			}
		}
	} 

	cout<<"Jest: "<<zawartych<< " wierszy gdzie slowo B zawiera sie w slowie A\n";


	// przyklad c)
	int wynik_c = 0;
	int licz_c = 0;
	for(int i = 0; !wektor.at(i).at(0).empty(); i++){
		slowo = wektor.at(i).at(1);
		wynik_c = 0;
		for(int k = 0; k < slowo.length(); k++){
			wynik_c = wynik_c * 2 + slowo[k] - '0';
		}

		if(wynik_c == 0){
			licz_c++;
		}

		wynik_c = 0;
		slowo = wektor.at(i).at(0);
		for(int j = 0; j < slowo.length(); j++){
			wynik_c = wynik_c * 2 + slowo[j] - '0';
		}

		if(wynik_c == 0) {
			licz_c++;
		}
	}

	cout<<"Jedyna mozliwosc sklejenia dwoch slow ma: "<<licz_c<<" wierszy\n";

	getchar();
	return EXIT_SUCCESS;
} // koniec main