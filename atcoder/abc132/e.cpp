#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

const int N = 100010;
const int INF = 19191919;

vector<int> G[N];
int d[N][3];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
    }

    int s,t;
    scanf(" %d %d", &s, &t);
    --s;
    --t;

    rep(i,N)rep(j,3) d[i][j] = INF;
    d[s][0] = 0;
    queue<pi> que({{s,0}});
    while(!que.empty()){
        pi v = que.front();
        que.pop();

        int D = d[v.fi][v.se];
        int nx = (v.se+1)%3;

        for(int e:G[v.fi]){
            if(d[e][nx] > D+1){
                d[e][nx] = D+1;
                que.push({e,nx});
            }
        }
    }

    int ans = -1;
    if(d[t][0]<INF) ans = d[t][0]/3;
    printf("%d\n",ans);
    return 0;
}
