#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int cv(char c){
    if(isdigit(c)) return c-'0';
    if('A'<=c && c<='Z') return c-'A'+10;
    return c-'a'+36;
}

ll READ(){
    ll p;
    string s;
    cin >>p >>s;

    ll ret = 0;
    rep(i,s.size()){
        ret = p*ret + cv(s[i]);
    }
    return ret;
}

int main(){
    int n;
    cin >>n;

    vector<ll> x(n);
    rep(i,n) x[i] = READ();

    // rep(i,n) printf(" %lld\n", x[i]);
    ll res = 0;
    rep(i,n){
        res ^= __builtin_popcount(x[i]);
    }

    string ans = "lose";
    if(res != 0) ans = "win";
    cout << ans << endl;
    return 0;
}
