#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 100000;
vector<int> G[N];

using pl = pair<ll,ll>;

ll base[2] = {101119, 101141};
ll mod[2] = {1000000007,1000000021};
pl h[N];
void dfs(int v, int p){
    pl ret(0,0);
    for(int c:G[v])if(c!=p){
        dfs(c, v);
        (ret.fi += h[c].fi) %= mod[0];
        (ret.se += h[c].se) %= mod[1];
    }

    (ret.fi *= base[0]) %= mod[0];
    (ret.se *= base[1]) %= mod[1];

    (ret.fi += 1) %= mod[0];
    (ret.se += 1) %= mod[1];

    h[v] = ret;
}

int main(){
    int n;
    cin >>n;
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(0,-1);

    map<pl,ll> ct;
    rep(i,n) ++ct[h[i]];

    ll ans = 0;
    for(const auto &p:ct){
        ll x = p.se;
        ans += x*(x-1)/2;
    }
    cout << ans << endl;
    return 0;
}
