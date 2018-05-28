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

const int N = 100000;
vector<int> G[N];

int main(){
    int m,n;
    scanf(" %d %d", &m, &n);
    rep(i,m){
        int k;
        scanf(" %d", &k);
        while(k--){
            int x;
            scanf(" %d", &x);
            G[x-1].pb(i);
        }
    }

    UF uf(m);
    int ans = 0;
    rep(i,N){
        assert(G[i].size()<=2);
        if(!G[i].empty()){
            int a = G[i][0], b = G[i][1];
            // printf(" (%d %d)\n", a,b);
            if(!uf.same(a,b)){
                ++ans;
                uf.unite(a,b);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
