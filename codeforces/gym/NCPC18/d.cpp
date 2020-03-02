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

const int N = 1010;
const ll INF = LLONG_MAX/5;
// const ll LIM = 1000000000000LL;

// struct SegTree{
//     int n; vector<ll> dat;
//     SegTree(){}
//     SegTree(int _n){
//         n = 1;
//         while(n<_n) n*=2;
//         dat = vector<ll>(2*n-1,-INF);
//     }

//     void update(int k, ll a){
//         k+=n-1;
//         dat[k]=a;
//         while(k>0){
//             k=(k-1)/2;
//             dat[k]=max(dat[2*k+1],dat[2*k+2]);
//         }
//     }

//     ll _query(int a, int b, int k, int l, int r){
//         if(r<=a || b<=l) return -INF;
//         if(a<=l && r<=b) return dat[k];

//         ll vl = _query(a,b,2*k+1,l,(l+r)/2);
//         ll vr = _query(a,b,2*k+2,(l+r)/2,r);
//         return max(vl,vr);
//     }

//     ll query(int a, int b){
//         return _query(a,b,0,0,n);
//     }
// };


int q;
int s[N],u[N],t[N];

ll d[N][N];
ll max_cost[N][N];
ll mv[N][N];

ll dp[N];
bool check(ll M){
    fill(dp,dp+N,INF);
    dp[0] = 0;
    rep(i,q){
        int pre = 0;
        if(i>0) pre = u[i-1];

        for(int j=i; j<q; ++j){
            ll add = 0;
            if(dp[i]+d[pre][0] > t[j]) add = dp[i]+d[pre][0] - t[j];

            ll now = t[j]+add;
            int pos = 0;
            bool ok = true;
            ll gmx = 0;
            for(int k=i; k<=j; ++k){
                now += d[pos][u[k]];
                gmx = max(gmx,now-s[k]);
                pos = u[k];
            }

            ll mx = max_cost[i][j]+add;
            // printf(" %d %d :: %lld   %lld\n",i,j, mx,gmx);
            if(mx<=M) dp[j+1] = min(dp[j+1], t[j]+add+mv[i][j]);
        }
    }

    return dp[q]<INF;
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,N)rep(j,N) d[i][j] = INF;
    rep(i,N) d[i][i] = 0;

    rep(i,m){
        int a,b,D;
        scanf(" %d %d %d", &a, &b, &D);
        --a;
        --b;
        d[a][b] = d[b][a] = D;
    }
    rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    scanf(" %d", &q);
    rep(i,q){
        scanf(" %d %d %d", &s[i], &u[i], &t[i]);
        --u[i];
    }

    // vector<SegTree> st(q,SegTree(n));
    // rep(i,q){
    //     rep(j,q) st[i].update(j,t[i]-s[j]);
    // }

    rep(i,q){
        int pre = 0;
        if(i>0) pre = u[i-1];

        for(int j=i; j<q; ++j){
            ll now = t[j];
            int pos = 0;
            ll gmx = 0;
            for(int k=i; k<=j; ++k){
                now += d[pos][u[k]];
                gmx = max(gmx,now-s[k]);
                pos = u[k];
            }
            max_cost[i][j] = gmx;
        }
    }

    // mv
    rep(i,q){
        int pre = 0;
        ll tt = 0;
        for(int j=i; j<q; ++j){
            tt += d[pre][u[j]];
            mv[i][j] = tt;
            pre = u[j];
        }
    }

    ll ng = -1, ok = INF;
    while(ok-ng>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%lld\n", ok);
    return 0;
}
