//
// Created by Michael Soliman on 07/05/2021.
//

#include <iostream>
#include <unordered_map>
#include "vector"

int canMeasureTrees(std::vector<int> tapeValues, int noOfValues,int tapeLength,  int x, int y) {
    /// check if tape values can measure x and y
    bool canMeasureX = false;
    bool canMeasureY = false;

    /// possible values to add to the tape to get x
    std::vector<int> xPossibleValues;

    xPossibleValues.push_back(x);
    for (int i = 0; i < noOfValues -1; i++) {
        for (int j = i + 1; j < noOfValues ; j++) {
            if (tapeValues[j] - tapeValues[i] == x && !canMeasureX) {
                canMeasureX = true;
            }
            if (tapeValues[j] - tapeValues[i] == y && !canMeasureY) {
                canMeasureY = true;
            }
            /// save the difference between the current value and x
            if(tapeValues[j] - x >= 0 )
                xPossibleValues.push_back(tapeValues[j] - x);
            if (tapeValues[j] + x < tapeLength)
                xPossibleValues.push_back(tapeValues[j] + x);
        }
    }

    /// if yes => return 0;
    if (canMeasureX && canMeasureY) return 0;

    /// if one of them is false, then we only need one value to add.
    if (canMeasureX && !canMeasureY) return 1;
    if (!canMeasureX && canMeasureY) return 1;

    /// if both false, get the min number of needed values and return it;
    /// we cannot return 2 because one value can be added to make them both true.
    for (int xPossibleValue : xPossibleValues) {
        for (int j = 0; j < noOfValues; j++) {
            ///  meaning that one of the added values for x can be used for y
            if (tapeValues[j] - xPossibleValue == y) return 1;
        }
    }
    return 2;
}

int main() {
    /// the number of distances on the measuring tape N,
    /// the length of the measuring tape L and the two allowed lengths of the trees X,Y
    int N, L, X, Y;
    std::cin>>N>>L>>X>>Y;

    std::vector<int> tapeValues(N);

    for (int i = 0; i < N; i++) {
        std::cin>>tapeValues[i];
    }

    int minNoOfDistancesNeeded = canMeasureTrees(tapeValues, N,L, X,Y);

    std::cout<<minNoOfDistancesNeeded;

    return 0;
}
