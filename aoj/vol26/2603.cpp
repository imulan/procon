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

const int N = 2002;
const ll INF = LLONG_MAX/3;

ll f[N][N];

ll dp[N],nx[N];
int midx[N];
void minima(int ly, int ry, int lx, int rx){
    if(ly > ry) return;
    if(ly == ry){
        int idx = lx;
        ll v = dp[lx]+f[lx+1][ly];
        for(int j=lx+1; j<=rx; ++j){
            ll tv = dp[j]+f[j+1][ly];
            if(tv<v){
                idx = j;
                v = tv;
            }
        }
        nx[ly] = v;
        midx[ly] = idx;
        return;
    }

    int my = (ly+ry)/2;
    minima(my,my,lx,rx);
    minima(ly,my-1,lx,midx[my]);
    minima(my+1,ry,midx[my],rx);
}

int main(){
    int s,n,m;
    cin >>s >>n >>m;

    vector<int> x(s);
    rep(i,s) cin >>x[i];

    vector<int> a;
    rep(i,n){
        int t,p;
        cin >>t >>p;
        --p;

        // 待ち時間0のためにバス停0を出るべき時間
        t -= x[p];
        a.pb(t);
    }
    a.pb(-10101);
    sort(all(a));
    int A = a.size();

    fill(f[0],f[N],INF);
    rep(r,A){
        int d_time = a[r];
        ll sum = 0;
        for(int l=r; l>=0; --l){
            sum += d_time - a[l];
            f[l][r] = sum;
        }
    }

    fill(dp,dp+N,INF);
    dp[0] = 0;
    rep(i,m){
        minima(0,A-1,0,A-1);
        rep(j,N) dp[j] = min(dp[j],nx[j]);
    }
    printf("%lld\n", dp[A-1]);
    return 0;
}
