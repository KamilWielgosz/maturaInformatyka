#include <iostream> 
#include <time.h> 
#include <conio.h> 

using namespace std; 

int main() { 
	    tm pierstr;
		tm drugstr;
		tm *wynik;

		time_t pierczas;
		time_t drugczas;
		

		double roznica = 0;
		int licz_siana = 0;
		int licz_zoledzi = 0;

		pierstr.tm_year = 2012 - 1900;
		pierstr.tm_mon = 12 - 1;
		pierstr.tm_mday = 1;
		pierstr.tm_hour = 0;
		pierstr.tm_min = 0;
		pierstr.tm_sec = 0;

		drugstr.tm_year = 2013 - 1900;
		drugstr.tm_mon = 2 - 1;
		drugstr.tm_mday = 28;
		drugstr.tm_hour = 0;
		drugstr.tm_min = 0;
		drugstr.tm_sec = 0;

		drugczas = mktime(&drugstr); //zmiana na czas kalendarzowy
		pierczas = mktime(&pierstr); // zmiana na czas kalendarzowy
		roznica = difftime(drugczas, pierczas); // roznica drugczas - pierczas

		cout<<"Roznica 1.12.2012 do 28.02.2013 wynosi: "<<roznica<<endl;

		wynik = localtime(&pierczas); //konwersacja na czas lokalny

		cout<<asctime(wynik);


		for(pierczas; pierczas <= drugczas; pierczas += 86400) {
			wynik = localtime(&pierczas);

			if(wynik->tm_wday == 5) {
				licz_siana++;
				cout<<licz_siana<<" dostawa siana"<<endl;
				}

			if(wynik->tm_wday == 2) {
				licz_zoledzi++;
				cout<<licz_zoledzi<<" dostawa zoledzi"<<endl;
			}


		}




	
        getchar(); 
        return 0; 

}