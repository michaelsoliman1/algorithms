#!/bin/sh

rm -r data_set
rm -r running_time

mkdir data_set
mkdir running_time

echo "Generating Data Set.."
python runscript.py 1000 data_set/0_data_1000.txt
python runscript.py 5000 data_set/1_data_5000.txt
python runscript.py 10000 data_set/2_data_10000.txt
python runscript.py 50000 data_set/3_data_50000.txt
python runscript.py 75000 data_set/4_data_75000.txt
python runscript.py 100000 data_set/5_data_100000.txt
python runscript.py 500000 data_set/6_data_500000.txt
echo "Generated Data Set Successfully."

algorithm=""

for i in $(seq 0 3); do
    if  [ "$i" = "0" ]; then
        algorithm="selection_sort"
    elif [ "$i" = "1" ]; then
        algorithm="insertion_sort"
    elif [ "$i" = "2" ]; then
        algorithm="merge_sort"
    elif [ "$i" = "3" ]; then
        algorithm="quick_sort"
    else
        echo "out of range"
    fi

    for filename in data_set/*.txt; do
        echo "Running $algorithm algorithm for $filename"
        /Users/michael/Dev/algorithms/cmake-build-debug/2_sorting "$i" "$filename" "sorted_data.txt" "running_time/$algorithm.txt"
        /Users/michael/Dev/algorithms/cmake-build-debug/2_sorting "$i" "sorted_data.txt" "sorted_data.txt" "running_time/$algorithm.txt"
    done
done
