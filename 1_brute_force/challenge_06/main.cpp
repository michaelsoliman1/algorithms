//
// Created by Michael Soliman on 06/03/2022.
//

#include <iostream>
#include <vector>
#include "algorithm"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void generateTeam(const vector<char>& characters, vector<char> team,int teamSize, int N, int level){
    if(team.size() == teamSize){
        for (char name : team) {
            cout<<name;
        }
        cout<<endl;
        return;
    }
    if (N == level) return;

    team.push_back(characters[level]);
    generateTeam(characters, team, teamSize, N, level + 1);
    team.pop_back();
    generateTeam(characters, team, teamSize, N, level + 1);
}

/// \IMPLEMENTATION DONE
/// \TESTCASES PASSED
int main() {
    int N, M;
    cin>>N>>M;

    vector<char> characters(N);
    vector<char> team;

    for(int i = 0; i<N;i++){
        cin>>characters[i];
    }
    std::sort(characters.begin(), characters.end());

    generateTeam(characters,team, M,N,0);
}
