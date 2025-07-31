#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll total(vector<ll>a, ll time) {
    ll ans = 0;
    for (ll i = 0; i < (ll)(a.size()); i++) {
        ans += time/a[i];
         if (ans > 1e18) break; 
    }
    return ans;
}
int main(){
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n);
    ll slowest = -1;
    for(ll i = 0; i < n; i++){
        cin >>a[i];
        slowest = max(slowest, a[i]);
    }
    ll left = 1, right = slowest * t;
    ll ans = right;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (total(a, mid) >= t) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
    }
    }
    cout << ans << endl;
    return 0;
}