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

inline int dist(const pi &p, const pi &q){
    return abs(p.fi-q.fi) + abs(p.se-q.se);
}

const int N = 7;
const ll INF = LLONG_MAX/3;

ll min_time[1<<N][N];
ll ti[1<<N];

const int W = 10001;
ll max_val[W]={};
ll val[1<<N];

const int T = 10001;
ll dp[T];

int main(){
    int n,m,w,t;
    cin >>n >>m >>w >>t;

    map<string,int> name2id;
    vector<int> v(m),p(m);
    rep(i,m){
        string s;
        cin >>s >>v[i] >>p[i];
        name2id[s] = i;
    }

    vector<int> L(n);
    vector<pi> pos(n);
    vector<vector<pi>> city(n);
    rep(i,n){
        cin >>L[i] >>pos[i].fi >>pos[i].se;
        city[i] = vector<pi>(L[i]);
        rep(j,L[i]){
            string s;
            int q;
            cin >>s >>q;

            int ID = name2id[s];
            // weight, value
            city[i][j] = {v[ID], p[ID]-q};
        }
    }

    // calc minimum time
    rep(i,1<<N){
        rep(j,N) min_time[i][j] = INF;
        ti[i] = INF;
    }

    rep(i,n) min_time[1<<i][i] = dist(pos[i],{0,0});
    for(int mask=1; mask<(1<<n); ++mask){
        rep(from,n)if(mask>>from&1){
            rep(to,n)if(!(mask>>to&1)){
                int nmask = mask|(1<<to);
                min_time[nmask][to] = min(min_time[nmask][to], min_time[mask][from]+dist(pos[from],pos[to]));
            }
        }

        rep(i,n){
            ti[mask] = min(ti[mask], min_time[mask][i]+dist(pos[i],{0,0}));
        }
    }
    ti[0] = 0;

    // calc maximum value
    rep(mask,1<<n){
        memset(max_val, 0, sizeof(max_val));

        vector<pi> item;
        rep(i,n)if(mask>>i&1){
            rep(j,L[i]) item.pb(city[i][j]);
        }
        int SZ = item.size();

        rep(i,w){
            rep(j,SZ)if(i+item[j].fi<=w){
                max_val[i+item[j].fi] = max(max_val[i+item[j].fi], max_val[i]+item[j].se);
            }
        }

        rep(i,w+1) val[mask] = max(val[mask], max_val[i]);
    }

    // calc dp
    rep(i,t){
        rep(mask,1<<n){
            int ni = i+ti[mask];
            if(ni<=t){
                dp[ni] = max(dp[ni], dp[i]+val[mask]);
            }
        }
    }

    ll ans = 0;
    rep(i,t+1) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
