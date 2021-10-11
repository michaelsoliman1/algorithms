//
// Created by Michael Soliman on 11/06/2021.
//

#include "iostream"
#include "vector"
#include "unordered_map"

/// half of test cases fail
int main() {
    int arraySize, partitionSize, partitionsNumber;
    std::cin>>arraySize>>partitionSize>>partitionsNumber;

    std::vector<int> array(arraySize);
    for (int i = 0; i < arraySize; i++) {
        std::cin>>array[i];
    }

    std::vector<int*> used(arraySize);
    int maxSum = 0;
    for (int i = 0; i < partitionsNumber; i++) {
        int currentPartitionValue = 0;
        int maxPartitionValue = 0;
        int maxPartitionIndex;
        for (int j = 0; j <= arraySize - partitionSize; j++) {
            if(used[j] != nullptr) break;
            currentPartitionValue += array[j];
            for (int k = 1; k < partitionSize; k++) {
                if (used[j + k] != nullptr) break;
                currentPartitionValue += array[j + k];
            }
            if (maxPartitionValue < currentPartitionValue){
                maxPartitionValue = currentPartitionValue;
                maxPartitionIndex = j;
            }
            currentPartitionValue = 0;
        }
        maxSum += maxPartitionValue;
        used[maxPartitionIndex] = &maxPartitionValue;
    }
    std::cout<<maxSum;
    return 0;
}
