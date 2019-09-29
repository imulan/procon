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

const int N = 10000001;
int mind[N];
vector<int> pr;

void build_sieve(){
    mind[0] = mind[1] = 1;
    for(int i=2; i<N; ++i){
        if(mind[i] == 0){
            pr.push_back(i);
            mind[i] = i;
        }
        for (int j=0; j<int(pr.size()) && pr[j]<=mind[i] && i*pr[j]<N; ++j) mind[i*pr[j]] = pr[j];
    }
}

inline ll lcm(ll x, ll y){
    return x/__gcd(x,y)*y;
}

using pi = pair<int,int>;
pi cand[N];

pi d[255];
int D;
void dfs(int x, int val, int idx){
    if(x == D){
        if(cand[val].fi == -1) cand[val].fi = idx;
        else if (cand[val].se == -1) cand[val].se = idx;
        return;
    }

    int mul = 1;
    rep(i,d[x].se+1){
        dfs(x+1, val*mul, idx);
        mul *= d[x].fi;
    }
}

void ADD(int v, int idx){
    const int val = v;

    D = 0;
    while(v>1){
        if(D==0 || d[D-1].fi != mind[v]){
            d[D] = {mind[v],1};
            ++D;
        }
        else ++d[D-1].se;

        v /= mind[v];
    }

    dfs(0,1,idx);
}

int main(){
    build_sieve();

    int n;
    scanf(" %d", &n);

    vector<int> v(n);
    vector<pi> a(n);
    rep(i,n){
        scanf(" %d", &v[i]);
        a[i].fi = v[i];
        a[i].se = i;
    }
    sort(all(a));

    fill(cand,cand+N,pi(-1,-1));
    rep(i,n) ADD(a[i].fi, a[i].se);

    ll mn = LLONG_MAX;
    pi idx(-1,-1);
    for(int i=1; i<N; ++i)if(cand[i].se != -1){
        int x = cand[i].fi, y =cand[i].se;
        ll L = lcm(v[x], v[y]);
        if(L < mn){
            mn = L;
            idx = {x,y};
        }
    }

    if(idx.fi > idx.se) swap(idx.fi,idx.se);
    printf("%d %d\n", idx.fi+1, idx.se+1);
    return 0;
}
