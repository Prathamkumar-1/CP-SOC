#include <bits/stdc++.h>
using namespace std;

    const int MAXN = 10000000;
int main() 
{
    static int sum[MAXN + 1];
    static int ans[MAXN + 1];     
    memset(sum, 0, sizeof(sum));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = i; j <= MAXN; j += i) {
            sum[j] += i;
        }
    }
    for (int n = 1; n <= MAXN; ++n) {
        int s = sum[n];
        if (s <= MAXN) {
            if (ans[s] == 0 || n < ans[s]) {
                ans[s] = n;
        }
    }
    }
    int t; cin >> t;
    while (t--) {
        int c; cin >> c;
        if (c > MAXN || ans[c] == 0) cout << -1 << "\n";
        else cout << ans[c] << "\n";
    }
    return 0;
}
