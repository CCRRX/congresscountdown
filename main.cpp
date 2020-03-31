#include<iostream>
#include<ctime>
#include "datetots.h"
#include<time.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
	time_t zeit;
	int endzeit, countdown,jahr,congress,stunde,minu,sec,alt;

	datetots ts;

    while(true){
        time_t now = time(0);

        tm *ltm = localtime(&now);

        jahr = 1900 + ltm->tm_year;
        stunde = ltm->tm_hour;
        minu = ltm->tm_min;
        sec = ltm->tm_sec;

        congress = jahr-1983;

        endzeit = ts.timestamp(jahr,12,26,0,0,0);

		countdown = endzeit - (time(&zeit));
		usleep(1000);
        if(sec!=alt){
            alt=sec;
            system ("clear");
            cout << congress << "c3" << endl;
            cout << "Day: " << -1*(countdown/86400) << endl;

            if(stunde<10){
                cout << "0" << stunde;
            }else{
                cout << stunde;
            }
        cout << ":";
		if(minu <10){
            cout <<"0"<<minu;
		}else{
            cout << minu;
        }
		cout << ":";
		if(sec<10){
            cout << "0"<< sec;
		}else{
            cout <<sec;
        }
            cout <<endl;
		}
    }
}
