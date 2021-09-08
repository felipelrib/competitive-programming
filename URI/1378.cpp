#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    int pointsAmount;
    int x, y;
    vector<pair<int, int>> points;
    ll distances[1001][1001];
    int trianglesAmount;
    while (cin >> pointsAmount && pointsAmount != 0) {
        points.clear();
        trianglesAmount = 0;
        for (int i = 0; i < pointsAmount; i++) {
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }
        for (int i = 0; i < pointsAmount; i++) {
            for (int j = 0; j < pointsAmount; j++) {
                distances[i][j] = pow(points[i].first - points[j].first, 2.0) + pow(points[i].second - points[j].second, 2.0);
            }
            sort(distances[i], distances[i] + pointsAmount);
            int pointsWithSameDistance = 1;
            ll currentDistance = distances[i][0];
            for (int j = 1; j < pointsAmount; j++, pointsWithSameDistance++) {
                if (distances[i][j] != currentDistance) {
                    // Sum with the combination of all points with the same distance.
                    trianglesAmount += (pointsWithSameDistance * (pointsWithSameDistance - 1)) / 2;
                    pointsWithSameDistance = 0;
                    currentDistance = distances[i][j];
                }
            }
            if (pointsWithSameDistance > 1) {
                trianglesAmount += (pointsWithSameDistance * (pointsWithSameDistance - 1)) / 2;
            }
        }
        cout << trianglesAmount << endl;
    }
    return 0;
}
