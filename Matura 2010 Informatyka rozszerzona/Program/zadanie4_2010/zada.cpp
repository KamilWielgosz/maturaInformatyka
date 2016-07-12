#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
	ifstream plik;

	plik.open("anagram.txt");

	if(!plik.good()){
		cout<<"Blad podczas otwarcia pliku anagram.txt";
		getchar();
		return EXIT_FAILURE;
    }

	vector< vector<string> > wektor(205, vector<string>(10));
    string str;
	
	int licznik = 0;
	for(licznik; plik>>str; licznik++){
		wektor.at(licznik).at(0) = str;
		for(int k = 1; k < 5; k++){
			plik>>str;
			wektor.at(licznik).at(k) = str;
		}
	}
	plik.close();

	
	ofstream wypisa;
	wypisa.open("odp_4a.txt", ios::out | ios::trunc);

	if(!wypisa.good()){
		cout<<"Blad przy próbie otwarcia pliku odp_4a.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	int dlugosc = 0;
	for(int i = 0; i <= licznik; i++){
		dlugosc = wektor[i][0].length();
		for(int k = 1; k < 5; k++) {
		if(dlugosc != wektor[i][k].length()){
			break;
		} else if(k == 4){
			for(int h = 0; h < 5; h++){
				wypisa<<wektor.at(i).at(h)<<" ";
			}
			wypisa<<"\n";
		}
		}
	}

	wypisa.close();

	getchar();
	return EXIT_SUCCESS;
} // koniec main