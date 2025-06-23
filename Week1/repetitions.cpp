#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll max = 0;
    ll count = 0;
    char s;
    cin >> s;
    char c;
    while(cin >> c){
        if(c == s){
            count++;
        }else{
            if(count > max){
                max = count;
            }
            count = 0;
        }
        s = c;
    }
    if(count > max){
        max = count;
    }
    cout<< max+1;  // The +1 is to include the first character in the count
    return 0;
}