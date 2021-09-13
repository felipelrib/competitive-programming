#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll unsigned long long

#define INF 0x3f3f3f3f

vector<vector<ll>> exponential(vector<vector<ll>> matrix, ll exponent) {
    if (exponent == 0) {
        vector<vector<ll>> identity = {{1, 0}, {0, 1}};
        return identity;
    } else {
        vector<vector<ll>> calculatedMatrix = exponential(matrix, floor(exponent / 2));
        calculatedMatrix = {{((calculatedMatrix[0][0] * calculatedMatrix[0][0]) % 1000000 + (calculatedMatrix[0][1] * calculatedMatrix[1][0]) % 1000000) % 1000000, ((calculatedMatrix[0][0] * calculatedMatrix[0][1]) % 1000000 + (calculatedMatrix[0][1] * calculatedMatrix[1][1]) % 1000000) % 1000000},
                           {((calculatedMatrix[1][0] * calculatedMatrix[0][0]) % 1000000 + (calculatedMatrix[1][1] * calculatedMatrix[1][0]) % 1000000) % 1000000, ((calculatedMatrix[1][0] * calculatedMatrix[0][1]) % 1000000 + (calculatedMatrix[1][1] * calculatedMatrix[1][1]) % 1000000) % 1000000}};
        if (exponent % 2 == 1) {
            calculatedMatrix = {{((calculatedMatrix[0][0] * matrix[0][0]) % 1000000 + (calculatedMatrix[0][1] * matrix[1][0]) % 1000000) % 1000000, ((calculatedMatrix[0][0] * matrix[0][1]) % 1000000 + (calculatedMatrix[0][1] * matrix[1][1]) % 1000000) % 1000000},
                               {((calculatedMatrix[1][0] * matrix[0][0]) % 1000000 + (calculatedMatrix[1][1] * matrix[1][0]) % 1000000) % 1000000, ((calculatedMatrix[1][0] * matrix[0][1]) % 1000000 + (calculatedMatrix[1][1] * matrix[1][1]) % 1000000) % 1000000}};
        }
        return calculatedMatrix;
    }
}

int main(){ _
    ll maximumLength, microbusAvailableAmount, busAvailableAmount;
    while (cin >> maximumLength) {
        cin >> microbusAvailableAmount >> busAvailableAmount;
        vector<vector<ll>> matrix = {{0, busAvailableAmount % 1000000}, {1, microbusAvailableAmount % 1000000}};
        ll firstRecurrenceValue = 1;
        ll secondRecurrenceValue = microbusAvailableAmount % 1000000;

        maximumLength /= 5;
        matrix = exponential(matrix, maximumLength - 1);
        ll result = (firstRecurrenceValue * matrix[0][1]) % 1000000 + (secondRecurrenceValue * matrix[1][1]) % 1000000;
        cout << setfill('0') << setw(6) << result % 1000000 << endl;
    }
    return 0;
}
