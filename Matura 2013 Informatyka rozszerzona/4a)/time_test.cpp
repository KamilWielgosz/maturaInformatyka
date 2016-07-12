#include <iostream> 
#include <time.h> 
#include <conio.h> 

using namespace std; 

int main() { 
	    time_t pierczas;
		time_t drugczas;
		double roznica;
		int piatkow = 0;
		int wtorkow = 0;

        tm pierstr; 
        tm drugstr; 
		tm *wyniki;

        pierstr.tm_year = 2012 - 1900; 
        pierstr.tm_mon = 12-1; 
        pierstr.tm_mday = 1; 
		pierstr.tm_hour = 0;
		pierstr.tm_min = 0;
		pierstr.tm_sec = 0;

		pierczas = mktime(&pierstr);
		cout<<"pierwszy czas: "<<pierczas<<endl;
		cout<<"pierstr.tm_wday: "<<pierstr.tm_wday<<endl;

        drugstr.tm_year = 2013 - 1900; 
        drugstr.tm_mon = 2-1; 
        drugstr.tm_mday = 28; 
		drugstr.tm_hour = 0;
		drugstr.tm_min = 0;
		drugstr.tm_sec = 0; 

		drugczas = mktime(&drugstr);
		cout<<"drugi czas: "<<drugczas<<endl;
		cout<<"drugstr.tm_wday: "<<drugstr.tm_wday<<endl;

        roznica = difftime(drugczas, pierczas); 

        cout<<"Roznica to: "<<roznica; 

		cout<<"\nObliczanie poszczegolnych dni:\n 0 - Niedziela, 1 - Poniedzialek, 2 - Wtorek, 3 - Œroda, 4 - Czwartek, 5 - Pi¹tek, 6 - Sobota\n";

		for(drugczas; drugczas >= pierczas; pierczas += 86400){
			wyniki = localtime(&pierczas);
			cout<<"wyniki->tm_wday = "<<wyniki->tm_wday<<endl;

			if(wyniki->tm_wday == 5) {
				piatkow++;
			}

			if(wyniki->tm_wday == 2) {
				wtorkow++;
			}
		}

		cout<<"W okresie czasu od 1.12.2012 do 28.02.2013 jest: "<<piatkow<<" piatkow i "<<wtorkow<<" wtorkow ";

        getchar(); 
        return 0; 

}