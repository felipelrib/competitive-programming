#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f
#define MAX 10000010

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
    int A, B;
    cin >> A >> B;
    if (A == B) {
        cout << "?" << endl;
    } else {
        int primesAmount = 0;
        int difference = abs(A - B);
        int min = A < B ? A : B;
        int max = A > B ? A : B;
        for (int i = 0; i < primeNumbers.size(); i++) {
            if (primeNumbers[i] >= min) {
                if (primeNumbers[i] > max) {
                    break;
                }
                primesAmount++;
            }
        }
        if (primesAmount == 0) {
            cout << "Bob" << endl;
        } else {
            bool isOdd = true;
            int n = primesAmount + difference - 1;
            // Lucas' Theorem
            while (n > 0 && difference > 0) {
                if (difference % 2 > n % 2) {
                    isOdd = false;
                    break;
                }
                n >>= 1;
                difference >>= 1;
            }
            cout << (isOdd ? "Alice" : "Bob") << endl;
        }
    }
    return 0;
}
