#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n;
        ll c, d;
        cin >> n >> c >> d;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
         cin >> a[i];
        sort(a.rbegin(), a.rend()); 
        vector<ll> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + a[i - 1];
        if (a[0] * d < c) {
            cout << "Impossible\n";
            continue;
        }
        ll max = prefix[min(n, (int)d)];
        if (max >= c) {
            cout << "Infinity\n";
            continue;
        }
        ll left = 0, right = d, answer = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll length = mid + 1;
            ll full = d / length;
            ll remain = d % length;
            ll sum = prefix[min(n, (int)length)];
            ll total = full* sum + prefix[min(n, (int)remain)];

            if (total >= c) {
                answer = mid;      
                left = mid + 1;
            } else 
                right = mid - 1;   
        }
     if (answer == -1)
            cout << "Impossible\n";
        else
            cout << answer << "\n";}
    return 0;
}
