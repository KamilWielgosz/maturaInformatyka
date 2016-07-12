#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
/////////////// FUNKCJE ///////////////////
bool czy_palindrom(string slowo) {
	string odwrocone;

	   for(int i = slowo.length() - 1; i >= 0; i--){
		   odwrocone = odwrocone + slowo[i];
	   }
	 
	   if(slowo == odwrocone){
		   return true;
	   } else {
		   return false;
	   }
}


////////////// KONIEC FUNKCJI //////////////

int main() {
	ifstream slowa_txt;

	slowa_txt.open("slowa.txt");

	if(!slowa_txt.good()){
		cout<<"Blad podczas proby otwarcia pliku slowa.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	vector < string > wektor(1005);
	string linia;

	for(int i = 0;getline(slowa_txt, linia); i++){
		 wektor.at(i) = linia;
	}
	slowa_txt.close();

	ofstream hasla_a_txt;

    hasla_a_txt.open("hasla_a.txt", ios::out | ios::trunc);

	if(!hasla_a_txt.good()){
		cout<<"Blad podczas probie otwarcia pliku hasla_a.txt\n";
		getchar();
		return EXIT_FAILURE;
	}


	for(int i = 0; !wektor.at(i).empty(); i++){
		linia = wektor.at(i);

		for(int k = linia.length() - 1; k >=0; k--){
			hasla_a_txt<<linia[k];
		}
		hasla_a_txt<<"\n";
	}
	hasla_a_txt.close();


	ofstream slowa_a_txt;

	slowa_a_txt.open("slowa_a.txt", ios::out | ios::trunc);

	if(!slowa_a_txt.good()){
		cout<<"Blad przy probie otwarcia pliku slowa_a.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	vector<string> naj_mn_wie(3);
	int dlugosc = 0;
	for(int i = 0; !wektor.at(i).empty(); i++){
		dlugosc = wektor.at(i).length();

		if(i == 0){
			for(int k = 0; k < 2; k++){
				naj_mn_wie.at(k) = wektor.at(i);
			}
		}

		if(naj_mn_wie.at(0).length() < dlugosc){
			naj_mn_wie.at(0) = wektor.at(i);
		}

		if(naj_mn_wie.at(1).length() > dlugosc){
			naj_mn_wie.at(1) = wektor.at(i);
		}

	}

	slowa_a_txt<<"Najdluzsze haslo "<<naj_mn_wie.at(0)<<" ma "<< naj_mn_wie.at(0).length()<<" znakow\n";
	slowa_a_txt<<"Najkrotsze haslo "<<naj_mn_wie.at(1)<<" ma "<< naj_mn_wie.at(1).length()<<" znaki\n";
	slowa_a_txt.close();

	fstream hasla_b;

	hasla_b.open("hasla_b.txt", ios::out | ios::trunc);

	if(!hasla_b.good()){
		cout<<"Blad podczas proby otwarcia pliku hasla_b.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	string slowo;
	string wyraz_wek;
	for(int i = 0; !wektor.at(i).empty(); i++){
		wyraz_wek = wektor.at(i);
		for(int k = wyraz_wek.length() - 1; k >= 0; k--){
			slowo.erase();
			  for(int j = 0; j <= k; j++){
			     slowo = slowo + wyraz_wek.at(j);
			  }

			  if(czy_palindrom(slowo)){
				  for(int u = wyraz_wek.length() - 1; u > k; u--){
					  hasla_b<<wyraz_wek.at(u);
				  }

				  for(int y = 0; y < wyraz_wek.length(); y++){
					  hasla_b<<wyraz_wek.at(y);
				  }
				  hasla_b<<"\n";
				  break;
			  }
		}
	}
	hasla_b.close();


	ofstream slowa_b;
	ifstream hasla_lepsze;

	hasla_lepsze.open("hasla_b.txt");
	if(!hasla_lepsze.good()){
		cout<<"Blad podczas proby otwarcia pliku hasla_b.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	slowa_b.open("slowa_b.txt", ios::out | ios::trunc);

	if(!slowa_b.good()){
		cout<<"Blad przy probie otwarcia pliku slowa_b.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	
	slowa_b<<"Wszystkie hasla o dlugosci 12\n";
	while(getline(hasla_lepsze, linia)){
		if(linia.length() == 12){
			slowa_b<<linia<<"\n";
		}
	}

	vector<string> wek_slo_b(3);
	hasla_lepsze.clear();
	hasla_lepsze.seekg(0);
	for(int i = 0; getline(hasla_lepsze, linia); i++){
		if(i == 0){
			for(int m = 0; m < 2; m++){
				wek_slo_b.at(m) = linia;
			}
		}

		if(wek_slo_b.at(0).length() < linia.length()){
			wek_slo_b.at(0) = linia;
		}

		if(wek_slo_b.at(1).length() > linia.length()){
			wek_slo_b.at(1) = linia;
		}
	}
	slowa_b<<"Najdluzsze haslo to "<<wek_slo_b.at(0)<<"\n";
	slowa_b<<"Najkrotsze haslo to "<<wek_slo_b.at(1)<<"\n";


	long int suma_dlugosci = 0;
	hasla_lepsze.clear();
	hasla_lepsze.seekg(0);
	while(getline(hasla_lepsze, linia)){
		suma_dlugosci = suma_dlugosci + linia.length();
	}
	slowa_b<<"Suma dlugosci wszystkich hasel wynosi "<<suma_dlugosci<<"\n";
    hasla_lepsze.close();
	slowa_b.close();





	cout<<"Wykonywanie programu zakonczone sukcesem";
	getchar();
	return EXIT_SUCCESS;
}