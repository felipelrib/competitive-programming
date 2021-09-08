#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

bool primes[100001];

int main(){ _
    fill(&primes[0], &primes[0] + sizeof(primes), true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < 100001; i++) {
        if (primes[i]) {
            for (int j = i * 2; j < 100001; j += i) {
                primes[j] = false;
            }
        }
    }
    int currentNumber;
    while (cin >> currentNumber) {
        if (!primes[currentNumber]) {
            cout << "Nada" << endl;
        } else {
            bool super = true;
            while (currentNumber > 0) {
                if (!primes[currentNumber % 10]) {
                    super = false;
                    break;
                }
                currentNumber /= 10;
            }
            cout << (super ? "Super" : "Primo") << endl;
        }
    }
    return 0;
}
