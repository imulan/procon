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

int main(){
    int n;
    cin >>n;

    int V = n*n;
    vector<vector<int>> G(V);
    rep(i, 2*n*n-2*n){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<vector<int>> x(n, vector<int>(n,-1));

    rep(i,V)if(G[i].size() == 2){
        x[0][0] = i;
        x[0][1] = G[i][0];
        x[1][0] = G[i][1];
        break;
    }

    for(int i=2; i<n; ++i){
        int pre = x[0][i-2];
        int v = x[0][i-1];
        for(int e:G[v]){
            if(G[e].size()<=3 && e!=pre) x[0][i] = e;
        }
    }

    for(int i=2; i<n; ++i){
        int pre = x[i-2][0];
        int v = x[i-1][0];
        for(int e:G[v]){
            if(G[e].size()<=3 && e!=pre) x[i][0] = e;
        }
    }

    for(int i=1; i<n; ++i)for(int j=1; j<n; ++j){
        int p = x[i-1][j], q = x[i][j-1], r = x[i-1][j-1];
        for(int np:G[p])for(int nq:G[q]){
            if(np==nq && np!=r) x[i][j] = np;
        }
    }

    rep(i,n)rep(j,n) cout << x[i][j]+1 << " \n"[j==n-1];
    return 0;
}
