#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll mod = 1e9 + 7;
    vector<ll> dp(x + 1, 0);
    dp[0] = 1; 
    for (ll j = 1; j <= x; j++) {
    for (ll i = 0; i < n; i++) {
        if (j - a[i] >= 0)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
}
    cout << dp[x] << endl;
    return 0;
}