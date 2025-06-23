#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<ll> s;
    ll ans = 0, l = 0;

    for(ll r = 0; r < n; r++) {
        while(s.find(a[r]) != s.end()) {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;
    return 0;
}
