#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    ll ans = 0;
    ll l = 0, r = n-1;
    while(l<=r){
        if(p[l]+p[r] <= x){
            ans++;
            l++;
            r--;
        }else{
            ans++;
            r--;
        }
    }
    cout << ans;
    return 0;
}