#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int suma_binarna(string slowo) {

	long int liczba = 0;

	for(int i = 0; i < slowo.length(); i++){
		liczba = liczba * 10 + slowo[i] - '0';
	}


	vector<int> wektor_bin;
	while(liczba / 2 != 0) {
		wektor_bin.push_back(liczba % 2);

		liczba = liczba / 2;
	}
	wektor_bin.push_back(1);

	int suma_bin = 0;

	for(int i = 0; i < wektor_bin.size(); i++){
		suma_bin = suma_bin + wektor_bin.at(i);
	}

	return suma_bin;
}



int main() {

	const int n = 100000;

	bool tablica[n + 1] = {0};
	vector<int> wektor;
	   for(int i = 2; i*i <=n; i++){

		   if(tablica[i] == false) {
		   for(int j = 2*i; j<=n; j = j + i){
			   tablica[j] = true;
		   }
		   }

	   }


	   ofstream plik_pierwsze;

	   plik_pierwsze.open("pierwsze.txt", ios::trunc | ios::out);

	   if(!plik_pierwsze.good()){
		   cout<<"Blad podczas proby otwarcia pliku pierwsze.txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }


	   for(int i = 2; i < n; i++){
		   if(tablica[i] == false) {
			   plik_pierwsze<<i<<"\n";
			   wektor.push_back(i);
		   }
	   }
	   plik_pierwsze.close();

	   ofstream plik_super_pierwsza;

	   plik_super_pierwsza.open("super_pierwsza.txt", ios::trunc | ios::out);

	   if(!plik_super_pierwsza.good()){
		   cout<<"Blad podczas proby otwarcia pliku super_pierwsza.txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }

	   ifstream plik_pierwsze_r;

	   plik_pierwsze_r.open("pierwsze.txt");

	   if(!plik_pierwsze_r.good()){
		   cout<<"Blad podczas proby otwarcia pliku pierwsze.txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }

	     string linia;
		 int suma = 0;
		 while(getline(plik_pierwsze_r, linia)){
			 suma = 0;
			    for(int i = 0; i < linia.length(); i++){
					suma = suma + linia[i] - '0';
				}


				for(int j = 0; j < wektor.size(); j++){
					if(wektor.at(j) == suma) {
						plik_super_pierwsza<<linia<<"\n";
					}
				}
		 }
	   plik_pierwsze_r.close();
	   plik_super_pierwsza.close();


	   ifstream super_pierwsza_read;

	   super_pierwsza_read.open("super_pierwsza.txt");

	   if(!super_pierwsza_read.good()){
		   cout<<"Blad podczas proby otwarcia pliku super_pierwsza.txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }

	   ofstream super_b;

	   super_b.open("super_b.txt", ios::out | ios::trunc);

	   if(!super_b.good()){
		   cout<<"Blad przy probie otwarcia pliku super_b.txt\n";
		   getchar();
		   return EXIT_FAILURE;
	   }


	   while(getline(super_pierwsza_read, linia)){

		   for(int j = 0; j < wektor.size(); j++){

			   if(suma_binarna(linia) == wektor.at(j)){
                 super_b<<linia<<"\n";
			   }

		   }

	   }

	   super_b.close();
	   super_pierwsza_read.close();






    cout<<"Wykonywanie programu zakonczone sukcesem";
	getchar();
	return EXIT_SUCCESS;
}