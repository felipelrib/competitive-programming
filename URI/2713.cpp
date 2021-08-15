#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<pair<double, double>> rooms;
vector<unordered_map<int, double>> dynamicMatrix;
int roomsAmount;
int mageDamage;

double getMinimumTime(int currentIndex, int manaAvailable) {
    if (currentIndex == -1) {
        return 0;
    }
    double minimumTime;
    if (dynamicMatrix[currentIndex].find(manaAvailable) != dynamicMatrix[currentIndex].end()) {
        minimumTime = dynamicMatrix[currentIndex][manaAvailable];
    } else {
        double timeSpentInThisRoomWithoutMagic = rooms[currentIndex].first / mageDamage;
        if (manaAvailable == 0) {
            minimumTime = timeSpentInThisRoomWithoutMagic + getMinimumTime(currentIndex - 1, manaAvailable);
        } else {
            double timeWithMagic = (rooms[currentIndex].first / (mageDamage + rooms[currentIndex].second)) + getMinimumTime(currentIndex - 1, manaAvailable - 1);
            double timeWithoutMagic = timeSpentInThisRoomWithoutMagic + getMinimumTime(currentIndex - 1, manaAvailable);
            minimumTime = max(timeWithMagic, timeWithoutMagic);
        }
        dynamicMatrix[currentIndex][manaAvailable] = minimumTime;
    }
    return minimumTime;
}

int main(){ _
    double monsterHP, damageIncrease;
    int mana;
    while (cin >> roomsAmount) {
        cin >> mana;
        cin >> mageDamage;
        rooms.clear();
        dynamicMatrix.clear();
        for (int j = 0; j < roomsAmount; j++) {
            cin >> monsterHP >> damageIncrease;
            // Make it negative so the algorithm will get the minimum.
            rooms.push_back(make_pair(-monsterHP, damageIncrease));
            unordered_map<int, double> map{};
            dynamicMatrix.push_back(map);
        }
        cout << fixed << setprecision(4) << getMinimumTime(roomsAmount - 1, mana) * -1.0 << endl;
    }
    return 0;
}
