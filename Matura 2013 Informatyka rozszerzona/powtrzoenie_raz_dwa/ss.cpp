#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ifstream dane_txt;

	dane_txt.open("dane.txt");

	if(!dane_txt.good()){
		cout<<"Blad podczas otwieranai pliku dane.txt/n";
		system("Pause");
		return EXIT_FAILURE;
	}

	vector<string> wektor_dane;

	string linia;

	   while(getline(dane_txt, linia)){
		   wektor_dane.push_back(linia);
	   }

	dane_txt.close();

	// sprawdzanie czy pierwsza rozna sie ostatniej
	int ost_pier = 0;
	for(int i = 0; i < wektor_dane.size(); i++){

		    linia = wektor_dane.at(i);

			   if(linia[0] == linia[linia.length() - 1]){
				   ost_pier++;
			   }
	}

	cout<<"Liczb takich gdzie pierwsza rowna sie ostatniej jest "<<ost_pier<<"\n";

	vector<string> wektor_dzies;
	int wynik = 0;
      for(int i = 0; i < wektor_dane.size(); i++){
		  linia = wektor_dane.at(i);

		       for(int k = 0; k < linia.length(); k++){
				   wynik = wynik * 8 + linia[k] - '0';
			   }

			   wektor_dzies.push_back(static_cast<string>(wynik));

	  }





	system("Pause");
	return EXIT_SUCCESS;
}