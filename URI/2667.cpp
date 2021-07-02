#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    int sum = 0;
    char digit;
    while (cin >> digit) {
        sum += (digit - '0');
    }
    cout << sum % 3 << endl;
    return 0;
}
