#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll finish = 0;
    for(int i = 0;i<n;i++){
        finish += a[i].first;
        ans += a[i].second - finish;
    }
    cout << ans << endl;
    return 0;
}