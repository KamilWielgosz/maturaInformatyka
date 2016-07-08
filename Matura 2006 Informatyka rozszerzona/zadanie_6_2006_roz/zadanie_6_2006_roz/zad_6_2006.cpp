#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

bool czy_palindrom(string slowo) {

	string od_tylu;

	for(int i = slowo.length() - 1; i >= 0; i--) {
		od_tylu = od_tylu + slowo[i];
	}

	int czy_tesame = 0;
	for(int i = 0; i < slowo.length(); i++){
		if(slowo[i] == od_tylu[i]){
			czy_tesame++;
		}
	}

	if(czy_tesame == slowo.length()){
		return true;
	} else {
		return false;
	}

}

int main(){
	
	ifstream dane;

	dane.open("dane.txt");

	if(!dane.good()){
		cout<<"Blad podczas probie otwarcia pliku dane.txt";
		getchar();
		return EXIT_FAILURE;
	}

	  vector<string> wektor_dane;

	  string linia;

	  while(getline(dane,linia)){
		  wektor_dane.push_back(linia);
	  }
	dane.close();
	
	cout<<"Etap pierwszy zakonczony\n";
	vector<string> wek_slow(wektor_dane.size() + 1);
	vector<int>    wek_ile(wektor_dane.size() + 1);

	int n = 300;
	int ilosc = 0;
	bool czy_bylo = false;
	string slowo;

	for(int i = 0; i < wektor_dane.size(); i++){
		slowo = wektor_dane.at(i);

		czy_bylo = false;
		for(int m = 0; m < wek_slow.size(); m++){
			if(slowo == wek_slow.at(m)){
				czy_bylo = true;
				break;
			}
		}

		if(czy_bylo == false) {
		ilosc = 0;
		wek_slow.at(i) = slowo;
		for(int k = 0; k < wektor_dane.size(); k++){
			if(slowo == wektor_dane.at(k)){
				ilosc++;
				wek_ile.at(i) = ilosc; 
			}

		}
		}
	}
	cout<<"Etap drugi zakonczony\n";
	ofstream wyniki;

	for(int i = 0; i < wek_slow.size(); i++){
		cout<<wek_slow.at(i)<<"\n";
	}

	wyniki.open("wyniki.txt", ios::out | ios::trunc);

	if(!wyniki.good()){
		cout<<"Blad podczas proby otwarcia pliku wyniki.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	int najwieksza_liczba = 0;
	int wieksze_dwoch = 0;
	     for(int i = 0; i < wek_ile.size(); i++){

			 if(wek_ile.at(i) >= 2){
				 wieksze_dwoch++;
			 }
		 }
	    wyniki<<"Slow wystepujacych wiecej niz jeden raz jest: "<<wieksze_dwoch<<"\n";
		cout<<"Etap trzeci zakonczony\n";

		for(int i = 0; i < wek_ile.size(); i++){
			if(najwieksza_liczba < wek_ile.at(i)){
				najwieksza_liczba = wek_ile.at(i);
			}
		}
		cout<<"Etap czwarty zakonczony\n";
		for(int i = 0; i < wek_ile.size(); i++){
			if(wek_ile.at(i) == najwieksza_liczba){
				wyniki<<"Slowo o najwiekszej liczbie wystapien to: "<<wek_slow.at(i)<<"\n";
				wyniki<<"Ktore wystepuje: "<<wek_ile.at(i)<<" razy \n";
				break;
			}
		}

		int licz_parzyste = 0;
		int na_dzies = 0;
		string wyraz;
		for(int i = 0; i < wektor_dane.size(); i++){
			wyraz = wektor_dane.at(i);
			na_dzies = 0;
			for(int k = 0; k < wyraz.length(); k++){
				na_dzies = na_dzies * 16 + wyraz[k] - '7';
			}

			if(na_dzies % 2 == 0) {
				licz_parzyste++;
			}
		}
		wyniki<<"W pliku jest: "<<licz_parzyste<<" liczb parzystych\n";

		int ile_palindromow = 0;
		for(int i = 0; i < wektor_dane.size(); i++){
			wyraz = wektor_dane.at(i);

			if(czy_palindrom(wyraz)){
				ile_palindromow++;
			}

		}

		wyniki<<"W pliku znajduje sie: "<<ile_palindromow<<" palindromow\n";

	wyniki.close();
	




	cout<<"Wykonywanie programu zakonczone sukcesem";
	getchar();
	return EXIT_SUCCESS;
}