#include<ctime>
#include"datetots.h"

using namespace std;

int datetots::timestamp(int year,int month, int day,int hour, int min, int sec)
{
time_t rawtime;
struct tm * timeinfo;

//int year=2015, month=12, day=26, hour = 0, min = 0, sec = 1;

/* get current timeinfo: */
time ( &rawtime ); //or: rawtime = time(0);
/* convert to struct: */
timeinfo = localtime ( &rawtime );

/* now modify the timeinfo to the given date: */
timeinfo->tm_year   = year - 1900;
timeinfo->tm_mon    = month - 1;    //months since January - [0,11]
timeinfo->tm_mday   = day;          //day of the month - [1,31]
timeinfo->tm_hour   = hour;         //hours since midnight - [0,23]
timeinfo->tm_min    = min;          //minutes after the hour - [0,59]
timeinfo->tm_sec    = sec;          //seconds after the minute - [0,59]

/* call mktime: create unix time stamp from timeinfo struct */
int date;
date = mktime ( timeinfo );

return date;
}


