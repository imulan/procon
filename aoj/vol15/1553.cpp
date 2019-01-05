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

const int N = 400040;
const int S = 200002;

const ll INF = LLONG_MAX/3;

struct edge{
    int to;
    ll cost;
};

vector<edge> G[N];
ll d[N];

bool IN(int x){
    return 0<=x && x<N;
}

int main(){
    int n,x;
    cin >>n >>x;

    rep(i,n){
        int dd,c;
        cin >>dd >>c;

        rep(j,N)for(int k:{-1,1}){
            int nx = j + k*dd;
            if(IN(nx)) G[j].pb({nx,c});
        }
    }

    fill(d,d+N,INF);
    d[S] = 0;

    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,S});
    while(!pq.empty()){
        P c = pq.top();
        pq.pop();

        int v = c.se;
        if(c.fi > d[v]) continue;

        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                pq.push({d[e.to], e.to});
            }
        }
    }

    ll ans = d[S+x];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
