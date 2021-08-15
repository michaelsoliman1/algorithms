//
// Created by Michael Soliman on 11/06/2021.
//

#include "iostream"
#include "vector"
#include <algorithm>

long findMinimumSteps(std::vector<long> blocks,int noOfBlocks){
    long minSteps = 0;
    long minHeight = *std::min_element(blocks.begin(), blocks.end());
    minSteps += minHeight;
    for (int i = 0; i < noOfBlocks; i++) {
        if (blocks[i] > minHeight) {
            if (i == noOfBlocks -1){
                minSteps++;
                break;
            }
            for (int j = i+1; j < noOfBlocks; j++) {
                if (blocks[j] != blocks[i]){
                    minSteps++;
                    i = j-1;
                    break;
                }
            }
        }
    }
    return minSteps < noOfBlocks ? minSteps : noOfBlocks;
}

/// 7 test cases fail out of 21
int main() {
    int noOfBlocks;
    std::cin>>noOfBlocks;

    /// array to hold blocks, each block will be
    /// 1 m in width, and blocks[i] in height
    std::vector<long> blocks(noOfBlocks);
    for (int i = 0; i < noOfBlocks; i++) {
        std::cin>>blocks[i];
    }

    std::cout<<findMinimumSteps(blocks, noOfBlocks);
    return 0;
}
