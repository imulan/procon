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

const ll INF = LLONG_MAX/3;

using pi = pair<int,int>;

// a->b, c: one-way/round
using P = pair<pi,int>;

int main(){
    int n,d;
    scanf(" %d %d", &n, &d);

    vector<int> a(d);
    rep(i,d){
        scanf(" %d", &a[i]);
        --a[i];
    }

    int m;
    scanf(" %d", &m);

    map<P,ll> ticket;
    rep(i,m){
        int f,t,c;
        char tt;
        scanf(" %d %d %c %d", &f, &t, &tt, &c);
        --f;
        --t;

        P pp = {{f,t},(tt=='R')};
        if(!ticket.count(pp)) ticket[pp] = c;
        else ticket[pp] = min(ticket[pp], (ll)c);
    }

    map<pi,vector<pi>> trip;
    rep(i,d-1){
        int u = a[i], v = a[i+1];
        pi key = {min(u,v), max(u,v)};
        trip[key].pb({u,v});
    }

    ll ans = 0;
    for(const auto &p:trip){
        int u = p.fi.fi, v = p.fi.se;

        vector<int> x;
        for(pi i:p.se) x.pb( i.fi==v );
        int X = x.size();

        ll cuv = INF;
        if(ticket.count( {{u,v},1}) ) cuv = ticket[{{u,v},1}];
        ll cvu = INF;
        if(ticket.count( {{v,u},1}) ) cvu = ticket[{{v,u},1}];

        ll cu = cuv;
        if(ticket.count( {{u,v},0}) ) cu = min(cu, ticket[{{u,v},0}]);
        ll cv = cvu;
        if(ticket.count( {{v,u},0}) ) cv = min(cv, ticket[{{v,u},0}]);

        if(cuv > cvu){
            swap(u,v);
            swap(cuv,cvu);
            swap(cu,cv);
            rep(i,X) x[i] = !x[i];
        }
        // cuv <= cvu

        // printf(" %d %d ::  one %lld  %lld  round  %lld  %lld\n",u+1,v+1,cu,cv,cuv,cvu);
        // dbg(x);

        set<int> pos[2];
        rep(i,X) pos[x[i]].insert(i);

        ll add = 0;
        int TT = -1;
        if(cu+cv <= cuv){
            // cu+cv <= cuv <= cvu
            // 全部片道で買う
            TT = 0;
        }
        else if(cu+cv <= cvu){
            // cuv < cu+cv <= cvu
            // uv往復 → 残り片道
            TT = 1;
        }
        else{
            // cuv <= cvu < cu+cv
            // uv往復 → vu往復 → 残り片道
            TT = 2;
        }

        // 往復分
        rep(i,TT){
            ll COST = cuv;
            if(i) COST = cvu;

            auto itr = pos[i].begin();
            while(itr != pos[i].end()){
                auto bk = pos[!i].lower_bound( *itr );
                if(bk == pos[!i].end()) break;
                else{
                    add += COST;
                    pos[!i].erase(bk);
                    itr = pos[i].erase(itr);
                }
            }
        }
        // 残ったぶん
        add += cu * pos[0].size();
        add += cv * pos[1].size();

        ans += add;
    }
    printf("%lld\n", ans);
    return 0;
}
