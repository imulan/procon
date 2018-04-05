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

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

using pi = pair<int,int>;

const int N = 100010;

vector<int> G[N];
int idx[N];
ll max_s[N];
ll s[N];

vector<int> Q[N];
vector<int> U[N];

int main(){
    int n;
    scanf(" %d", &n);

    vector<pi> v(n);

    rep(i,n){
        int c;
        scanf(" %d", &c);
        v[i] = {c,i};
    }
    sort(all(v));

    vector<int> c(n), f(n);
    rep(i,n){
        c[i] = v[i].fi;
        f[v[i].se] = i;
    }
    rep(i,n) Q[c[i]].pb(i);

    int m;
    scanf(" %d", &m);
    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        a = f[a-1];
        b = f[b-1];

        G[a].pb(b);
        G[b].pb(a);
        U[c[a]].pb(b);
        U[c[b]].pb(a);
    }

    rep(i,N){
        sort(all(G[i]));
        sort(all(U[i]));
        U[i].erase(unique(all(U[i])), U[i].end());
    }

    UF uf(n);
    vector<ll> umx(n);

    rep(i,N){
        // printf(" --- i = %d --- \n", i);

        // calc salary
        for(int j:Q[i]){
            s[j] = max_s[j];
            for(int e:G[j]){
                s[j] = max(s[j], max_s[e]);
            }
            ++s[j];
            // printf(" s[%d] = %lld\n", j,s[j]);
        }

        // check salary for same contibution
        for(int j:Q[i]){
            int tt = idx[j];
            int root = j;
            while(tt<G[j].size() && c[G[j][tt]]==i){
                uf.unite(root, G[j][tt]);
                ++tt;
            }
        }

        for(int j:U[i]){
            int tt = idx[j];
            assert(c[G[j][tt]]==i);
            int root = G[j][tt];
            ++tt;
            while(tt<G[j].size() && c[G[j][tt]]==i){
                uf.unite(root, G[j][tt]);
                ++tt;
            }
        }

        for(int j:Q[i]) umx[uf.root(j)] = max(umx[uf.root(j)], s[j]);
        for(int j:Q[i]) s[j] = umx[uf.root(j)];

        // update
        for(int j:U[i]){
            while(idx[j]<G[j].size() && c[G[j][idx[j]]]<=i){
                max_s[j] = max(max_s[j], s[G[j][idx[j]]]);
                ++idx[j];
            }
            // printf(" UPD %d : %lld\n", j,max_s[j]);
        }
    }

    ll ans = 0;
    rep(i,n) ans += s[i];
    printf("%lld\n", ans);
    return 0;
}
