#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

bool solve(){
    string s,t;
    cin >>s >>t;

    int n = s.size();
    int l = n, r = -1;
    rep(i,n){
        if(s[i]!=t[i]){
            l = min(l,i);
            r = max(r,i);
        }
    }

    if(l>r) return true;

    reverse(s.begin()+l, s.begin()+r+1);
    return s==t;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}