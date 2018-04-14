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

using vl = vector<ll>;

const vl base{1009,1021};
const ll MOD = 1000000009;
// const vl mod{1000000009,1000000007};

// 2次元ハッシュ
// sの各P*Q部分のハッシュを計算
vector<vl> calc_hash(const vector<string> &s, int P, int Q){
    int n = s.size(), m = s[0].size();

    vector<vector<ll>> tmp(n,vl(m)), hash(n,vl(m));

    ll t0 = 1;
    rep(j,Q) (t0 *= base[0]) %= MOD;

    // 行方向
    rep(i,n){
        ll e = 0;
        rep(j,Q) e = (e*base[0] + s[i][j]) % MOD;

        for(int j=0; j+Q<=m; ++j){
            tmp[i][j] = e;
            if(j+Q < m) e = (e*base[0] - (t0*s[i][j])%MOD + MOD + s[i][j+Q]) % MOD;
        }
    }

    ll t1 = 1;
    rep(i,P) (t1 *= base[1]) %= MOD;

    for(int j=0; j+Q<=m; ++j){
        ll e = 0;
        rep(i,P) e = (e*base[1] + tmp[i][j]) % MOD;

        for(int i=0; i+P<=n; ++i){
            hash[i][j] = e;
            if(i+P < n) e = (e*base[1] - (t1*tmp[i][j])%MOD + MOD + tmp[i+P][j]) % MOD;
        }
    }

    return hash;
}

pair<int,int> solve(){
    int n,m;
    cin >>n >>m;

    vector<string> s(n), t(m);
    rep(i,n) cin >>s[i];
    rep(i,m) cin >>t[i];

    vector<vector<ll>> hs = calc_hash(s,m,m), ht = calc_hash(t,m,m);

    // map sのi行目から と map tのj列目から
    rep(i,n-m+1)rep(j,n-m+1){
        if(hs[i][0] == ht[0][j]) return{i+1, j+1};
    }
    assert(false);
}

int main(){
    pair<int,int> ans = solve();
    cout << ans.fi << " " << ans.se << endl;
    return 0;
}
