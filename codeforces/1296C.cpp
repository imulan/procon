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

using pi = pair<int,int>;

void solve(){
    int n;
    string s;
    cin >>n >>s;

    vector<pi> pre(n);
    map<pi,queue<int>> que;
    pi t(0,0);
    rep(i,n){
        if(s[i]=='L') --t.fi;
        else if(s[i]=='R') ++t.fi;
        else if(s[i]=='U') ++t.se;
        else --t.se;

        pre[i] = t;
        que[pre[i]].push(i);
    }

    int w = n+1;
    pi ans = {-1,-1};
    t = {0,0};
    rep(i,n){

        if(!que[t].empty()){
            int v = que[t].front();
            int L = v-i+1;
            if(L < w){
                w = L;
                ans = {i,v};
            }
        }

        que[pre[i]].pop();

        if(s[i]=='L') --t.fi;
        else if(s[i]=='R') ++t.fi;
        else if(s[i]=='U') ++t.se;
        else --t.se;
    }

    if(w>n) cout << -1 << "\n";
    else cout << ans.fi+1 << " " << ans.se+1 << "\n";
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int t;
    cin >>t;
    while(t--) solve();
    return 0;
}
