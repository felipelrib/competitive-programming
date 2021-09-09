#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f
#define MAX 2000010

bool primes[MAX];
int dividers[MAX];
int hiperprimesAmount[MAX];

int main(){ _
    fill(&primes[0], &primes[0] + sizeof(primes), true);
    fill_n(&dividers[0], MAX, 1);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (primes[i]) {
            dividers[i]++;
            for (int j = i * 2; j < MAX; j += i) {
                int currentDividers = 1;
                int currentRemainder = j;
                primes[j] = false;
                while (currentRemainder % i == 0) {
                    currentDividers++;
                    currentRemainder /= i;
                }
                // Multiplies the current dividers amount by the current prime power.
                dividers[j] *= currentDividers;
            }
        }
    }
    hiperprimesAmount[0] = 0;
    hiperprimesAmount[1] = 0;
    for (int i = 2; i < MAX; i++) {
        hiperprimesAmount[i] = hiperprimesAmount[i - 1] + (primes[dividers[i]] ? 1 : 0);
    }
    int currentNumber;
    while (cin >> currentNumber) {
        cout << hiperprimesAmount[currentNumber] << endl;
    }
    return 0;
}
