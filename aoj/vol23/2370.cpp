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

const int INF = 12345678;

const int B = 320;
const int N = 100010;
vector<int> G[N];

int dp[N][2], nx[N][2];
int dp2[N], nx2[N];

ll solve(){
    int n,m;
    cin >>n >>m;
    rep(i,m){
        int u,v;
        cin >>u >>v;
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> d(n,INF);
    vector<int> x;
    rep(i,n){
        if(d[i]!=INF) continue;

        queue<int> que;
        vector<int> cc;

        d[i] = 0;
        que.push(i);
        cc.pb(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    d[e] = d[v]+1;
                    que.push(e);
                    cc.pb(e);
                }
            }
        }

        int diff = 0;
        for(int v:cc){
            if(d[v]%2==0) ++diff;
            else --diff;

            for(int e:G[v]){
                // 奇閉路が存在する
                if(abs(d[v]-d[e])%2==0) return -1;
            }
        }

        x.pb(abs(diff));
    }

    vector<int> s,l;
    for(int i:x){
        if(i<B) s.pb(i);
        else l.pb(i);
    }

    vector<int> Ld, Sd;

    // calc small
    vector<int> ct(B);
    for(int i:s) ++ct[i];

    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i=1; i<B; ++i){
        memset(nx,-1,sizeof(nx));

        priority_queue<P> pq;
        int C = ct[i];
        rep(j,N)if(dp[j][0]>=0){
            pq.push({C,{j,C%2}});
            nx[j][C%2] = C;
        }

        while(!pq.empty()){
            P now = pq.top();
            pq.pop();

            if(now.fi == 0) continue;

            pi p = now.se;
            for(int j=-1; j<=1; j+=2){
                int idx = abs(p.fi+j*i);

                if(idx<N && nx[idx][!p.se] < now.fi-1){
                    nx[idx][!p.se] = now.fi-1;
                    pq.push({nx[idx][!p.se], {idx,!p.se}});
                }
            }
        }

        rep(j,N)rep(k,2) dp[j][k] = nx[j][k];
    }
    rep(i,N)if(dp[i][0]>=0) Sd.pb(i);

    // calc large
    int L = l.size();

    memset(dp2,0,sizeof(dp2));
    queue<pi> que;

    dp2[0] = 1;
    rep(i,L){
        memset(nx2,0,sizeof(nx2));
        rep(j,N)if(dp2[j]){
            for(int k=-1; k<=1; k+=2){
                int idx = abs(j+k*l[i]);
                if(idx<N) nx2[idx] = 1;
            }
        }

        rep(j,N) dp2[j] = nx2[j];
    }
    rep(i,N)if(dp2[i]) Ld.pb(i);

    // calc ans
    ll ans = 0;

    int sz = Sd.size();
    for(int i:Ld){
        int idx = lower_bound(all(Sd), i) - Sd.begin();
        for(int a=-1; a<=1; ++a){
            int j = idx + a;
            if(0<=j && j<sz){
                int dd = abs(i-Sd[j]);
                if(n-dd>0){
                    // assert((n-dd)%2==0);
                    int xx = (n-dd)/2;

                    ll X = xx, Y = xx+dd;
                    ans = max(ans, X*Y-m);
                }
            }
        }
    }

    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
