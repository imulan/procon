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

using vi = vector<int>;
using vvi = vector<vi>;

const int Y = 1010;
const int INF = 19191919;

struct Town{
    int k;
    vi a,b,c;

    int dp[Y];

    Town(){}

    void init(){
        // read
        cin >>k;
        a.assign(k,0);
        b.assign(k,0);
        c.assign(k,0);
        rep(i,k) scanf(" %d %d %d", &a[i], &b[i], &c[i]);

        // make dp table
        rep(i,Y) dp[i] = -INF;
        dp[0] = 0;
        rep(i,k){
            int rem = c[i];
            int num = 1;

            while(rem>0){
                for(int j=Y-1; j>=0; --j)if(dp[j] > -INF){
                    int nx = j+a[i]*num;
                    if(nx<Y) dp[nx] = max(dp[nx], dp[j]+b[i]*num);
                }

                rem -= num;
                num *= 2;
                if(num > rem) num = rem;
            }
        }

        rep(i,Y-1) dp[i+1] = max(dp[i+1], dp[i]);
    }

    int MAX(int yen){
        return dp[yen];
    }
};

int main(){
    int n,x,y;
    scanf(" %d %d %d", &n, &x, &y);

    vector<Town> t(n);
    rep(i,n) t[i].init();

    vvi d(n, vi(n));
    rep(i,n)rep(j,n) cin >>d[i][j];

    // Floyd-Warshall
    rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    // calc move cost
    vvi dp(1<<n, vi(n,INF));
    dp[1][0] = 0;
    rep(mask,1<<n)rep(i,n)if(mask>>i&1){
        rep(j,n){
            if(mask>>j&1) continue;
            int nmask = mask|(1<<j);
            dp[nmask][j] = min(dp[nmask][j], dp[mask][i]+d[i][j]);
        }
    }

    vi move_cost(1<<n,INF);
    rep(mask,1<<n){
        rep(i,n) move_cost[mask] = min(move_cost[mask], dp[mask][i]+d[i][0]);
    }

    // two groups
    int A = n/2, B = n-A;

    // groupA : 0 ~ A-1
    vvi dpa(1<<A, vi(Y, -INF));
    dpa[0][0] = 0;
    rep(i,A){
        rep(mask,1<<i){
            int nmask = mask|(1<<i);

            int tidx = i;
            rep(j,Y)if(dp[mask][j] > -INF){
                rep(k,Y){
                    int nj = j+k;
                    if(nj >= Y) break;

                    dpa[nmask][nj] = max(dpa[nmask][nj], dpa[mask][j]+t[tidx].MAX(k));
                }
            }
        }
    }

    // groupB : A ~ A+B-1
    vvi dpb(1<<B, vi(Y, -INF));
    dpb[0][0] = 0;
    rep(i,B){
        rep(mask,1<<i){
            int nmask = mask|(1<<i);

            int tidx = A+i;
            rep(j,Y)if(dp[mask][j] > -INF){
                rep(k,Y){
                    int nj = j+k;
                    if(nj >= Y) break;

                    dpb[nmask][nj] = max(dpb[nmask][nj], dpb[mask][j]+t[tidx].MAX(k));
                }
            }
        }
    }

    // check all masks
    int ans = 0;

    int AA = (1<<A)-1, BB = (1<<B)-1;
    rep(mask,1<<n){
        int amask = mask&AA;
        int bmask = (mask>>A)&BB;

        int cost = move_cost[mask];
        // use ai yen for group A
        rep(ai,y+1){
            int bi = min(y-ai, x-cost-ai);
            if(bi<0) break;

            ans = max(ans, dpa[amask][ai]+dpb[bmask][bi]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
