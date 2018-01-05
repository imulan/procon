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

bool is_kadomatsu(int x1, int x2, int x3){
    if(x1==x2 || x2==x3 || x1==x3) return false;

    if(min({x1,x2,x3})==x2 || max({x1,x2,x3})==x2) return true;
    return false;
}

using pi = pair<int,int>;
vector<int> G[1000];

string solve(){
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<pi> e(m);
    rep(i,m){
        int u,v;
        cin >>u >>v;
        --u; --v;
        e[i] = {u,v};
        G[u].pb(v);
        G[v].pb(u);
    }

    rep(i,m){
        int u=e[i].fi, v=e[i].se;
        for(int nx:G[u])if(nx!=v){
            if(is_kadomatsu(a[v],a[u],a[nx])) return "YES";
        }
        for(int nx:G[v])if(nx!=u){
            if(is_kadomatsu(a[u],a[v],a[nx])) return "YES";
        }
    }
    return "NO";
}

int main(){
    cout << solve() << endl;
    return 0;
}
