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
using P = pair<int,pi>;

struct edge{int to,cost;};

const int N = 100;
const int INF = 123456789;
vector<edge> G[N];
int d[N][N];

int main(){
    int n,m,c;
    while(scanf(" %d %d %d", &n, &m, &c),n){
        rep(i,N) G[i].clear();
        fill(d[0],d[N],INF);

        rep(i,m){
            int f,t,w;
            scanf(" %d %d %d", &f, &t, &w);
            --f; --t;
            G[f].pb({t,w});
        }

        d[0][0]=0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int v = now.se.fi, num = now.se.se;
            if(d[v][num]<now.fi) continue;
            for(const auto &e:G[v]){
                if(num+1<N){
                    if(d[e.to][num+1] > d[v][num]){
                        d[e.to][num+1] = d[v][num];
                        pq.push({d[e.to][num+1], {e.to,num+1}});
                    }
                }

                if(d[e.to][num] > d[v][num]+e.cost){
                    d[e.to][num] = d[v][num]+e.cost;
                    pq.push({d[e.to][num], {e.to,num}});
                }
            }
        }

        int ans = 0;
        while(ans<N && d[n-1][ans]>c) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
