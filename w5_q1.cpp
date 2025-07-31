#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll total = 1 << n; 

    for (ll i = 0; i < total; i++) {
        ll gray = i ^ (i >> 1);
        for (ll j = n - 1; j >= 0; j--) {
            cout << ((gray >> j) & 1);
        }
        cout << '\n';
    }
    return 0;
}
