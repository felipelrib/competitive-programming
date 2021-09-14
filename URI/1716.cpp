#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll unsigned long long

#define INF 0x3f3f3f3f

ll x, y;

void extendedEuclidean(ll a, ll b) {
    if (a == 0) {
        x = 0;
        y = 1;
        return;
    }

    extendedEuclidean(b % a, a);

    ll previousX = x;
    x = y - ((b / a) * x);
    y = previousX;
}

ll exponentiation(ll base, ll exponent, ll modulo) {
    if (exponent == 0) {
        return 1LL;
    } else if (exponent == 1) {
        return base;
    } else if (exponent % 2 == 0) {
        return exponentiation(((base % modulo) * (base % modulo)) % modulo, exponent / 2, modulo) % modulo;
    } else {
        return base * exponentiation(((base % modulo) * (base % modulo)) % modulo, (exponent - 1) / 2, modulo) % modulo;
    }
}

int main(){ _
    ll n, e, c;
    ll p, q;
    ll phi, d;

    cin >> n >> e >> c;

    if (n % 2 == 0) {
        p = 2;
        q = n / 2;
    }
    for (ll i = 3; i * i < n; i+= 2) {
        if (n % i == 0) {
            p = i;
            q = n / i;
        }
    }

    phi = (p - 1) * (q - 1);
    extendedEuclidean(phi, e);
    d = (y + phi) % phi;
    cout << exponentiation(c % n, d, n) << endl;
    return 0;
}
