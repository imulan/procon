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
    vector<bool> namori;

    UF() {}
    UF(int N):n(N), d(N,-1), namori(N,false){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y){
            if(!namori[X]){
                namori[X] = true;
                return true;
            }
            return false;
        }

        if(namori[X] && namori[Y]) return false;

        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        namori[X] = namori[X]|namori[Y];
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

using pi = pair<int,int>;
using edge = pair<int,pi>;

int main(){
    int n,m;
    cin >>n >>m;

    vector<edge> e(m);
    rep(i,m){
        int a,b,c;
        cin >>a >>b >>c;
        --a; --b;
        e[i] = {c,{a,b}};
    }
    sort(all(e),greater<edge>());

    UF uf(n);
    int ans = 0;
    rep(i,m){
        int a = e[i].se.fi, b = e[i].se.se;
        if(uf.unite(a,b)) ans += e[i].fi;
    }
    cout << ans << endl;
    return 0;
}
