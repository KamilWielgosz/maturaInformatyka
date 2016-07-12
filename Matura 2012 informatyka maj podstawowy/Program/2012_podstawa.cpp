#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {

	fstream cyfry_txt;

	vector<string> wek_cyf;

	string linia;

    cyfry_txt.open("cyfry.txt");

	if(!cyfry_txt.good()){
		cout<<"Blad podczas proby otwarcia pliku cyfry.txt\n";
		system("Pause");
		return EXIT_FAILURE;
	}

	while(getline(cyfry_txt, linia)){
		wek_cyf.push_back(linia);
	}
	cyfry_txt.close();


	int parzyste = 0;
	int cyfra = 0;
	for(int i = 0; i < wek_cyf.size(); i++){
		cyfra = 0;
		linia = wek_cyf.at(i);
		   for(int k = 0; k < linia.length(); k++){
			   cyfra = cyfra * 10 + linia[k] - '0';
		   }

		   if((cyfra % 2) == 0){
			   parzyste++;
		   }

	}

	cout<<parzyste<<"\n";

	int najwieksza = 0;
	string najwiekszast;
	int najmniejsza = 0;
	string najmniejszast;

	for(int i = 0; i < wek_cyf.size(); i++){
		cyfra = 0;
		  linia = wek_cyf.at(i);

		      for(int k = 0; k < linia.length(); k++){
				  cyfra = cyfra + linia[k] - '0';
			  }

	    if(cyfra > najwieksza){
			najwieksza = cyfra;
			najwiekszast = linia;
		}

		if(i == 0){
			najmniejsza = cyfra;
		}

		if(cyfra < najmniejsza){
			najmniejsza = cyfra;
			najmniejszast = linia;
		}
		  
	}

	cout<<najwieksza<<" -- "<<najwiekszast<<" - najwieksza\n";
	cout<<najmniejsza<<" -- "<<najmniejszast<<" - najmniejsza\n";

	int liwcz = 0;
	int likol = 0;
	int licznik = 0;

	vector<string> wek_ciag;
	for(int i = 0; i < wek_cyf.size(); i++){
		linia = wek_cyf.at(i);
		licznik = 0;
		    for(int k = 0; k < linia.length() - 1; k++){
				liwcz = linia[k] - '0';
				likol = linia[k + 1] - '0';

				if(liwcz < likol){
					licznik = k + 1;
				} else {
					break;
				}
			}

	

			if(licznik == linia.length() - 1){
				wek_ciag.push_back(linia);
			}
	}

	for(int i = 0; i < wek_ciag.size(); i++){
		cout<<wek_ciag.at(i)<<"\n";
	}


	system("Pause");
	return EXIT_SUCCESS;
}