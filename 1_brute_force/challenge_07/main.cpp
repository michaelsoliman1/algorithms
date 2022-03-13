//
// Created by Michael Soliman on 06/03/2022.
//

#include <iostream>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

long vectorSum(const set<long>& vec){
    long sum = 0;
    for (long element: vec) {
        sum+=element;
    }
    return sum;
}

void findMaxCells(vector<long> cells, set<long> generated, int &maxCells, int cellsLength, int level){
    long sum = vectorSum(generated);

    if(sum == 0 && generated.size() > maxCells){
        maxCells = generated.size();
    }

    if(level == cellsLength) return;

    findMaxCells(cells, generated,maxCells, cellsLength, level + 1);
    generated.insert(cells[level]);
    findMaxCells(cells, generated, maxCells,cellsLength, level + 1);
}

/// \IMPLEMENTATION DONE
/// \TESTCASES PASSED
int main() {
    int M,N;
    cin>>N>>M;
    vector<long> cells(N*M);

    for (int i = 0; i < N * M; ++i) {
             cin>>cells[i];
    }

    int maxCells = 0;

    findMaxCells(cells, {}, maxCells,N*M,0);

    cout<<maxCells;
}
