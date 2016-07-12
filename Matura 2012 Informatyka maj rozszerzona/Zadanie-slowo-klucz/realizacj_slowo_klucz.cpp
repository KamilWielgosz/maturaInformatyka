#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main() {

	cout<<"Otwieranie pliku tj.txt....\n";
	ifstream plik_slowa;

	plik_slowa.open("tj.txt");

	if(!plik_slowa.good()) {
		cout<<"Blad przy probie otwarcia pliku tj.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	string linia;
	vector < vector<int> > wektor_slow(100, vector<int>(40)); // zakladajac ze slowa nie beda dluzsze niz 40 znakow
	int ele_wier = 0;
	while(getline(plik_slowa, linia)) {
		
		for(int i = 0; i < linia.length(); i++) {
		wektor_slow.at(ele_wier).at(i) = static_cast<int>(linia[i]);
		}

		if(ele_wier == wektor_slow.size() - 1) {
			wektor_slow.resize(wektor_slow.size() + 100, vector<int>(40));
		}
		ele_wier++;
	} // koniec while

	plik_slowa.close();
	cout<<"Slowa z pliku tj.txt zostaly pobrane poprawnie\n";

    cout<<"Otwieranie pliku klucze1.txt ...\n";
	ifstream plik_klucze;

	plik_klucze.open("klucze1.txt");

	   if(!plik_klucze.good()) {
		   cout<<"Blad przy probie otwarcia pliku klucze1.txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }

	   vector< vector<int> > wektor_kluczy(100, vector<int>(40)); // zakladajac ze klucze nie maja rozmiaru wiekszego niz 40 znakow
	   ele_wier = 0;
	   while(getline(plik_klucze, linia)) {

		   for(int i = 0; i < linia.length(); i++) {
			   wektor_kluczy.at(ele_wier).at(i) = static_cast<int>(linia[i]) - 64;
		   }

		   if(ele_wier == wektor_kluczy.size() - 1) {
			   wektor_kluczy.resize(wektor_kluczy.size() + 100, vector<int>(40));
		   }
		   ele_wier++;
	   } // koniec while
	   plik_klucze.close();
       cout<<"Klucze z pliku klucze1.txt zostaly wczytane prawidlowo\n";

	   cout<<"Kodowanie slow...\n";

	   vector < vector<char> > wektor_zakodowanych(100, vector<char>(40)); // zakladajac ze zakodowane slowa nie beda dluzsze niz 40 znakow
	   int wynik = 0;
		   for(int i = 0; wektor_slow[i][0] != 0; i++) {
			   for(int k = 0, m = 0; wektor_slow[i][k] != 0; k++, m++) {
				   if(wektor_kluczy[i][m] == 0){
					   m = 0;
				   }
				   wynik = wektor_slow[i][k] + wektor_kluczy[i][m];
				   if(wynik > 90) {
					   wynik = wynik - 26;
				   }

				   wektor_zakodowanych.at(i).at(k) = static_cast<char>(wynik);
			   }

			   if(i == wektor_zakodowanych.size() - 1) {
				   wektor_zakodowanych.resize(wektor_zakodowanych.size() + 100, vector<char>(40));
			   }

		   } // koniec petli for

		   cout<<"Wpisywanie zakodowanych slow do pliku wynik4a.txt...\n";

		   ofstream plik_koncowy;

		   plik_koncowy.open("wynik4a.txt", ios::trunc | ios::out);

		   if(!plik_koncowy.good()) {
			   cout<<"Blad przy probie otwarcia pliku wynik4a.txt\n";
			   getchar();
			   return EXIT_FAILURE;
		   }

		   for(int i = 0; wektor_zakodowanych[i][0] != 0; i++){
			   for(int k = 0; wektor_zakodowanych[i][k] != 0; k++){
			   plik_koncowy<<wektor_zakodowanych[i][k];
			   }
			   plik_koncowy<<"\n";
		   }
		   plik_koncowy.close();
		   cout<<"Zakodowane slowa zostaly wpisane do pliku wynik4a.txt\n";

	   getchar();
	   return EXIT_SUCCESS;
}// koniec main










