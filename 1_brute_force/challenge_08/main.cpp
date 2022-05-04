//
// Created by Michael Soliman on 11/03/2022.
//

#include <iostream>
#include <climits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define ROW_SIZE 3
#define TOP_LEFT_INDEX 0
#define BOTTOM_LEFT_INDEX 6

bool inGrid(int cellIndex, int gridSize){
    return cellIndex >= 0 && cellIndex < gridSize;
}

void maxCarrots(int& currentCarrotsMax,int carrotsCount, const vector<int>& carrotsCountGrid, int cellIndex,
                vector<bool> visited, int currentJumps, int minJumps){

    /// indicates what visited cells till now
    visited[cellIndex] = true;
    currentJumps += 1;

    /// add cell count to current carrots counts
    carrotsCount += carrotsCountGrid[cellIndex];


    /// check if current carrots count is greater than the max
    if(carrotsCount > currentCarrotsMax){
        /// update max carrots
        currentCarrotsMax = carrotsCount;
    }

    /// if both are negative,
    if(carrotsCount < 0 && currentCarrotsMax < 0){
        if(carrotsCount < currentCarrotsMax && currentJumps <= minJumps){
            currentCarrotsMax = carrotsCount;
        }
    }

    /// exit condition
    /// we reached the last cell
    if(cellIndex == BOTTOM_LEFT_INDEX){
        return;
    }

    int gridSize = carrotsCountGrid.size();
    int topCellIndex = cellIndex - ROW_SIZE;
    int downCellIndex = cellIndex + ROW_SIZE;

    int topRightCellIndex;
    int topLeftCellIndex;
    int downRightCellIndex ;
    int downLeftCellIndex ;

    /// means we are at the right edge of grid
    if((topCellIndex+1) % ROW_SIZE == 0){
        /// set right cells as out of grid
        topRightCellIndex = -1;
        downRightCellIndex = -1;
    } else {
        topRightCellIndex = topCellIndex + 1;
        downRightCellIndex = downCellIndex + 1;
    }

    /// means we are at the left edge of grid
    if(topCellIndex % ROW_SIZE == 0){
        /// set left cells as out of grid
        topLeftCellIndex = -1;
        downLeftCellIndex = -1;
    } else {
        topLeftCellIndex = topCellIndex - 1;
        downLeftCellIndex = downCellIndex - 1;
    }


    if(inGrid(topCellIndex, gridSize) && !visited[topCellIndex]){
        maxCarrots(currentCarrotsMax, carrotsCount, carrotsCountGrid, topCellIndex, visited, currentJumps,minJumps);
    }
    if(inGrid(downCellIndex, gridSize) && !visited[downCellIndex]){
        maxCarrots(currentCarrotsMax, carrotsCount, carrotsCountGrid, downCellIndex, visited, currentJumps,minJumps);
    }
    if(inGrid(topRightCellIndex, gridSize) && !visited[topRightCellIndex]){
        maxCarrots(currentCarrotsMax, carrotsCount , carrotsCountGrid, topRightCellIndex, visited, currentJumps,minJumps);
    }
    if(inGrid(topLeftCellIndex, gridSize) && !visited[topLeftCellIndex]){
        maxCarrots(currentCarrotsMax, carrotsCount , carrotsCountGrid, topLeftCellIndex, visited, currentJumps,minJumps);
    }
    if(inGrid(downRightCellIndex, gridSize) && !visited[downRightCellIndex]){
        maxCarrots(currentCarrotsMax, carrotsCount , carrotsCountGrid, downRightCellIndex, visited, currentJumps,minJumps);
    }
    if(inGrid(downLeftCellIndex, gridSize) && !visited[downLeftCellIndex]){
        maxCarrots(currentCarrotsMax, carrotsCount , carrotsCountGrid, downLeftCellIndex, visited, currentJumps,minJumps);
    }
    currentJumps -= 1;
    visited[cellIndex] = false;

}

/// \IMPLEMENTATION STOPPED
/// \TESTCASES 6 / 15
int main(){
    /// holds each cell carrots counts
    vector<int> grid(9);

    /// holds a boolean for each cell if it's previously visited or not
    vector<bool> visited(9, false);

    for (int & i : grid) {
        cin>>i;
    }

    int max = INT_MIN;
    maxCarrots(max, 0, grid, TOP_LEFT_INDEX, visited, 0, 3);
    cout<<max;
}
