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

const ll INF = LLONG_MAX/3;

const int N = 200000;
ll dp[N][2];

int main(){
    int n,c;
    scanf(" %d %d", &n, &c);

    vector<int> a(n-1),b(n-1);
    rep(i,n-1) scanf(" %d", &a[i]);
    rep(i,n-1) scanf(" %d", &b[i]);

    fill(dp[0], dp[N], INF);
    dp[0][0] = 0;
    rep(i,n){
        dp[i][1] = min(dp[i][1], dp[i][0]+c);
        dp[i][0] = min(dp[i][0], dp[i][1]);

        if(i+1<n){
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]+a[i]);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1]+b[i]);
        }
    }

    rep(i,n) printf("%lld%c", dp[i][0], " \n"[i==n-1]);
    return 0;
}
