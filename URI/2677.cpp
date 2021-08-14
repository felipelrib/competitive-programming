#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<bool> sequence;

int getMaxEvenNumbersAmount() {
    int sequenceSize = sequence.size();
    pair<int, int> matrix[sequenceSize][sequenceSize];
    for (int i = 0; i < sequenceSize; i++) {
        for (int j = 0; j < sequenceSize - i; j++) {
            if (i == 0) {
                matrix[j][j] = make_pair(sequence[j], 0);
            } else {
                int leftSum = sequence[j] ? 1 : 0;
                leftSum += matrix[j + 1][j + i].second;
                int rightSum = sequence[j + i] ? 1 : 0;
                rightSum += matrix[j][j + i - 1].second;
                if (leftSum > rightSum) {
                    matrix[j][i + j] = make_pair(leftSum, matrix[j + 1][j + i].first);
                } else {
                    matrix[j][i + j] = make_pair(rightSum, matrix[j][j + i - 1].first);
                }
            }
        }
    }
    return matrix[0][sequenceSize - 1].first;
}

int main(){ _
    int amountOfEach;
    int currentNumber;
    int firstPlayerEvenNumbersAmount;
    bool isFirstPlayerTurn;
    while (cin >> amountOfEach && amountOfEach != 0) {
        sequence.clear();
        for (int i = 0; i < 2 * amountOfEach; i++) {
            cin >> currentNumber;
            sequence.push_back(currentNumber % 2 == 0);
        }
        cout << getMaxEvenNumbersAmount() << endl;
    }
}
