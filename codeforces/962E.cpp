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

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    cin >>n;

    vector<ll> a[2],p;
    rep(i,n){
        int x;
        char c;
        cin >>x >>c;

        if(c=='R') a[0].pb(x);
        else if(c=='B') a[1].pb(x);
        else p.pb(x);
    }

    if(p.empty()){
        ll ans = 0;
        for(auto &v:{a[0],a[1]}){
            if(v.empty()) continue;

            ll mn = INF, mx = -INF;
            for(ll i:v){
                mn = min(mn, i);
                mx = max(mx, i);
            }
            ans += mx-mn;
        }
        cout << ans << "\n";
        return 0;
    }

    ll ans = 0;
    int sz[2];
    rep(i,2) sz[i] = a[i].size();
    int P = p.size();

    int idx[2]={};
    // 左
    rep(i,2){
        if(!a[i].empty() && a[i][0] < p[0]){
            ans += p[0]-a[i][0];
            while(idx[i]<sz[i] && a[i][idx[i]]<p[0]) ++idx[i];
        }
    }

    // 間
    rep(pidx,P-1){
        ll L = p[pidx], R = p[pidx+1];
        ll W = R-L;

        ll g[2] = {};
        rep(i,2){
            vector<ll> v;
            v.pb(L);
            while(idx[i]<sz[i] && a[i][idx[i]]<R) v.pb(a[i][idx[i]++]);
            v.pb(R);

            int V = v.size();
            rep(j,V-1) g[i] = max(g[i], v[j+1]-v[j]);
        }

        ans += min(2*W, 3*W-g[0]-g[1]);
    }

    // 右
    rep(i,2){
        if(!a[i].empty() && p[P-1] < a[i][sz[i]-1]) ans += a[i][sz[i]-1] - p[P-1];
    }

    cout << ans << "\n";
    return 0;
}
