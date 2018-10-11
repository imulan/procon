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

using pi = pair<int,int>;

const int INF = 19191919;

const int N = 100000;
vector<int> G[N];
int d[N][2];

int main(){
    int n,m;
    cin >>n >>m;
    rep(i,m){
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    rep(i,n)rep(j,2) d[i][j] = INF;
    d[0][0] = 0;
    queue<pi> que({{0,0}});
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        int v = now.fi, p = now.se;
        for(int e:G[v]){
            if(d[e][!p] > d[v][p]+1){
                d[e][!p] = d[v][p]+1;
                que.push({e,!p});
            }
        }
    }

    int ans = INF;
    rep(p,2){
        int tmp = 0;
        rep(i,n) tmp = max(tmp, d[i][p]);
        ans = min(ans, tmp);
    }

    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
