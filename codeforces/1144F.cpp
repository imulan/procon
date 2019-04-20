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

const int INF = 19191919;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    vector<int> u(m),v(m);
    rep(i,m){
        scanf(" %d %d", &u[i], &v[i]);
        --u[i];
        --v[i];
        G[u[i]].pb(v[i]);
        G[v[i]].pb(u[i]);
    }

    vector<int> d(n,INF);
    rep(i,n)if(d[i]==INF){
        d[i] = 0;
        queue<int> que({i});
        while(!que.empty()){
            int x = que.front();
            que.pop();
            for(int e:G[x]){
                if(d[e] > d[x]+1){
                    d[e] = d[x]+1;
                    que.push(e);
                }
            }
        }
    }

    rep(i,m){
        int dd = abs(d[u[i]]-d[v[i]]);
        if(dd%2==0){
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    rep(i,m) printf("%d", d[u[i]]%2);
    printf("\n");
    return 0;
}
