#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll median = a[n / 2];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += abs(a[i] - median);
    }
    cout << ans << endl;
    return 0;
}