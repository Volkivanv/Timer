#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
//#include <vector>

int main() {


    std::time_t tInit = std::time(nullptr);
    std::tm local = *std::localtime(&tInit);
    std::cout << "Input time period in format 'MM:SS'!" << std::endl;
    std::cin >> std::get_time(&local, "%M:%S");


    long long period = local.tm_min*60+local.tm_sec;

    std::time_t baseTime = mktime(&local);
    std::time_t beginTime = std::time(nullptr);
    std::time_t stopTime = std::time(nullptr) + period;
    for(std::time_t t = beginTime; t < stopTime; t = std::time(nullptr)){
        std::time_t showTime = baseTime - (t - beginTime);
        std::tm localNow = *std::localtime(&showTime);
        std::cout << std::put_time(&localNow,"%M:%S") << std::endl;
        Sleep(1000);
    }

    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
