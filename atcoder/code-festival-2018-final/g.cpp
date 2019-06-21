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

ll a[N],p[N];

ll f(int l, int r){
    if(l>r) return INF;
    ll ret = p[r];
    if(l>0) ret -= p[l-1];
    return ret*(r-l+1);
}

ll dp[N],nx[N];
int midx[N];
void minima(int ly, int ry, int lx, int rx){
    if(ly > ry) return;
    if(ly == ry){
        int idx = lx;
        ll v = dp[lx]+f(lx,ly-1);
        for(int j=lx+1; j<=rx; ++j){
            ll tv = dp[j]+f(j,ly-1);
            if(tv<=v){
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
    int n,m;
    cin >>n >>m;
    rep(i,n) cin >>a[i];
    sort(a,a+n);

    p[0] = a[0];
    for(int i=1; i<n; ++i) p[i] = p[i-1]+a[i];

    fill(dp,dp+N,INF);
    dp[0] = 0;
    rep(i,m){
        minima(1,n,0,n-1);
        rep(j,N) dp[j] = nx[j];
    }
    cout << dp[n] << endl;
    return 0;
}
