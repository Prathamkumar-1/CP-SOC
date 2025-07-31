#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1; i <= n;) {
        ll q = n / i;
        ll j = n / q; 
        ll count = (j - i + 1) % MOD;
        ll sum_d = ((i + j) % MOD) * count % MOD * ((MOD + 1) / 2) % MOD;
        ans = (ans + sum_d * q % MOD) % MOD;
        i = j + 1;
    }

    cout << ans << endl;
    return 0;
}
