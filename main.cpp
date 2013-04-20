#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

int main(){

	// get current time
	time_t epoch_time;
    struct tm *tm_p;
    epoch_time = time( NULL );
    tm_p = localtime( &epoch_time );

    // get date items
    int day = tm_p->tm_mday;
    int month = tm_p->tm_mon+1;
    int year = tm_p->tm_year-100;

    int hour = tm_p->tm_hour;
    int minute = tm_p->tm_min;
    int second = tm_p->tm_sec;

    // convert to std::string
    std::string s_day = std::to_string(day);
    std::string s_month = std::to_string(month);
    std::string s_year = std::to_string(year);

    std::string s_hour = std::to_string(hour);
    std::string s_minute = std::to_string(minute);
    std::string s_second = std::to_string(second);

    // add leading zeros
    if(day < 10){
    	s_day = "0" + s_day;
    }
    if(month < 10){
    	s_month = "0" + s_month;
    }
    if(year < 10){
    	s_year = "0" + s_year;
    }

    if(hour < 10){
        s_hour = "0" + s_hour;
    }
    if(minute < 10){
        s_minute = "0" + s_minute;
    }
    if(second < 10){
        s_second = "0" + s_second;
    }

    // construct commands
    std::string datestring = ":SC" + s_month + "/" + s_day + "/" + s_year + "#";
    std::string timestring = "#:SL" + s_hour + ":" + s_minute + ":" + s_second + "#";

  	// open port
	std::fstream port("/dev/ttyUSB0");

    if(!port){
        std::cout << "Port cannot be opened!" << std::endl;
        return 1;
    }
    
	std::cout << "Port opened..." << std::endl;

	std::cout << "Setting date..." << std::endl;

    // write date
    port << datestring;

    std::cout << "Setting time..." << std::endl;

    // write time
    port << timestring;

    port.close();

	return 0;
}