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

const int D = 366;
const int N = 100000;

const ll INF = LLONG_MAX/3;

ll dp[N+1];

int main(){
    int d;
    cin >>d;
    vector<ll> p(d);
    rep(i,d) cin >>p[i];

    rep(i,N+1) dp[i] = -INF;
    dp[0] = 100;
    rep(i,d){
        rep(j,N+1) dp[0] = max(dp[0], dp[j]+p[i]*j);
        rep(j,N)if(dp[j]-p[i]>=0) dp[j+1] = max(dp[j+1], dp[j]-p[i]);
    }
    cout << dp[0] << endl;
    return 0;
}
