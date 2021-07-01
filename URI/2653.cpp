#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    string jewel;
    set<string> jewels;
    while (cin >> jewel) {
        jewels.insert(jewel);
    }
    cout << jewels.size() << endl;
    return 0;
}
