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
        // if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

const int INF = 1e9+19191919;

struct R{
    int val,len,lh,rh;
};

bool solve(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int V = 0;
    vector<R> v;

    int s = 0;
    while(s<n){
        int e = s;
        while(e<n && a[s] == a[e]) ++e;

        v.pb({a[s], e-s, V-1, V+1});
        ++V;
        s = e;
    }

    UF uf(V);
    int L = -1, R = V;

    using pi = pair<int,int>;
    set<pi> ms;
    rep(i,V){
        ms.insert({v[i].val, i});
    }

    while(1){
        pi pp = *ms.begin();

        int idx = pp.se;
        int l = v[idx].lh, r = v[idx].rh;

        // printf(" %d %d %d\n",idx,l,r);

        if(l==L && r==R) break;

        if(v[idx].len%2 == 1) return false;

        if(l!=L) l = uf.root(l);
        if(r!=R) r = uf.root(r);

        // printf(" cv lr %d %d\n", l,r);

        int tgt = INF;
        if(l!=L) tgt = min(tgt, v[l].val);
        if(r!=R) tgt = min(tgt, v[r].val);

        ms.erase(pp);

        v[idx].val = tgt;
        if(l!=L && v[l].val == tgt){
            v[idx].len += v[l].len;
            v[idx].lh = v[l].lh;
            ms.erase({v[l].val, l});
            uf.unite(idx,l);
        }
        if(r!=R && v[r].val == tgt){
            v[idx].len += v[r].len;
            v[idx].rh = v[r].rh;
            ms.erase({v[r].val, r});
            uf.unite(idx,r);
        }

        ms.insert({v[idx].val, idx});
    }

    return true;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
