#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

void generateTreasure(vector<vector<int>> generatedItems,vector<vector<int>> items, int noOfItems,
						int index, int &maxValue,int maxWeight){
	
	if(index == noOfItems){
		int maxV = 0;
		int weight = 0;
		if(!generatedItems[0].empty()){
			for(int i = 0;i < generatedItems[0].size(); i++){
				maxV += generatedItems[0][i];
				weight += generatedItems[1][i];
			}
			if(weight <= maxWeight){
				if(maxV > maxValue)
					maxValue = maxV;
			}
		}
		return;
	}
	

	generateTreasure(generatedItems,items, noOfItems, index +1, maxValue, maxWeight);
	generatedItems[0].push_back(items[0][index]);
	generatedItems[1].push_back(items[1][index]);

	generateTreasure(generatedItems,items, noOfItems, index +1, maxValue, maxWeight);
		
}

int main() {
	int weight;
	cin>>weight;
	int n;
	cin>>n;
	vector<vector<int>> items (2, vector<int> (n));
		
	int w, v;	
	for(int i = 0; i<n;i++){
		cin>>w>>v;	
		items[0][i] = v;
		items[1][i] = w;
	}
	vector<vector<int>> generatedItems (2, vector<int> ());
	int maxValue =0;
	generateTreasure(generatedItems, items, n, 0, maxValue, weight);
	cout<<maxValue<<endl;
	
	
	return 0;
	
}
