#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    string input;
    long inteira, decimal;
    int notas[] ={100, 50, 20, 10, 5, 2};
    int notasUsadas[6];
    int moedas[] = {100, 50, 25, 10, 5, 1};
    int moedasUsadas[6];
    getline(cin, input, '.');
    inteira = stoi(input);
    getline(cin, input);
    decimal = stoi(input);
    for (int i = 0; i < 6; i++) {
        notasUsadas[i] = inteira / notas[i];
        inteira %= notas[i];
        moedasUsadas[i] = decimal / moedas[i];
        decimal %= moedas[i];
    }
    moedasUsadas[0] = inteira;
    cout << "NOTAS:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << notasUsadas[i] << " nota(s) de R$ " << setprecision(2) << fixed << float(notas[i]) << endl;
    }
    cout << "MOEDAS:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << moedasUsadas[i] << " moeda(s) de R$ " << setprecision(2) << fixed << float(moedas[i]) / 100 << endl;
    }
    return 0;
}
