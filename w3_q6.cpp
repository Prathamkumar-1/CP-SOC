#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i]; 
    for (int i = 0; i < n; ++i) 
        cin >> b[i]; 

    vector<int> dp(x + 1, 0); 
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= a[i]; --j) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }

    cout << dp[x] << endl;
    return 0;
}
