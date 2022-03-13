
#include <iostream>
#include "vector"
#include "string"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void generateStrings(string generatedString,vector<int> counts, int stringLength, int k, int level){
    if(generatedString.size() == stringLength){
        cout<<generatedString<<endl;
        return;
    }
    for (int i = 0; i < k; ++i) {
        if(counts[i] != 0){
            counts[i]--;
            generateStrings(generatedString+std::to_string(i), counts, stringLength, k, level+1);
            counts[i]++;
        }
    }
}

/// \IMPLEMENTATION DONE
/// \TESTCASES PASSED
int main(){
    int k, stringLength;
    cin>>k>>stringLength;

    vector<int> counts(k);

    for (int i = 0; i < k; ++i) {
        cin>>counts[i];
    }

    generateStrings("", counts, stringLength, k, 0);
}

