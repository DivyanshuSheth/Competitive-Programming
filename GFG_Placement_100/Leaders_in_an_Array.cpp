#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> leadersInTheArray(vector <int> &inputSequence) {
    vector <int> finalLeadersInTheArray;
    int maxOfRemainingElements = INT_MIN;
    
    for (int i = inputSequence.size() - 1; i >= 0; --i) {
        if (inputSequence[i] > maxOfRemainingElements) {
            finalLeadersInTheArray.push_back(inputSequence[i]);
            maxOfRemainingElements = inputSequence[i];
        }
    }

    reverse(finalLeadersInTheArray.begin(), finalLeadersInTheArray.end());

    return finalLeadersInTheArray;
}

int main() {
    vector <int> inputSequence {30, 20, 10};
    vector <int> finalLeadersInTheArray = leadersInTheArray(inputSequence);

    for (int i = 0; i < finalLeadersInTheArray.size(); i++) {
        cout << finalLeadersInTheArray[i] << " ";
    }
    
    cout << "\n";

    return 0;
}