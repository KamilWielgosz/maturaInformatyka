#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){

	vector <string> wek_dane;

	ifstream dane_txt;

	dane_txt.open("dane.txt");

	if(!dane_txt.good()){
		cout<<"Blad podczas otwierania pliku dane.txt\n";
		system("Pause");
		return EXIT_FAILURE;
	}

    string linia;

	while(getline(dane_txt, linia)){
		wek_dane.push_back(linia);
	}

	dane_txt.close();

	int ostatnia_liczba = 0;
	int odp_a = 0;

	for(int i = 0; i < wek_dane.size(); i++){
		linia = wek_dane.at(i);

		ostatnia_liczba = linia.size() - 1;

		if(linia[0] == linia[ostatnia_liczba]){
			odp_a++;
		}

	}
	cout<<"a) Pierwsza cyfra rowna sie ostatniej w "<<odp_a<<" przypadkach\n";

	int dziesietnie = 0;
	int ostatni = 0;
	int pierwszy = 0;
	int odp_b = 0;

	for(int i = 0; i < wek_dane.size(); i++){

		linia = wek_dane.at(i);

		dziesietnie = 0;

		for(int k = 0; k < linia.length(); k++){
			dziesietnie = dziesietnie * 8 + linia[k] - '0';
		}

		ostatni = dziesietnie % 10;
		pierwszy = 0;
		while(dziesietnie != 0){
			pierwszy = dziesietnie % 10;
			dziesietnie = dziesietnie / 10;
		}

		if(pierwszy == ostatni){
			odp_b++;
		}
	}
	cout<<"b) Dziesietnie pierwszy rowna sie ostatniemy w "<<odp_b<<" przypadkach\n";


	vector <int> wek_c;
	int licznik = 0;
	int praw_liczba = 0;

	for(int i = 0; i < wek_dane.size(); i++){
		linia = wek_dane.at(i);

		licznik = 0;

		for(int k = 0; k < linia.length() - 1; k++){
			if(linia[k] <= linia[k+1]){
				licznik++;
			} else {
				break;
			}
		}

		if(licznik == linia.length() - 1){
			praw_liczba = 0;
			 for(int m = 0; m < linia.length(); m++){
				 praw_liczba = praw_liczba * 10 + linia[m] - '0';
			 }
			 wek_c.push_back(praw_liczba);
		}
	}
	cout<<"c) Spelnia warunek "<<wek_c.size()<<" liczb\n";

	   for(int i = 0; i < wek_c.size(); i++){

		   for(int k = 0; k < wek_c.size() - 1; k++){
			   if(wek_c.at(k) > wek_c.at(k+1)){
				   swap(wek_c.at(k), wek_c.at(k+1));
			   }
		   }
	   }

	   cout<<"Najmniejsza to "<<wek_c.at(0)<<" a najwieksza to "<<wek_c.at(wek_c.size() - 1)<<"\n";

	cout<<"Program wykonany pomyslnie";
	system("Pause");
	return EXIT_SUCCESS;
}