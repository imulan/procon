#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const string hand = "RPS";

string solve(){
    int n;
    cin >>n;

    int h[3];
    rep(i,3) cin >>h[i];

    string s;
    cin >>s;

    string ans(n,'?');
    int win = 0;
    rep(i,n){
        int e;
        if(s[i]=='R') e = 0;
        else if(s[i]=='P') e = 1;
        else e = 2;

        int idx = (e+1)%3;
        if(h[idx]<=0) continue;

        ans[i] = hand[idx];
        --h[idx];
        ++win;
    }

    if(win < (n+1)/2) return "NO";

    rep(i,3){
        rep(j,n){
            if(ans[j]=='?' && h[i]>0){
                --h[i];
                ans[j] = hand[i];
            }
        }
    }

    return "YES\n"+ans;
}

int main(){
    int t;
    cin >>t;
    while(t--) cout << solve() << "\n";
    return 0;
}
