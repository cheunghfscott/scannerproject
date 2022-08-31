#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <time.h>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time



std::string return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}
std::string convertostring(char*a)
{
	std::string s(a);
	return s;
}


int main()
{
	std::ofstream myfile;
	myfile.open("record.txt");
	//std::string code;
	int const counter = 10;
	int i =0;
	char delimit = '\r';
	char buffer[10];
	while( i < counter)
	{
		//std::cin.getline(buffer,19);
		
		std::cin.get(buffer,10);

		//std::getline(std::cin, code);
		std:: cout << "read:" << buffer<<"\n";
	
		std::string code = convertostring(buffer);

		myfile << code;
		myfile << " ";
		myfile << return_current_time_and_date();
		myfile << "\n";
		myfile.flush();
		//memset(&code, 0, sizeof(code));
		memset(&buffer, 0, sizeof(buffer));
		i++;
	}
	myfile.close();

	std::cout << "finished";
	return 0;
}