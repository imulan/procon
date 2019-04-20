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

const int MD = 2;
const ll hash_base[MD] = {1007,1021};
const ll hash_mod[MD] = {1000000009,1000000007};

int N;

const int SZ = 100010;
ll hs[MD][SZ], pw[MD][SZ];
char s[SZ];
char t[SZ];

void init(){
    N = strlen(s);
    rep(i,MD){
        rep(j,N+1){
            hs[i][j] = 0;
            pw[i][j] = 0;
        }

        hs[i][0] = 0;
        pw[i][0] = 1;
        rep(j,N){
            pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
            hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
        }
    }
}

// 1-index
ll hash_value(int l, int r, int i){
    return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
}

ll calc(int l, int r){
    return (hash_value(l-1,r,0)<<32)|hash_value(l-1,r,1);
}

vector<int> qidx[2000];

int main(){
    int q;
    scanf(" %s %d", t, &q);

    int n = strlen(t);

    vector<int> l(q),r(q);
    vector<int> sz(q);
    vector<ll> qval(q);
    rep(i,q){
        scanf(" %d %d %s", &l[i], &r[i], s);

        sz[i] = strlen(s);
        init();
        qval[i] = calc(1, sz[i]);
    }

    vector<int> usz(sz);
    sort(all(usz));
    usz.erase(unique(all(usz)), usz.end());
    int U = usz.size();

    rep(i,q){
        int idx = lower_bound(all(usz), sz[i]) - usz.begin();
        qidx[idx].pb(i);
    }

    vector<int> ans(q,0);
    strcpy(s,t);
    init();

    rep(i,U){
        if(usz[i] > n) break;
        unordered_map<ll,vector<int>> pos;
        rep(j,n+1-usz[i]){
            ll hval = calc(j+1, j+usz[i]);
            pos[hval].pb(j);
        }

        for(int j:qidx[i]){
            int L = l[j], R = r[j] - (sz[j]-1);
            if(L>R) continue;
            if(pos.count(qval[j])){
                ans[j] = lower_bound(all(pos[qval[j]]), R+1) - lower_bound(all(pos[qval[j]]), L);
            }
        }
    }

    rep(i,q) printf("%d\n", ans[i]);
    return 0;
}
