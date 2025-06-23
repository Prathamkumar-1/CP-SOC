#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int total = (n * (n + 1)) / 2;
    long long int sum = 0;
    for (long long int i = 1; i <= n - 1; i++) {
        long long int x;
        cin >> x;
        sum += x;
    }
    cout << total - sum << endl;
    return 0;
}