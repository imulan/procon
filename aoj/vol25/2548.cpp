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

inline int get_dice(){
    int ret;
    scanf(" %d", &ret);
    return ret-1;
}

inline void query(int move){
    printf("%d\n", move);
    fflush(stdout);
}

struct edge{
    int to;
    double cost;
};

const int N = 300;
vector<edge> G[N],rG[N];

void solve(){
    int m;
    scanf(" %d", &m);

    int a[6];
    rep(i,6) scanf(" %d", &a[i]);

    int s,g;
    scanf(" %d %d", &s, &g);
    --s;
    --g;

    vector<int> x(m);
    rep(i,m) scanf(" %d", &x[i]);

    auto IN = [&](int pos){
        return 0<=pos && pos<m;
    };

    auto move = [&](int pos, int aidx, int mul){
        if(mul==0) return pos;

        int nx = pos + mul*a[aidx];
        if(!IN(nx)) return -1;
        nx += x[nx];
        if(!IN(nx)) return -1;
        return nx;
    };

    rep(i,m){
        vector<int> ct(m);

        rep(j,6){
            vector<int> ttt(m);
            for(int k=-1; k<=1; ++k){
                int nx = move(i,j,k);
                if(nx!=-1) ttt[nx]=1;
            }

            rep(k,m) ct[k] += ttt[k];
        }

        rep(j,m){
            if(ct[j]>0){
                double COST = 1.0*ct[j]/6;
                G[i].pb({j, COST});
                rG[j].pb({i, COST});
            }
        }
    }

    const double INF = 19191919;
    vector<double> E(m,INF);
    vector<double> pp(m,1);
    vector<double> qq(m,0);

    E[g] = 0;

    using P = pair<double,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,g});
    while(!pq.empty()){
        P cur = pq.top();
        pq.pop();
        int v = cur.se;
        if(cur.fi > E[v]) continue;

        // dbg(v);
        for(const auto &e:rG[v]){
            double tp = pp[e.to] + e.cost*E[v];
            double tq = qq[e.to] + e.cost;
            double ne = tp/tq;
            // dbg(e.to);dbg(ne);
            if(E[e.to] > ne){
                pp[e.to] = tp;
                qq[e.to] = tq;
                E[e.to] = ne;
                pq.push({E[e.to], e.to});
            }
        }
    }

    // rep(i,m) printf(" %d: %.5f\n",i,E[i]);

    int now = s;
    rep(loop,3000){
        // printf(" now %d \n", now);
        int idx = get_dice();

        double tmpE = E[now];
        int ans = 0;
        for(int i=-1; i<=1; ++i){
            int nxt = move(now, idx, i);
            // dbg(i);dbg(nxt);
            if(nxt!=-1){
                if(tmpE > E[nxt]){
                    ans = i;
                    tmpE = E[nxt];
                }
            }
        }

        now = move(now,idx,ans);
        query(ans);
        if(now == g) return;
    }

    while(1){}
}

int main(){
    solve();
    return 0;
}
