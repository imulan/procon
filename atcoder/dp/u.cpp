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

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    cin >>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >>a[i][j];

    vector<ll> val(1<<n);
    rep(mask,1<<n){
        rep(i,n)rep(j,i)if((mask>>i&1) && (mask>>j&1)) val[mask]+=a[i][j];
    }

    vector<ll> dp(1<<n,-INF);
    dp[(1<<n)-1] = 0;
    for(int mask=(1<<n)-1; mask>0; --mask){
        int nx = (mask-1)&mask;
        while(1){
            int g = mask&(~nx);
            dp[nx] = max(dp[nx], dp[mask]+val[g]);

            if(nx == 0) break;
            nx = (nx-1)&mask;
        }
    }
    cout << dp[0] << "\n";
    return 0;
}
