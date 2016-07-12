#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool czy_palindrom(string slowo) {
	int dlugosc = slowo.length();
	int licznik = 0;
	int i = 0;

	for(int k = 1; i < dlugosc / 2; i++, k++){
		if(slowo[i] != slowo[dlugosc - k]){
			break;
		}
	}

	if( (dlugosc / 2) == i){
		return true;
	} else {
		return false;
	}

}

int main(){

	ifstream dane_txt;

	dane_txt.open("dane.txt");

	  if(!dane_txt.good()){
		  cout<<"Blad podczas otwierania pliku dane.txt\n";
		  system("Pause");
		  return EXIT_FAILURE;
	  }

   vector<string> wektor_dane;

     string linia;

     while(getline(dane_txt, linia)){

		 wektor_dane.push_back(linia);

	 }


	dane_txt.close();

	ofstream zadanie4_txt;

     zadanie4_txt.open("zadanie4.txt", ios::out | ios::trunc);

	 if(!zadanie4_txt.good()){
		 cout<<"Blad podczas otwierania pliku zadanie4.txt\n";
		  system("Pause");
		  return EXIT_FAILURE;
	 }

	  for(int i = 0; i < wektor_dane.size(); i++){
		  if(czy_palindrom(wektor_dane.at(i))){
			  zadanie4_txt << wektor_dane.at(i)<<"\n";
		  }
	  }
	
	  zadanie4_txt.close();



	system("Pause");
	return EXIT_SUCCESS;
}