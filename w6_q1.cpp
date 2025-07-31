#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 0);
    stack<int> st;
    int maxlen = 0, count = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (!st.empty()) {
            int j = st.top(); st.pop();
            dp[i] = i - j + 1;
            if (j > 0) dp[i] += dp[j-1];
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                count = 1;
            } else if (dp[i] == maxlen) {
                count++;
            }
        }
    }

    if (maxlen == 0) cout << "0 1\n";
    else cout << maxlen << " " << count << '\n';

    return 0;
}
