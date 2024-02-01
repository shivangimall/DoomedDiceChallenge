#include<bits/stdc++.h>
using namespace std;


vector<int> calculateOccurrences(vector<int>& dieA, const std::vector<int>& dieB) {
    vector<int> occurrences(11, 0); // Counts for sums 2 to 12
    for (int i = 0; i < dieA.size(); i++) {
        for (int j = 0; j < dieB.size(); j++) {
            occurrences[dieA[i] + dieB[j] - 2]++;
        }
    }
    return occurrences;
}


bool isValidTransformation(const std::vector<int>& newDieA) {
    for (int face : newDieA) {
        if (face > 4) {
            return false;
        }
    }
    return true;
}


vector<int> updatedDieB(vector<int>& dieB, int index, int newValue) {
    vector<int> updatedDieB = dieB;
    updatedDieB[index] = newValue;
    return updatedDieB;
}


vector<int> compensateDieB(vector<int>& newDieA, vector<int>& originalOccurrences) {
    vector<int> newDieB(newDieA.size());

    // Iterate through possible values for each face of Die B
    for (int i = 0; i < newDieB.size(); i++) {
        for (int newFaceValue = 1; newFaceValue <= 12; newFaceValue++) { // Allow values up to 12
            // Calculate new occurrences with the potential Die B face
            vector<int> tentativeOccurrences = calculateOccurrences(newDieA, updatedDieB(newDieB, i, newFaceValue));

            // If occurrences match, set the face value and move to the next face
            if (tentativeOccurrences == originalOccurrences) {
                newDieB[i] = newFaceValue;
                break; // Move to the next face
            }
        }
    }

    return newDieB;
}




vector<vector<int>> undoomDice(vector<int>& dieA, vector<int>& dieB) {
    vector<int> originalOccurrences = calculateOccurrences(dieA, dieB);

    for (int i = 0; i < dieA.size(); i++) {
        for (int newFaceValue = 1; newFaceValue <= 4; newFaceValue++) {
            vector<int> newDieA = dieA;
            newDieA[i] = newFaceValue;

            if (isValidTransformation(newDieA)) {
                vector<int> newOccurrences = calculateOccurrences(newDieA, dieB);

                if (newOccurrences == originalOccurrences) {
                    vector<int> newDieB = compensateDieB(newDieA, originalOccurrences);
                    return { newDieA, newDieB };
                }
            }
        }
    }

    return {};
}

int main() {
    vector<int> dieA = {1, 2, 3, 4, 5, 6};
    vector<int> dieB = {1, 2, 3, 4, 5, 6};

    vector<vector<int>> result = undoomDice(dieA, dieB);

    if (!result.empty()) {
        cout << "New Die A: ";
        for (int value : result[0]) {
            cout << value << " ";
        }
        cout << endl;

        cout << "New Die B: ";
        for (int value : result[1]) {
            cout << value << " ";
        }
        cout <<endl;
    } else {
        cout << "No valid transformation found." << endl;
    }

    return 0;
}
