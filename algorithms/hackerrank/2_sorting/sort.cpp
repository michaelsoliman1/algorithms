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
#include "./algorithms/selection_sort.h"
#include "./algorithms/quick_sort.h"
#include "./algorithms/merge_sort.h"

int main(int argc, char** argv) {
    if(argc < 4) return 0;

    int algNum = atoi(argv[1]);
    char* inputPath = argv[2];
    char* outputPath = argv[3];
    char* writeTimePath = argv[4];

    std::fstream dataFile;
    int* data = new int;

    dataFile.open(inputPath,std::ios::in);

    int size = 0;

    if (dataFile.is_open())
    {   
        std::string tp;
        
        while(getline(dataFile, tp))
        { 
            data[size] = stoi(tp);
            size++;
        }
        dataFile.close(); //close the file object.
    }

    int d [6] = {8, 11, 3, 6,4, 1};

    auto start = std::chrono::system_clock::now();
    switch (algNum) {
        case 0:
            SelectionSort::sort(data, size);
            break;
        case 1:
            InsertionSort::sort(data, size);
            break;
        case 2:
            MergeSort::sort(data, 0, size);
            break;
        case 3:
            QuickSort::sort(data, 0, size);
            break;

    }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;

    dataFile.open(outputPath,std::ios::out | std::ios::trunc);

    if (dataFile.is_open())
    {
        for(int i =0;i < size;i++)
        {
            dataFile << data[i] << std::endl;
        }
        dataFile.close(); //close the file object.
    }

    dataFile.open(writeTimePath,std::ios::out | std::ios::trunc);

    if (dataFile.is_open())
    {
        dataFile<<elapsed_seconds.count()<<std::endl;
        dataFile.close(); //close the file object.
    }

    return 0;
}

//    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
