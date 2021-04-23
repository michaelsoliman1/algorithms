#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>  

#include "selection_sort.h"

int main()
{
    std::ifstream dataFile;
    std::vector<int> data;

    dataFile.open("data.txt",std::ios::in); 

    if (dataFile.is_open())
    {   
        std::string tp;
        
        while(getline(dataFile, tp))
        { 
            data.push_back(stoi(tp));
        }
        dataFile.close(); //close the file object.
    }

    auto start = std::chrono::system_clock::now();
    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout<<data[i]<<std::endl;
    }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    return 0;
}