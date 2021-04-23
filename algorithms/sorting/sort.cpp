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

#include "./algorithms/insertion_sort.h"

int main()
{
    std::ifstream dataFile;
    int* data = new int;

    dataFile.open("data.txt",std::ios::in); 

    int count = 0;

    if (dataFile.is_open())
    {   
        std::string tp;
        
        while(getline(dataFile, tp))
        { 
            data[count] = stoi(tp);
            count++;
        }
        dataFile.close(); //close the file object.
    }

    std::cout<<count<<std::endl;


    auto start = std::chrono::system_clock::now();

    InsertionSort::sort(data, count);

    for (int i = 0; i < count; i++)
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