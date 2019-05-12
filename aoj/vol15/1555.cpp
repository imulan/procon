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

struct RollingHash{
    static const int MD = 2;
    static const vector<ll> hash_base, hash_mod;

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        rep(i,MD){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    // 1-index
    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    ll calc(int l, int r){
        ll ret = 0;
        rep(i,MD) ret |= (hash_value(l-1,r,i)<<(i*32));
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007};



using P = pair<string,int>;

int main(){
    int n;
    scanf(" %d", &n);

    vector<P> s(n);
    rep(i,n){
        char tt[100010];
        scanf(" %s", tt);
        s[i] = {string(tt), i};
    }

    sort(all(s));

    vector<int> f(n),sz(n);
    rep(i,n){
        f[s[i].se] = i;
        sz[i] = s[i].fi.size();
    }

    vector<RollingHash> h(n);
    rep(i,n) h[i] = RollingHash(s[i].fi);

    auto check = [&](int a, int b){
        if(sz[a] > sz[b]) return false;

        ll va = h[a].calc(1,sz[a]);
        ll vb = h[b].calc(1,sz[a]);
        return va == vb;
    };

    set<int> active;
    int Q;
    scanf(" %d", &Q);
    while(Q--){
        int k,id;
        scanf(" %d %d", &k, &id);
        --id;

        if(k == 1) active.insert(f[id]);
        else if(k == 2) active.erase(f[id]);
        else{
            int ans = -1;
            auto itr = active.lower_bound(f[id]);
            if(itr != active.end()){
                int idx = *itr;
                if(check(f[id], idx)) ans = s[idx].se+1;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
