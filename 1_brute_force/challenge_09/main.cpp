
#include <iostream>
#include "vector"
#include "string"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void generateStrings(const string& generatedString,vector<int> counts, int stringLength, int k){
    /// exit condition
    if(generatedString.size() == stringLength){
        cout<<generatedString<<endl;
        return;
    }

    /// loop over all the numbers from 0 to k-1
    for (int i = 0; i < k; ++i) {
        /// if we still need to add the number, generate a string with this number
        /// and decrement its occurrences
        if(counts[i] != 0){
            counts[i]--;
            generateStrings(generatedString+std::to_string(i), counts, stringLength, k);

            /// increment the number again to be used in next callbacks
            counts[i]++;
        }
    }
}

/// \IMPLEMENTATION DONE
/// \TESTCASES PASSED
int main(){
    /// k is the radix count
    int k, stringLength;
    cin>>k>>stringLength;

    /// create an array to hold how many occurrence should a number have
    vector<int> counts(k);

    for (int i = 0; i < k; ++i) {
        cin>>counts[i];
    }

    /// recursive call
    generateStrings("", counts, stringLength, k);
}

