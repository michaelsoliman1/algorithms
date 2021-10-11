#include <iostream>
#include <typeindex>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void generateRoutes(vector<int> generatedRoutes, vector<int> routes, vector<bool> isUsed, 
				int n,int index, vector<vector<int>> matrix, int& isTripPossible){
	if(isTripPossible == 1) return;

	if(index == n){
		if(matrix[generatedRoutes[0]][0] ==0){ 
			return;
		}
		for(int i =0;i<generatedRoutes.size() - 1; i++){
			if(matrix[generatedRoutes[i]][generatedRoutes[i+1]] ==0){
				return;
			}
		}
		if(matrix[generatedRoutes[generatedRoutes.size()-1]][0] ==0){ 
			return;
		}
		isTripPossible = 1;
		return;
	}
	for(int i =0; i < n ; ++i) {
		if(!isUsed[i]){
			isUsed[i] = true;
			generatedRoutes.push_back(routes[i]);
			generateRoutes(generatedRoutes, routes,isUsed, n, index +1, matrix, isTripPossible);
			generatedRoutes.pop_back();
			isUsed[i] = false;
		}
	}
		
}

int main() {
	int galxNo;
	cin>>galxNo;
	int edgesNo;
	cin>>edgesNo;
	
	vector<vector<int>> matrix(galxNo, vector<int>(galxNo));
	
	int val1, val2;	
	for(int i = 0; i<edgesNo;i++){
		cin>>val1>>val2;		
		matrix[val1][val2] = 1;
		matrix[val2][val1] = 1;
		for(int j = 0;j<galxNo;j++){
			if(i==j){
				matrix[i][j] = 0;
			}
		}
	}
	
	vector<int> routes (galxNo -1);
	for(int i = 0; i<galxNo -1;i++){
		routes[i] = i + 1;
	}
	
	vector<int> generatedRoutes;
	vector<bool> isUsed(galxNo -1, false);
	int isTripPossible = 0;

	generateRoutes(generatedRoutes,routes,isUsed,galxNo - 1,0, matrix,isTripPossible);

	cout<<isTripPossible;
	
	return 0;
}

