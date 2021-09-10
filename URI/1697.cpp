#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f
// (10^6 + 1)th prime + 2 to give luck
#define MAX 15485870
#define MAX_PRIME_AMOUNT 1000001

bool primesSieve[MAX];
int firstPrimeDivisor[MAX];
vector<int> primeNumbers;

int main(){ _
    fill(&primesSieve[0], &primesSieve[0] + sizeof(primesSieve), true);
    primesSieve[0] = false;
    primesSieve[1] = false;
    for (ll i = 2; i < MAX; i++) {
        if (primesSieve[i]) {
            primeNumbers.push_back(i);
            firstPrimeDivisor[i] = i;
            if (primeNumbers.size() >= MAX_PRIME_AMOUNT) {
                break;
            }
        }
        for (ll j = 0; j < primeNumbers.size(); j++) {
            ll currentNumber = i * primeNumbers[j];
            if (currentNumber >= MAX || primeNumbers[j] > firstPrimeDivisor[i]) {
                break;
            }
            primesSieve[currentNumber] = false;
            firstPrimeDivisor[currentNumber] = i;
        }
    }
    primeNumbers.insert(primeNumbers.begin(), 1);
    int testCasesAmount;
    int listSize;
    int listElement;
    unordered_map<int, bool> listHasElement;
    cin >> testCasesAmount;
    for (int i = 0; i < testCasesAmount; i++) {
        listHasElement.clear();
        cin >> listSize;
        for (int j = 0; j < listSize; j++) {
            cin >> listElement;
            listHasElement[listElement] = true;
        }
        for (int j = 0; j < MAX_PRIME_AMOUNT; j++) {
            if (listHasElement.find(primeNumbers[j]) == listHasElement.end()) {
                cout << primeNumbers[j] - 1 << endl;
                break;
            }
        }
    }
    return 0;
}
