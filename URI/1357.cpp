#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

map<int, string> upperFromNumber {
    {1, "*."},
    {2, "*."},
    {3, "**"},
    {4, "**"},
    {5, "*."},
    {6, "**"},
    {7, "**"},
    {8, "*."},
    {9, ".*"},
    {0, ".*"}
};
map<int, string> middleFromNumber {
    {1, ".."},
    {2, "*."},
    {3, ".."},
    {4, ".*"},
    {5, ".*"},
    {6, "*."},
    {7, "**"},
    {8, "**"},
    {9, "*."},
    {0, "**"}
};

map<string, vector<int>> upperFromBraille {
    {"*.", {1, 2, 5, 8}},
    {"**", {3, 4, 6, 7}},
    {".*", {9, 0}}
};

map<string, vector<int>> middleFromBraille {
    {"..", {1, 3}},
    {"*.", {2, 6, 9}},
    {".*", {4, 5}},
    {"**", {7, 8, 0}}
};
int main(){ _
    string inputString;
    char inputChar;
    vector<int> insertedDigits;
    vector<string> insertedUpperBraille;
    vector<string> insertedMiddleBraille;

    int digits;
    char identifier;

    cin >> digits;
    while (digits != 0) {
        cin >> identifier;
        if (identifier == 'S') {
            for (int i = 0; i < digits; i++) {
                cin >> inputChar;
                insertedDigits.push_back(inputChar - '0');
            }
            bool isFirst = true;
            for (int digit : insertedDigits) {
                auto it = upperFromNumber.find(digit);
                if (isFirst) {
                    isFirst = false;
                    cout << it->second;
                } else {
                    cout << ' ' << it->second;
                }
            }
            cout << endl;
            isFirst = true;
            for (int digit : insertedDigits) {
                auto it = middleFromNumber.find(digit);
                if (isFirst) {
                    isFirst = false;
                    cout << it->second;
                } else {
                    cout << ' ' << it->second;
                }
            }
            cout << endl;
            isFirst = true;
            for (int digit : insertedDigits) {
                if (isFirst) {
                    isFirst = false;
                    cout << "..";
                } else {
                    cout << ' ' << "..";
                }
            }
            cout << endl;
            insertedDigits.clear();
        } else {
            for (int i = 0; i < digits; i++) {
                cin >> inputString;
                insertedUpperBraille.push_back(inputString);
            }
            for (int i = 0; i < digits; i++) {
                cin >> inputString;
                insertedMiddleBraille.push_back(inputString);
            }
            for (int i = 0; i < digits; i++) {
                cin >> inputString;
            }
            for (int i = 0; i < digits; i++) {
                string currentUpper = insertedUpperBraille[i];
                string currentMiddle = insertedMiddleBraille[i];
                auto it = upperFromBraille.find(currentUpper);
                vector<int> possibleNumbers = it->second;
                it = middleFromBraille.find(currentMiddle);
                vector<int> middlePossibilities = it->second;
                for (int number : possibleNumbers) {
                    if (find(middlePossibilities.begin(), middlePossibilities.end(), number) != middlePossibilities.end()) {
                        cout << number;
                        break;
                    }
                }
            }
            cout << endl;
            insertedUpperBraille.clear();
            insertedMiddleBraille.clear();
        }
        cin >> digits;
    }
    return 0;
}
