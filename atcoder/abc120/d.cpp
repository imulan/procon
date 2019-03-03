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
    ll size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> a(m),b(m);
    rep(i,m){
        cin >>a[i] >>b[i];
        --a[i];
        --b[i];
    }

    UF uf(n);
    vector<ll> ans(m);
    ll now = (ll)n*(n-1)/2;
    for(int i=m-1; i>=0; --i){
        ans[i] = now;
        if(!uf.same(a[i],b[i])){
            ll sub = uf.size(a[i])*uf.size(b[i]);
            uf.unite(a[i],b[i]);
            now -= sub;
        }
    }

    rep(i,m) cout << ans[i] << "\n";
    return 0;
}
