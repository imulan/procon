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

const int N = 9;
const int INF = 2000000002;

using pi = pair<int,int>;

int READ_MASK(){
    int n;
    scanf(" %d", &n);

    int ret = 0;
    rep(i,n){
        int b;
        scanf(" %d", &b);
        --b;
        ret |= 1<<b;
    }
    return ret;
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> p(1<<N);
    rep(i,n) ++p[READ_MASK()];

    vector<int> cover(1<<N);
    rep(i,1<<N){
        rep(j,1<<N)if((i&j) == j) cover[i] += p[j];
    }

    vector<int> c(m), g(m);
    rep(i,m){
        scanf(" %d", &c[i]);
        g[i] = READ_MASK();
    }

    vector<vector<pi>> cost(1<<N);
    rep(i,m) cost[g[i]].pb({c[i],i});
    rep(i,1<<N) sort(all(cost[i]));

    int num = -1, min_cost = INF;
    pi ans;
    auto UPDATE = [&](int mask, pi cx, pi cy){
        int tcost = cx.fi+cy.fi;
        if(cover[mask]>num || (cover[mask]==num && min_cost>tcost)){
            num = cover[mask];
            min_cost = tcost;
            ans = {cx.se, cy.se};
        }
    };

    rep(i,1<<N)if(!cost[i].empty()){
        if(cost[i].size()>=2) UPDATE(i, cost[i][0], cost[i][1]);

        rep(j,1<<N)if(i!=j && !cost[j].empty()){
            UPDATE(i|j, cost[i][0], cost[j][0]);
        }
    }
    printf("%d %d\n", ans.fi+1, ans.se+1);
    return 0;
}
