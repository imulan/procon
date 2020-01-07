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

const int INF = 19191919;

const int M = 16;

const int MASK = (1<<M)-1;
const int LAST = 15;

int dp[1<<M], ndp[1<<M];

int main(){
    int n;
    scanf(" %d", &n);

    int a[5] = {};
    for(int i=1; i<=4; ++i) scanf(" %d", &a[i]);

    int m[10],cost[10];
    int midx = 0;
    for(int sz=1; sz<=4; ++sz){
        rep(sy,4-sz+1){
            int f[4][4];
            rep(y,4)rep(x,4) f[y][x] = 1;

            for(int y=sy; y<sy+sz; ++y)rep(x,sz) f[y][x] = 0;

            m[midx] = 0;
            rep(i,16){
                int y = i%4, x = i/4;
                m[midx] |= (f[y][x]<<i);
            }
            cost[midx] = a[sz];

            ++midx;
        }
    }

    vector<int> f[4];
    rep(i,4){
        char s[1010];
        scanf(" %s", s);

        vector<int> v(n);
        rep(j,n) v[j] = (s[j]=='*');
        f[i] = v;
    }

    int ini_mask = 0;
    rep(i,16){
        int y = i%4, x = i/4;
        ini_mask |= (f[y][x]<<i);
    }
    fill(dp,dp+(1<<M),INF);
    dp[ini_mask] = 0;

    rep(i,n){
        fill(ndp,ndp+(1<<M),INF);

        for(int mask=MASK; mask>=0; --mask)if(dp[mask]<INF){
            if((mask&LAST) == 0){
                int nx = mask;
                nx >>= 4;
                if(i+4<n){
                    rep(y,4) nx |= (f[y][i+4]<<(12+y));
                }
                ndp[nx] = min(ndp[nx], dp[mask]);
            }
            else{
                rep(j,10){
                    int nx = mask&m[j];
                    dp[nx] = min(dp[nx], dp[mask]+cost[j]);
                }
            }
        }

        memcpy(dp,ndp,sizeof(dp));
    }

    printf("%d\n", dp[0]);
    return 0;
}
