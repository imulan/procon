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

const int N = 100;

vector<int> G[N];
bool vis[N];
vector<int> t;
void dfs(int v){
    vis[v] = true;
    for(int nx:G[v]){
        if(!vis[nx]) dfs(nx);
    }
    t.pb(v);
}

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    rep(i,n)rep(j,n){
        if(a[i]%3==0){
            if(a[i]/3 == a[j]) G[i].pb(j);
        }
        if(a[i]*2 == a[j]) G[i].pb(j);
    }

    rep(i,n){
        t.clear();
        fill(vis,vis+N,false);
        dfs(i);
        if(t.size()==n){
            reverse(all(t));
            break;
        }
    }

    rep(i,n) cout << a[t[i]] << " \n"[i==n-1];
    return 0;
}
