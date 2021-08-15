#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f
#define MAX_DIFFERENCE 5

vector<int> presentPacks;
vector<unordered_map<int, int>> dynamicMatrix;
int totalPresents;
int presentPacksAmount;

bool hasMinimumDifferenceWithinConstraints(int currentIndex, int currentFirstSetSum, int currentSecondSetSum) {
    if (currentIndex == presentPacksAmount) {
        return true;
    }
    bool hasMinimumDifference = false;
    int currentDifference = abs(currentFirstSetSum - currentSecondSetSum);
    if (dynamicMatrix[currentIndex].find(currentDifference) != dynamicMatrix[currentIndex].end()) {
        hasMinimumDifference = dynamicMatrix[currentIndex][currentDifference];
    } else {
        if (abs(currentFirstSetSum + presentPacks[currentIndex] - currentSecondSetSum) <= MAX_DIFFERENCE) {
            hasMinimumDifference = hasMinimumDifferenceWithinConstraints(currentIndex + 1, currentFirstSetSum + presentPacks[currentIndex], currentSecondSetSum);
        }
        if (!hasMinimumDifference && abs(currentFirstSetSum - (currentSecondSetSum + presentPacks[currentIndex])) <= MAX_DIFFERENCE) {
            hasMinimumDifference = hasMinimumDifferenceWithinConstraints(currentIndex + 1, currentFirstSetSum, currentSecondSetSum + presentPacks[currentIndex]);
        }
        dynamicMatrix[currentIndex][currentDifference] = hasMinimumDifference;
    }
    return hasMinimumDifference;
}

int main(){ _
    int testCases;
    int currentPresentPack;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin >> presentPacksAmount;
        presentPacks.clear();
        dynamicMatrix.clear();
        totalPresents = 0;
        for (int j = 0; j < presentPacksAmount; j++) {
            cin >> currentPresentPack;
            totalPresents += currentPresentPack;
            presentPacks.push_back(currentPresentPack);
            unordered_map<int, int> map{};
            dynamicMatrix.push_back(map);
        }
        cout << (hasMinimumDifferenceWithinConstraints(0, 0, 0) ? "Feliz Natal!" : "Ho Ho Ho!") << endl;
    }
    return 0;
}
