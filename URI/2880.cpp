#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    string message, crib;
    int cribLength, possibleCribAmount = 0;
    cin >> message >> crib;
    cribLength = crib.length();
    for (int i = 0, lengthDifference = message.length() - cribLength; i <= lengthDifference; i++) {
        bool validCrib = true;
        for (int j = 0; j < cribLength; j++) {
            if (crib[j] == message[i + j]) {
                validCrib = false;
                break;
            }
        }
        if (validCrib) {
            possibleCribAmount++;
        }
    }
    cout << possibleCribAmount << endl;
    return 0;
}
