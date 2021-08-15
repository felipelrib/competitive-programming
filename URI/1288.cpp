#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<pair<int, int>> projectiles;
vector<unordered_map<int, int>> dynamicMatrix;
int projectilesAmount;

int getMaximumDamage(int currentIndex, int currentCapacity) {
    if (currentIndex == -1 || currentCapacity == 0) {
        return 0;
    }
    int maximumDamage;
    if (dynamicMatrix[currentIndex].find(currentCapacity) != dynamicMatrix[currentIndex].end()) {
        maximumDamage = dynamicMatrix[currentIndex][currentCapacity];
    } else {
        if (projectiles[currentIndex].second > currentCapacity) {
            maximumDamage = getMaximumDamage(currentIndex - 1, currentCapacity);
        } else {
            int damageWithCurrentProjectile = projectiles[currentIndex].first + getMaximumDamage(currentIndex - 1, currentCapacity - projectiles[currentIndex].second);
            int damageWithoutCurrentProjectile = getMaximumDamage(currentIndex - 1, currentCapacity);
            maximumDamage = max(damageWithCurrentProjectile, damageWithoutCurrentProjectile);
        }
        dynamicMatrix[currentIndex][currentCapacity] = maximumDamage;
    }
    return maximumDamage;
}

int main(){ _
    int testCases;
    int projectileDamage, projectileWeight;
    int cannonCapacity;
    int necessaryDamage;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin >> projectilesAmount;
        projectiles.clear();
        dynamicMatrix.clear();
        for (int j = 0; j < projectilesAmount; j++) {
            cin >> projectileDamage >> projectileWeight;
            projectiles.push_back(make_pair(projectileDamage, projectileWeight));
            unordered_map<int, int> map{};
            dynamicMatrix.push_back(map);
        }
        cin >> cannonCapacity;
        cin >> necessaryDamage;
        cout << (getMaximumDamage(projectilesAmount - 1, cannonCapacity) >= necessaryDamage ? "Missao completada com sucesso" : "Falha na missao") << endl;
    }
    return 0;
}
