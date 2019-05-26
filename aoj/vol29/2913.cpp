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

const int N = 100100;
const int INF = 19191919;
vector<int> G[N];
int d[N][2];

const int P = 1000000;
bool prime[P];

int main(){
    fill(prime, prime+P, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<P; ++i){
        if(prime[i]) for(int j=2*i; j<P; j+=i) prime[j] = false;
    }

    int n,m,s,t;
    scanf(" %d %d %d %d", &n, &m, &s, &t);

    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        G[a].pb(b);
        G[b].pb(a);
    }

    fill(d[0],d[N],INF);
    d[s][0] = 0;
    queue<pi> que({{s,0}});
    while(!que.empty()){
        pi now = que.front();
        que.pop();

        int v = now.fi, p = now.se;
        int np = !p;
        for(int e:G[v]){
            if(d[e][np] > d[v][p]+1){
                d[e][np] = d[v][p]+1;
                que.push({e,np});
            }
        }
    }

    int ans = INF;
    if(d[t][1]<INF){
        ans = d[t][1];
        while(!prime[ans]) ans += 2;
    }
    if(d[t][0]<=2) ans = 2;
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}
