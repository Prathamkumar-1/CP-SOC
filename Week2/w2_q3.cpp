#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1; 
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        ll rem = x - v[i].first;
        int l = i + 1, r = n - 1;

        while (l < r) {
            ll sum = v[l].first + v[r].first;
            if (sum == rem) {
                cout << v[i].second << " " << v[l].second << " " << v[r].second << "\n";
                return 0;
            }
            if (sum < rem) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
