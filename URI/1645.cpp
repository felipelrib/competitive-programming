#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<int> sequence;
int sequenceSize;
int desiredSubsequenceSize;

ll getAmountOfIncreasingSubsequences() {
    ll matrix[sequenceSize][desiredSubsequenceSize];
    ll amountOfIncreasingSubsequences = 0;
    fill(&matrix[0][0], &matrix[0][0] + sizeof(matrix) / sizeof(ll), 0);

    for(int i = 0; i < sequenceSize; i++) {
        matrix[i][0] = 1;
    }

    for (int i = 1; i < desiredSubsequenceSize; i++) {
        for (int j = 1; j < sequenceSize; j++) {
            for (int k = i - 1; k < j; k++) {
                if (sequence[k] < sequence[j]) {
                    matrix[j][i] += matrix[k][i - 1];
                }
            }
        }
    }

    for (int i = 0; i < sequenceSize; i++) {
        amountOfIncreasingSubsequences += matrix[i][desiredSubsequenceSize - 1];
    }

    return amountOfIncreasingSubsequences;
}

int main(){ _
    int currentNumber;
    while (cin >> sequenceSize && sequenceSize != 0) {
        cin >> desiredSubsequenceSize;
        sequence.clear();
        for (int j = 0; j < sequenceSize; j++) {
            cin >> currentNumber;
            sequence.push_back(currentNumber);
        }
        cout << getAmountOfIncreasingSubsequences() << endl;
    }
    return 0;
}
