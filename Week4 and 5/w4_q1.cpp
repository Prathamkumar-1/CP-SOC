#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exp(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll mod = 1000000007;
        ll mod2 = 1000000006;  
        ll exponent = exp(b, c, mod2);  
        ll ans = exp(a, exponent, mod); 

        cout << ans << endl;
    }
    return 0;
}
