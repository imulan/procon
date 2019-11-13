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

int main(){
    int n,m;
    cin >>n >>m;

    const int N = 1<<n;
    vector<int> dp(N,INF);
    dp[0] = 0;
    rep(i,m){
        int a,b;
        cin >>a >>b;

        int mask = 0;
        rep(j,b){
            int x;
            cin >>x;
            --x;
            mask |= (1<<x);
        }

        for(int j=N-1; j>=0; --j){
            int nx = j|mask;
            dp[nx] = min(dp[nx], dp[j]+a);
        }
    }

    int ans = dp[N-1];
    if(ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
