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

const ll mod = 1e9+7;

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

const int N = 100010;
ll pw[N];

int main(){
    pw[0] = 1;
    rep(i,N-1) pw[i+1] = (pw[i]*2)%mod;

    int n,m;
    while(scanf(" %d %d", &n, &m),n){
        UF uf(n);

        rep(i,m){
            int a,b;
            scanf(" %d %d", &a, &b);
            --a;
            --b;
            uf.unite(a,b);
        }

        int ct = 0;
        int add = 0;
        vector<bool> vis(n);

        rep(i,n){
            int v = uf.root(i);
            if(vis[v]) continue;

            int sz = uf.size(v);
            if(sz>1) add = 1;
            ++ct;
            vis[v] = true;
        }

        ll ans = pw[ct];
        (ans += add) %= mod;
        cout << ans << endl;
    }
    return 0;
}
