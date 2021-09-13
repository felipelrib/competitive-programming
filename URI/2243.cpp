#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    vector<int> wall;
    vector <int> fromLeft, fromRight;
    int wallLength;
    int columnSize, triangleSize, maxSize = 0;
    int lastSize;
    cin >> wallLength;
    for (int i = 0, lastSize = 0; i < wallLength; i++) {
        cin >> columnSize;
        wall.push_back(columnSize);
    }
    for (int i = 0, lastSize = 0; i < wallLength; i++) {
        triangleSize = min(lastSize + 1, wall[i]);
        lastSize = triangleSize;
        fromLeft.push_back(triangleSize);
    }
    for (int i = wallLength - 1, lastSize = 0; i >= 0; i--) {
        triangleSize = min(lastSize + 1, wall[i]);
        lastSize = triangleSize;
        fromRight.insert(fromRight.begin(), triangleSize);
    }

    for (int i = 0; i < wallLength; i++) {
        maxSize = max(maxSize, min(fromLeft[i], fromRight[i]));
    }

    cout << maxSize << endl;
    return 0;
}
