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

const int N = 300003;
ll dp[N][3];

int main(){
    int n,x;
    scanf(" %d %d", &n, &x);

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    rep(i,n)rep(j,3){
        rep(jj,2){
            int nj = j+jj;
            if(nj>=3) continue;

            ll add = a[i];
            if(nj==1) add *= x;

            dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+add);
        }
    }

    ll ans = 0;
    rep(i,N)rep(j,3) ans = max(ans, dp[i][j]);
    printf("%lld\n", ans);
    return 0;
}
