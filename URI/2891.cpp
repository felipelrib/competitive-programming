#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

ll orientation(pair<int, int> point1, pair<int, int> point2, pair<int, int> point3) {
    ll xVector1 = point2.first - point1.first;
    ll yVector1 = point2.second - point1.second;
    ll xVector2 = point3.first - point2.first;
    ll yVector2 = point3.second - point2.second;
    return yVector1 * xVector2 - xVector1 * yVector2;
}

vector<pair<int, int>> convexHull(vector<pair<int, int>> points) {
    vector<pair<int, int>> sortedClockWisePoints;

    int leftmostIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (points[i].first < points[leftmostIndex].first) {
            leftmostIndex = i;
        }
    }

    int currentPointIndex = leftmostIndex;
    do {
        int nextPointIndex = (currentPointIndex + 1) % 4;
        sortedClockWisePoints.push_back(points[currentPointIndex]);

        for (int i = 0; i < 4; i++) {
            if (orientation(points[currentPointIndex], points[i], points[nextPointIndex]) > 0) {
                nextPointIndex = i;
            }
        }

        currentPointIndex = nextPointIndex;
    } while (currentPointIndex != leftmostIndex);

    return sortedClockWisePoints;
}

ll getArea(vector<pair<int, int>> points) {
    ll firstSum = 0;
    ll secondSum = 0;
    for (int i = 0; i < 4; i++) {
        firstSum += points[i].first * points[(i + 1) % 4].second;
        secondSum += points[i].second * points[(i + 1) % 4].first;
    }
    ll area = abs(firstSum - secondSum) / 2;
    return area;
}

int main(){ _
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    pair<int, int> points[5];
    vector<pair<int, int>> currentSet;
    ll highestArea;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 && (x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0 || x3 != 0 || y3 != 0 || x4 != 0 || y4 != 0 || x5 != 0 || y5 != 0)) {
        points[0] = make_pair(x1, y1);
        points[1] = make_pair(x2, y2);
        points[2] = make_pair(x3, y3);
        points[3] = make_pair(x4, y4);
        points[4] = make_pair(x5, y5);
        highestArea = 0;
        for (int i = 0; i < 5; i++) {
            currentSet.clear();
            for (int j = 0; j < 5; j++) {
                if (j != i) {
                    currentSet.push_back(points[j]);
                }
            }
            currentSet = convexHull(currentSet);
            if (currentSet.size() == 4) {
                ll area = getArea(currentSet);
                if (area > highestArea) {
                    highestArea = area;
                }
            }
        }
        cout << highestArea << endl;
    }
    return 0;
}
