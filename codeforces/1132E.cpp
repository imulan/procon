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

const int N = 8;
const int L = 840; // lcm(1,2,3,4,5,6,7,8) = 840
const int M = 8*L+1;
const ll INF = LLONG_MAX/3;

int main(){
    ll W;
    cin >>W;
    vector<ll> ct(N);
    rep(i,N) cin >>ct[i];

    vector<ll> dp(M, -INF);
    dp[0] = 0;
    rep(i,N){
        vector<ll> nx(M,-INF);
        int need = L/(i+1);
        rep(num,need){
            ll rem = ct[i]-num;
            if(rem<0) break;

            ll block = rem/need;

            for(int j=M-1; j>=0; --j){
                int nj = j+num*(i+1);
                if(nj>=M) continue;
                nx[nj] = max(nx[nj], dp[j]+block);
            }
        }
        dp = nx;
    }

    ll ans = 0;
    rep(i,M)if(dp[i]>=0){
        ll rem = W-i;
        if(rem<0) continue;

        ll num = min(dp[i], rem/L);
        ans = max(ans, num*L+i);
    }
    cout << ans << "\n";
    return 0;
}
