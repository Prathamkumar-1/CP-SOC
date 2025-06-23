#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a;
    cin >> n >> a;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    unordered_map<ll, int> hashmap;
    for(int i=0;i<n;i++){
         if(v[i] == 1 && a == 1) {
              cout << "IMPOSSIBLE" << endl;
              return 0;
         }
         if(v[i] > a) continue;
       ll complement = a - v[i];
       if(hashmap.count(complement)) {
           cout << hashmap[complement] + 1 << " " << i + 1 << endl;
           return 0;
       }
        hashmap[v[i]] = i;
            }
cout << "IMPOSSIBLE" << endl;
return 0;
}