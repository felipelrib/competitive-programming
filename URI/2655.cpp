
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f
#define MAX 1700000

/**
 * Implementação de Seg Tree do @brunomaletta
 */
ll seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = seg[2*i] | seg[2*i+1];
}

ll query(int a, int b) {
	ll ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret |= seg[a];
		if (b % 2 == 0) ret |= seg[b];
	}
	return ret;
}

void update(int p, ll x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = seg[2*p] | seg[2*p+1];
}

/**
 * Fim da implementação
 */

int main(){ _
    int coordinatesAmount, operationsAmount, monstersTypes;
    int currentMonster, currentOperation;
    int firstArgument, secondArgument;
    cin >> coordinatesAmount >> operationsAmount >> monstersTypes;
    n = coordinatesAmount;
    for (int i = 0; i < coordinatesAmount; i++) {
        cin >> currentMonster;
        ll monsterBitwise = 1LL << (currentMonster - 1);
        seg[n + i] = monsterBitwise;
    }
    build();
    for (int i = 0; i < operationsAmount; i++) {
        cin >> currentOperation >> firstArgument >> secondArgument;
        if (currentOperation == 1) {
            ll queryResponse = query(firstArgument - 1, secondArgument - 1);
            int differentMonstersAmount = 0;
            while (queryResponse > 0) {
                differentMonstersAmount += queryResponse % 2;
                queryResponse >>= 1;
            }
            cout << differentMonstersAmount << endl;
        } else {
            ll monsterBitwise = 1LL << (secondArgument - 1);
            update(firstArgument - 1, monsterBitwise);
        }
    }
    return 0;
}
