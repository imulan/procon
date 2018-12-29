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

vector<int> f(int x){
    vector<int> ret;
    int t = x;
    for(int i=2; i*i<=x; ++i){
        if(t%i==0){
            ret.pb(i);
            while(t%i==0) t/=i;
        }
    }
    if(t>1) ret.pb(t);
    return ret;
}

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    map<int,vector<int>> m;
    rep(i,n){
        vector<int> d = f(a[i]);
        for(int j:d) m[j].pb(i);
    }

    UF uf(n);
    for(const auto &p:m){
        int k = p.fi;
        vector<int> v = p.se;
        int V = v.size();
        rep(i,V) uf.unite(v[0],v[i]);
    }

    vector<int> sa(a);
    sort(all(sa));
    map<int,int> pos;
    for(int i=n-1; i>=0; --i) pos[sa[i]] = i;

    int ans = 1;
    rep(i,n){
        int v = a[i];
        int p = pos[v];
        if(!uf.same(i,p)){
            ans = 0;
            break;
        }
        ++pos[v];
    }
    cout << ans << endl;
    return 0;
}
