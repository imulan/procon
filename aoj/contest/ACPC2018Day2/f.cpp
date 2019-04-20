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

void test(){
    ll a,b;
    cin >>a >>b;

    for(ll t=0; t<100; ++t){
        printf(" t %lld  t+ceil(b/(a+t)) %lld\n", t, t+(b+a+t-1)/(a+t));
    }
}

const ll INF = LLONG_MAX/3;
const int N = 200000;
ll d[N];

struct edge{
    int to;
    ll a,b;
};

vector<edge> G[N];

double f(ll t, ll a, ll b){
    // printf(" f %lld %lld %lld  -> %lld\n",t,a,b,  t+(b/(t+a)));
    return t+(double)b/(t+a);
}

ll COST(ll t, ll a, ll b){
    if(a+t > b) return t+1;

    // printf(" Q %lld %lld %lld\n",t,a,b);
    ll l=t, r=b;
    while(r-l>2){
        ll ml = (2*l+r)/3, mr = (l+2*r)/3;

        if(f(ml,a,b) < f(mr,a,b)) r = mr;
        else l = ml;
        // printf(" lr %d %d\n",l,r);
    }

    ll ret = INF;
    for(ll i=l; i<=r; ++i) ret = min(ret, i+((b+i+a-1)/(i+a)));
    return ret;
}

int main(){
    // test();

    int n,m,s,g;
    scanf(" %d %d %d %d", &n, &m, &s, &g);
    --s;
    --g;

    rep(i,m){
        int u,v;
        ll a,b;
        scanf(" %d %d %lld %lld", &u, &v, &a, &b);
        --u;
        --v;
        G[u].pb({v,a,b});
        G[v].pb({u,a,b});
    }

    fill(d,d+N,INF);
    d[s] = 0;
    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        ll D = now.fi;
        int v = now.se;
        if(D > d[v]) continue;

        for(const auto &e:G[v]){
            ll nt = COST(d[v],e.a,e.b);
            if(d[e.to] > nt){
                // printf(" ----- v to nt %d %d %lld\n",v,e.to,nt);
                d[e.to] = nt;
                pq.push({d[e.to],e.to});
            }
        }
    }

    ll ans = d[g];
    if(ans == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
