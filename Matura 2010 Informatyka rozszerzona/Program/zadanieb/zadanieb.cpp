#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {

     ifstream plik_pier;

	 plik_pier.open("anagram.txt");

	 if(!plik_pier.good()){
		 cout<<"Blad podczas otwierania pliku anagram.txt\n";
		 getchar();
		 return EXIT_FAILURE;
	 }

	 vector < vector<string> > wektor(205, vector<string>(10));
	 string str;
	 for(int i = 0; plik_pier>>str; i++){
		   wektor.at(i).at(0) = str;
		   for(int u = 1; u < 5; u++){
			   plik_pier>>str;
			   wektor.at(i).at(u) = str;
		   }
	 }
	 plik_pier.close();

	 ofstream plik_drug;

	 plik_drug.open("wynik.txt", ios::out | ios::trunc);

	 if(!plik_drug.good()){
		 cout<<"Blad przy probie otwarcia pliku wynik.txt\n";
		 getchar();
		 return EXIT_FAILURE;
	 }

	 cout<<"przed";
	 vector<int> wekint(10);
	 int wartosc = 0;
	 for(int i = 0; !wektor.at(i).at(0).empty(); i++){

		  for(int u = 0; u < 5; u++){
			  wartosc = 0;
			  str = wektor.at(i).at(u);

			  for(int k = 0; k < str.length(); k++){
				  wartosc = wartosc + static_cast<int>(str[k]);
			  }
			  wekint.at(u) = wartosc;
			  }
		  			  if(wekint.at(0) == wekint.at(1) && wekint.at(0) == wekint.at(2) && wekint.at(0) == wekint.at(3) && wekint.at(0) == wekint.at(4)){
				  for(int f = 0; f < 5; f++){
					  plik_drug<<wektor.at(i).at(f)<<" ";
				  }
				  plik_drug<<"\n";

		  }
	 }
	 plik_drug.close();

	 getchar();
	 return EXIT_SUCCESS;
} // koniec main