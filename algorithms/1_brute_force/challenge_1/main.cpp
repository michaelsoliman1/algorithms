#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

typedef unordered_map<int, unordered_map<int, int>> _floor;
typedef unordered_map<int,_floor> lair;


void generateRoutes1(int n,int floorNo, int roomX,int roomY, lair _lair,int amount, int &minAmount) {
	amount+= _lair[floorNo][roomX][roomY];	
			
	if(floorNo == n-1 && roomX == n-1 && roomY == n-1){
		if(amount < minAmount){
			minAmount = amount;
		}
		return;
	}		
	
	if(roomX < n-1) generateRoutes1(n, floorNo, roomX+1, roomY,_lair, amount, minAmount);
	if(roomY < n-1) generateRoutes1(n, floorNo, roomX, roomY+1,_lair, amount, minAmount);
	if(floorNo < n-1) generateRoutes1(n, floorNo+1, roomX, roomY,_lair, amount, minAmount);
}

void generateRoutes(int n,int floorNo, int roomX,int roomY, int* list,int amount, int &minAmount){
	amount+= list[roomX + (roomY*n) +(n*n*floorNo)];	
			
	if(floorNo == n-1 && roomX == n-1 && roomY == n-1){
		if(amount < minAmount){
			minAmount = amount;
		}
		return;
	}		
	
	if(roomX < n-1) generateRoutes(n, floorNo, roomX+1, roomY,list, amount, minAmount);
	if(roomY < n-1) generateRoutes(n, floorNo, roomX, roomY+1,list, amount, minAmount);
	if(floorNo < n-1) generateRoutes(n, floorNo+1, roomX, roomY,list, amount, minAmount);
}

int main()
{
	int n;
	cin>>n;

	int n3 = n*n*n;
	int* list = new int[n3];
	
	for(int i = 0 ; i< n3 ; i++){
		cin>> list[i];
	}


	int minAmount = std::numeric_limits<int>::max();
	generateRoutes(n,0,0,0,list,0,minAmount);
	
	cout<<minAmount;
	return 0;
	
}
