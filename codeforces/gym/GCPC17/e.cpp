#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using LD = long double;
using P = pair<LD,int>;

const double EPS = 1e-7;

const int N = 800;
const int LIM = 3300000;

struct edge{
    int to;
    LD mul;
};
vector<edge> G[N];

bool solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m){
        int a,b;
        LD c;
        scanf(" %d %d %Lf", &a, &b, &c);
        --a;
        --b;
        G[a].pb({b,c});
    }

    rep(i,n){
        int ct = 0;
        vector<LD> d(n,0);
        d[i] = 1;
        priority_queue<P> pq;
        pq.push({1,i});
        while(!pq.empty()) {
            P now = pq.top();
            pq.pop();

            ++ct;
            if(ct > LIM) return false;

            int v = now.se;
//            printf(" %d: %Lf\n",v,d[v]);
            if(v==i && d[v]>1.0001) return false;

            if (now.fi+EPS < d[v]) continue;
            for (const auto &e:G[v]) {
//                printf(" e:: %d %f\n",e.to,e.mul);
                LD mm = d[v]*e.mul;
                if(d[e.to]+EPS < mm) {
                    d[e.to] = mm;
                    pq.push({mm, e.to});
                }
            }
        }
    }
    return true;
}

int main(){
    if(!solve()) printf("in");
    printf("admissible\n");
    return 0;

}