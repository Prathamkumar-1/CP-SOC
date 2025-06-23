#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll MOD = 1e9 + 7;  
    vector<ll> dp(n+1, 0);
    dp[0] = 1; 
    for(ll i = 1; i <= n; i++){
                dp[i] = (dp[i-1]*2) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}