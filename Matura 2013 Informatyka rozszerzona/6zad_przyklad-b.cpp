#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream> // czytanie z pliku

using namespace std;

int main() {



     ifstream plik; // czytanie z pliku
	 plik.open("dane.txt");

	 if(!plik.good()) {
		 cout<<"Wystapil blad przy probie otwarcia pliku";
		 return EXIT_FAILURE;
	 }
	
	 int licznik = 0;
	 int rowne = 0;
	 string linia;
	 while(getline(plik, linia)) {

		 // Zmiana liczby z systemu 8 na system 10
		 int wynik = 0;
		 wynik = 0;
		 for(unsigned i = 0; i < linia.length(); i++) { 
             wynik = wynik * 8 + linia[i] - '0'; 
        }

	     // Sprawdzanie ile jest liczb (po przeksztalceniu na system 10) w pliku gdzie pierwsza cyfra rowna sie ostatniej
		 int licz = 0;
		 int koncowy = 0;
		 int pierwsza = 0;
		 while(wynik != 0) {
			 koncowy = wynik % 10;
			 wynik = wynik / 10;
			 if(licz == 0) {
				 pierwsza = koncowy;
				 licz++;
			 }
		 }
		 
		 if(koncowy == pierwsza) {
			 rowne++;
		 }		  
	 } // koniec while

	 cout<<"Rownych jest: "<<rowne<<" liczb";

	 plik.close();
	 getchar();
	 return EXIT_SUCCESS;


} // koniec main