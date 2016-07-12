#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

	ifstream plik;

	plik.open("liczby.txt");

	if(!plik.good()){
		cout<<"Blad przy probie otwarcia pliku liczby.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	string linia;
	int parzystych = 0;
	int wynik = 0;
	int tablica[10];
	int licznik = 0;
	string tabstring[10];
	int dziewcyf = 0;
	int sumacyfr = 0;

	while(getline(plik, linia)){
		wynik = 0;
		for(int i = 0; i < linia.length(); i++){
		wynik = wynik*2 + linia[i] - '0';
		}

		if(linia.length() == 9){
			dziewcyf++;
			sumacyfr = sumacyfr + wynik;
		}

		if((wynik % 2) == 0){
			parzystych++;
		}

		if(licznik == 0){
			licznik++;
			tablica[0] = wynik;
		}

		tablica[1] = wynik;

		if(tablica[0] < tablica[1]){
			tablica[0] = tablica[1];
			tabstring[0] = linia;
		}


	} // koniec while
	plik.close();

	cout<<"W pliku jest "<<parzystych<<" liczb parzystych\n";
	cout<<"Najwieksza liczba w pliku wynosi dwojkowo: "<<tabstring[0]<<" i dziesietnie: "<<tablica[0]<<"\n";
	cout<<"W calym pliku 9 cyfr ma dokladnie "<<dziewcyf<<" liczb, których suma dwojkowo wynosi ";

	vector<int> wektor;
	while(sumacyfr != 0){
		wektor.push_back(sumacyfr%2);
		sumacyfr = sumacyfr/2;
	}
	
	int a = wektor.size();
	for(int i = a-1; i>=0; --i){
		cout<<wektor.at(i);
	}



  getchar();
  return EXIT_SUCCESS;
}//koniec main