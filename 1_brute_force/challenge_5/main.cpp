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

 void checkMission(int sum, vector<int> coins, int total,int& result, int n,int index){
	if(sum == total)
		result = 1;
	if(n==index)
		return;
		
	checkMission(sum + coins[index], coins, total, result,  n, index+1);	
	checkMission(sum, coins, total,result, n, index+1);		
}

int main(){
	int total;
	cin>>total;
	int size;
	cin>>size;
	vector<int> coins(size);
	for(int i =0;i<size;i++){
		cin>>coins[i];
	}
	
		
	int result = 0;
	checkMission(0, coins, total,result, size, 0);
	
	cout<<result<<endl;
	
	return 0;
}













