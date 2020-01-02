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

void solve(){
    int n;
    cin >>n;

    vector<string> s(n);
    set<string> def, ss;
    rep(i,n){
        cin >>s[i];
        def.insert(s[i]);
    }

    int ans = 0;

    auto replace = [&](int x){
        rep(i,4)rep(j,10){
            if(s[x][i] == j+'0') continue;
            string t = s[x];
            t[i] = j+'0';
            if(!def.count(t) && !ss.count(t)){
                s[x] = t;
                return;
            }
        }
    };

    rep(i,n){
        if(ss.count(s[i])){
            ++ans;
            replace(i);
        }
        ss.insert(s[i]);
    }

    cout << ans << "\n";
    for(string t:s) cout << t << "\n";
}

int main(){
    int t;
    cin >>t;
    while(t--) solve();
    return 0;
}
