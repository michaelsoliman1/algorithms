#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <string>
#include <fstream>
#include <chrono>

#include "./algorithms/insertion_sort.h"
#include "./algorithms/selection_sort.h"
#include "./algorithms/quick_sort.h"
#include "./algorithms/merge_sort.h"

using std::cin;
using std::cout;
using std::endl;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

int main(int argc, char **argv)
{
    if (argc < 4)
        return -1;

    int algNum;
    char *inputFile;
    char *outputFile;
    char *timeFile;

    try
    {
        algNum = std::stoi((argv[1]));
        inputFile = argv[2];
        outputFile = argv[3];
        timeFile = argv[4];
    }
    catch (std::exception const &e)
    {
        cout << "error : " << e.what() << endl;
        return -1;
    }

    std::fstream file;
    int *data = new int();
    int size = 0;

    file.open(inputFile, std::fstream::in);
    if (file.is_open())
    {
        std::string tp;
        while (getline(file, tp))
        {
            data[size] = stoi(tp);
            size++;
        }
        file.close(); // close the file object.
    }
    else
    {
        cout << "error : "
             << "couldn't read data" << endl;
        return -1;
    }

    auto start = high_resolution_clock::now();
    switch (algNum)
    {
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
    auto end = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto elapsed_seconds = duration_cast<milliseconds>(end - start);

    file.open(outputFile, std::fstream::out | std::fstream::trunc);
    if (file.is_open())
    {
        for(int i =0; i < size; i++)
        {
            file << data[i] << std::endl;
        }
        file.close(); //close the file object.
    }
    else
    {
        cout << "error : "
             << "couldn't write sorted data" << endl;
        return -1;
    }

    file.open(timeFile, std::fstream::out | std::fstream::app);
    if (file.is_open())
    {
        file << inputFile << " : " << elapsed_seconds.count() << "ms" << std::endl;
        file.close(); //close the file object.
    }
    else
    {
        cout << "error : "
             << "couldn't write time" << endl;
        return -1;
    }

    return 0;
}
