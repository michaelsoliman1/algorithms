#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void generateTeam(vector<int> team, int teamSize,int index, vector<vector<int>> matrix, int& maxTeam){
	
	if(team.size() !=0) {
		bool hasSyn = true;
		for(int i =0;i<team.size() - 1; i++){
			for(int j = i+1;j<team.size();j++){
				if(matrix[team[i]][team[j]] ==0) hasSyn = false;
			}
		}
		if(hasSyn && maxTeam < team.size()) {
			maxTeam = team.size();
		};
	}
	if(index == teamSize){
		return;
	}
	generateTeam(team, teamSize, index +1, matrix, maxTeam);
	team.push_back(index);
	generateTeam(team, teamSize, index +1, matrix, maxTeam);
		
}

int main()
{
	int teamSize;
	cin>>teamSize;
	int edgesNo;
	cin>>edgesNo;
	
	vector<vector<int>> matrix(teamSize, vector<int>(teamSize));
	
	int val1, val2;	
	for(int i = 0; i<edgesNo;i++){
		cin>>val1>>val2;		
		matrix[val1][val2] = 1;
		matrix[val2][val1] = 1;
		for(int j = 0;j<teamSize;j++){
			if(i==j){
				matrix[i][j] = 0;
			}
		}
	}
	
	vector<int> team;
	int maxTeam = 0;
	generateTeam(team, teamSize,0, matrix, maxTeam);
	
	cout<<maxTeam<<endl;
	
	
	return 0;
}

