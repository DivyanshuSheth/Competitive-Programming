#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> moveZerosToTheEnd(vector <int> &inputVector) {
    if (inputVector.size() <= 1) {
        return inputVector;
    } 

    int inputVectorSize = inputVector.size(), lastNonZeroElement = -1;
    queue <int> freeSpaceQueue;
    
    for (int i = 0; i < inputVectorSize; i++) {
        if (inputVector[i] == 0) {
            freeSpaceQueue.push(i);
        }
        else if (freeSpaceQueue.empty()) {
            continue;
        }
        else {
            lastNonZeroElement = freeSpaceQueue.front();
            inputVector[freeSpaceQueue.front()] = inputVector[i];
            freeSpaceQueue.pop();
            freeSpaceQueue.push(i);
        }
    }

    if (lastNonZeroElement != -1) {
        for (int i = lastNonZeroElement + 1; i < inputVectorSize; i++) {
            inputVector[i] = 0;
        }
    }
    return inputVector;
}

int main() {
    vector <int> inputVector {10, 20};
    vector <int> changedVector = moveZerosToTheEnd(inputVector);
    
    for (int i = 0; i < changedVector.size(); i++) {
        cout << changedVector[i] << " ";
    }

    cout << "\n";

    return 0;
}
