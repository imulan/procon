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

const int N = 10010;

const int GR = 10000;
const int G1 = 10000, G2 = 10001, G3 = 10002;
const int INF = 19191919;

struct edge{
    int to,cost;
};
vector<edge> G[N];

int ma = INF, mb = INF, mc = INF;

void dijk(int start, vector<int> &d, vector<int> &mp){
    d = vector<int>(N,INF);

    deque<int> dq;
    d[start] = 0;
    dq.push_front(start);
    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();

        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                if(e.cost==0) dq.push_front(e.to);
                else dq.push_back(e.to);
            }
        }
    }

    mp = vector<int>(N);
    rep(i,N) mp[i] = i;
    mp[GR] = ma;
    mp[GR+1] = mb;
    mp[GR+2] = mc;

    vector<bool> vis(N);
    dq.push_front(start);
    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();
        vis[v] = true;

        for(const auto &e:G[v]){
            if(d[e.to] == d[v]+e.cost){
                mp[e.to] = min(mp[e.to], mp[v]);
                if(!vis[e.to]){
                    if(e.cost==0) dq.push_front(e.to);
                    else dq.push_back(e.to);
                }
            }
        }
    }
}

int main(){
    int n,a,b,c;
    scanf(" %d %d %d %d", &n, &a, &b, &c);

    rep(i,a){
        int gidx = GR;
        int x;
        scanf(" %d", &x);
        --x;
        G[gidx].pb({x,0});
        G[x].pb({gidx,0});
        ma = min(ma,x);
    }

    rep(i,b){
        int gidx = GR+1;
        int x;
        scanf(" %d", &x);
        --x;
        G[gidx].pb({x,0});
        G[x].pb({gidx,0});
        mb = min(mb,x);
    }

    rep(i,c){
        int gidx = GR+2;
        int x;
        scanf(" %d", &x);
        --x;
        G[gidx].pb({x,0});
        G[x].pb({gidx,0});
        mc = min(mc,x);
    }

    int m;
    scanf(" %d", &m);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb({v,1});
        G[v].pb({u,1});
    }

    vector<int> d[3], minp[3];
    rep(i,3) dijk(GR+i, d[i], minp[i]);

    // rep(i,3){
    //     printf(" --- %d ---\n",i);
    //     rep(j,n) printf(" %d", d[i][j]);
    //     printf("\n");
    //     rep(j,n) printf(" %d", minp[i][j]);
    //     printf("\n");
    // }

    int ans = INF;
    int idx = INF;
    rep(i,n){
        int min_idx = N;
        int tmp = 0;
        rep(j,3){
            tmp += d[j][i];
            min_idx = min(min_idx, minp[j][i]);
        }
        // printf(" %d %d %d\n", i,tmp,min_idx);

        if(tmp < ans){
            ans = tmp;
            idx = min_idx;
        }
        else if(tmp == ans) idx = min(idx, min_idx);
    }

    cout << ans << " " << idx+1 << endl;
    return 0;
}
