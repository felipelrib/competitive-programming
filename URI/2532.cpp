#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<pair<int, int>> spells;

int spellsAmount;
int monsterHP;

int getMinManaAmount(int totalDamage) {
    int minMana[spellsAmount + 1][monsterHP + 1];
    for (int i = 0; i < monsterHP + 1; i++) {
        minMana[0][i] = INF;
    }
    for (int i = 0; i < spellsAmount + 1; i++) {
        minMana[i][0] = 0;
    }

    for (int i = 1; i < spellsAmount + 1; i++) {
        for (int j = 1; j < monsterHP + 1; j++) {
            int manaWithSpell = (j - spells[i - 1].first >= 0 ? minMana[i - 1][j - spells[i - 1].first] : 0) + spells[i - 1].second;
            int manaWithoutSpell = minMana[i - 1][j];
            minMana[i][j] = min(manaWithSpell, manaWithoutSpell);
        }
    }
    return minMana[spellsAmount][monsterHP];
}

int main(){ _
    int damage, manaAmount;
    int totalDamage;
    while (cin >> spellsAmount) {
        cin >> monsterHP;
        spells.clear();
        totalDamage = 0;
        for (int i = 0; i < spellsAmount; i++) {
            cin >> damage >> manaAmount;
            spells.push_back(make_pair(damage, manaAmount));
            totalDamage += damage;
        }
        if (totalDamage < monsterHP) {
            cout << -1 << endl;
        } else {
            cout << getMinManaAmount(totalDamage) << endl;
        }
    }
    return 0;
}
