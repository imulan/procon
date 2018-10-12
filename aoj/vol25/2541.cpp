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

struct edge{int to; ll cost;};

const int N = 1000, B = 101;
const ll INF = LLONG_MAX/111;

vector<edge> G[N];
ll d[N][B];

using pi = pair<int,int>;
using P = pair<ll,pi>;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    int n,m,s1,s2,t;
    while(cin >>n >>m >>s1 >>s2 >>t,n){
        rep(i,N) G[i].clear();

        --s1;
        --s2;
        --t;

        rep(i,m){
            int a,b;
            string w;
            cin >>a >>b >>w;
            --a;
            --b;

            ll cost;
            if(w == "x") cost = -1;
            else cost = stoll(w);

            G[a].pb({b,cost});
            G[b].pb({a,cost});
        }

        rep(i,N)rep(j,B) d[i][j] = INF;

        d[t][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{t,0}});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int v = now.se.fi, b = now.se.se;
            if(now.fi > d[v][b]) continue;

            for(const auto &e:G[v]){
                if(e.cost == -1){
                    if(b+1<B && d[e.to][b+1] > d[v][b]){
                        d[e.to][b+1] = d[v][b];
                        pq.push({d[e.to][b+1], {e.to,b+1}});
                    }
                }
                else{
                    if(d[e.to][b] > d[v][b]+e.cost){
                        d[e.to][b] = d[v][b]+e.cost;
                        pq.push({d[e.to][b], {e.to,b}});
                    }
                }
            }
        }

        vector<ll> cand;
        cand.pb(0);
        cand.pb(INF);
        rep(b1,B)rep(b2,B){
            if(b1 == b2) continue;
            if(d[s1][b1] == INF || d[s2][b2] == INF) continue;

            ll D = abs(d[s1][b1] - d[s2][b2]);
            D /= abs(b1-b2);
            for(int i=-1; i<=1; ++i)if(D+i>0) cand.pb(D+i);

            D = abs(d[s1][b1] - d[s1][b2]);
            D /= abs(b1-b2);
            for(int i=-1; i<=1; ++i)if(D+i>0) cand.pb(D+i);

            D = abs(d[s2][b1] - d[s2][b2]);
            D /= abs(b1-b2);
            for(int i=-1; i<=1; ++i)if(D+i>0) cand.pb(D+i);
        }
        sort(all(cand));
        cand.erase(unique(all(cand)), cand.end());

        ll ans = INF;
        for(ll w:cand){
            ll d1 = LLONG_MAX, d2 = LLONG_MAX;
            rep(i,B){
                if(d[s1][i]<INF) d1 = min(d1, d[s1][i]+w*i);
                if(d[s2][i]<INF) d2 = min(d2, d[s2][i]+w*i);
            }

            ans = min(ans, abs(d1-d2));
        }

        cout << ans << endl;
    }
    return 0;
}
