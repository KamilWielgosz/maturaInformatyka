#include <map>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

	map<const string, int> mapa;

	mapa["A"] = 1;
	mapa["B"] = 2;
	mapa["C"] = 3;
	mapa["D"] = 4;
	mapa["E"] = 5;
	mapa["F"] = 6;
	mapa["G"] = 7;
    mapa["H"] = 8;
	mapa["I"] = 9;
	mapa["J"] = 10;
	mapa["K"] = 11;
	mapa["L"] = 12;
	mapa["M"] = 13;
	mapa["N"] = 14;
    mapa["O"] = 15;
	mapa["P"] = 16;
	mapa["Q"] = 17;
	mapa["R"] = 18;
	mapa["S"] = 19;
	mapa["T"] = 20;
	mapa["U"] = 21;
	mapa["V"] = 22;
	mapa["W"] = 23;
	mapa["X"] = 24;
	mapa["Y"] = 25;
	mapa["Z"] = 26;


	vector<string> vec_slowa;

	ifstream slowa_txt;

	slowa_txt.open("tj.txt");

	if(!slowa_txt.good()){
		cout<<"Blad podczas otwierania pliku tj.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	string linia;

	while(getline(slowa_txt, linia)){

		vec_slowa.push_back(linia);
	}

	slowa_txt.close();
	cout<<"Pobieranie slow zakonczone sukcesem\n";

	vector <string> vec_klucze; 
	ifstream klucze_txt;

	klucze_txt.open("klucze1.txt");

	if(!klucze_txt.good()){
		cout<<"Blad podczas otwierania pliku klucze1.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	while(getline(klucze_txt, linia)){
		vec_klucze.push_back(linia);
	}

	klucze_txt.close();
	cout<<"Pobieranie kluczy zakonczone sukcesem\n";


	ofstream szyfrogram_txt;

	szyfrogram_txt.open("wynik4a.txt", ios::out | ios::trunc);

	if(!szyfrogram_txt.good()){
		cout<<"Blad podczas otwierania pliku wynik4a.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	string slowo;
	string klucz;
	int cyfra_slowo = 0;
	int cyfra_klucz = 0;
	int cyfra_koncowa = 0;
	string literka;

	for(int i = 0; i < vec_slowa.size(); i++){

		slowo = vec_slowa.at(i);
		klucz = vec_klucze.at(i);

		for(int k = 0, m = 0; k < slowo.length(); k++, m++){

			cyfra_slowo = static_cast<int>(slowo[k]);

			    if(m >= klucz.length()){
				   m = 0;
			       literka = klucz[m];
		        } else {
					literka = klucz[m];
				}

				cyfra_klucz = mapa[literka];

            cyfra_koncowa = cyfra_slowo + cyfra_klucz;

			if(cyfra_koncowa > 90){
				cyfra_koncowa = cyfra_koncowa - 26;
			}
			szyfrogram_txt << static_cast<char>(cyfra_koncowa);
	}
		szyfrogram_txt << "\n";

	}


	szyfrogram_txt.close();
	cout<<"Wypisywanie zakodowanych liczb do pliku zakonczone sukcesem\n";


	ifstream sz_slowa_txt;

	sz_slowa_txt.open("sz.txt");

	if(!sz_slowa_txt.good()){
		cout<<"Blad podczas otwierania pliku sz.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	vector <string> vec_sz_slowa;

	while(getline(sz_slowa_txt,linia)){
		   vec_sz_slowa.push_back(linia);
		}
	sz_slowa_txt.close();
	cout<<"Wczytywanie zaszyfrowanych slow zakonczone sukcesem\n";

	
	ifstream klucze2_txt;

	klucze2_txt.open("klucze2.txt");

	if(!klucze2_txt.good()){
		cout<<"Blad podczas otwierania pliku klucze2.txt\n";
		getchar();
	    return EXIT_FAILURE;
	}

	vector <string> vec_klucze2;

	while(getline(klucze2_txt, linia)){
		vec_klucze2.push_back(linia);
	}
	klucze2_txt.close();
	cout<<"Wczytywanie kluczy2 zakonczone sukcesem\n";

	   ofstream wynik4b_txt;

	   wynik4b_txt.open("wynik4b_txt.txt", ios::out | ios::trunc);

	   if(!wynik4b_txt.good()){
		   cout<<"Blad podczas otwierania pliku wynik4b_txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }


		for(int i = 0; i < vec_sz_slowa.size(); i++){

		slowo = vec_sz_slowa.at(i);
		klucz = vec_klucze2.at(i);

		for(int k = 0, m = 0; k < slowo.length(); k++, m++){

			cyfra_slowo = static_cast<int>(slowo[k]);

			    if(m >= klucz.length()){
				   m = 0;
			       literka = klucz[m];
		        } else {
					literka = klucz[m];
				}

				cyfra_klucz = mapa[literka];

            cyfra_koncowa = cyfra_slowo - cyfra_klucz;

			if(cyfra_koncowa < 65){
				cyfra_koncowa = cyfra_koncowa + 26;
			}

			wynik4b_txt << static_cast<char>(cyfra_koncowa);
	}
		wynik4b_txt << "\n";

	}
		wynik4b_txt.close();


		cout<<"Wykonywanie programu zakonczone sukcesem\n";



	getchar();
	return EXIT_SUCCESS;
}