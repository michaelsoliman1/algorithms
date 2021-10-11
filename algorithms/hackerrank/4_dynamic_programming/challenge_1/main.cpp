//
// Created by Michael Soliman on 11/06/2021.
//

#include "iostream"
#include "vector"
#include <algorithm>

int findMaxNumberOfOrders(const std::vector<long>& ordersValues, long noOfGrams){
    int maxOrders = 0;
    long currentValue = 0;
    for (long ordersValue : ordersValues) {
        if(currentValue + ordersValue <= noOfGrams){
            currentValue += ordersValue;
            maxOrders++;
        } else {
            break;
        }
    }
    return maxOrders;
}

int main() {
    int noOfOrders;
    long noOfGrams;
    std::cin>>noOfOrders>>noOfGrams;

    /// vector to hold each order's summed value
    std::vector<long> ordersValues(noOfOrders);

    long smallBurgerWeight, largeBurgerWeight;
    std::cin>>smallBurgerWeight>>largeBurgerWeight;

    for (int i = 0; i < noOfOrders; i++) {
        long noOfSmallBurgers, noOfLargeBurgers, orderValue;
        std::cin>>noOfSmallBurgers>>noOfLargeBurgers;

        orderValue = noOfSmallBurgers*smallBurgerWeight + noOfLargeBurgers*largeBurgerWeight;
        ordersValues[i] = orderValue;
    }
    /// sort the array in ascending order
    std::sort(ordersValues.begin(), ordersValues.end());

    std::cout<<findMaxNumberOfOrders(ordersValues, noOfGrams);
    return 0;
}
