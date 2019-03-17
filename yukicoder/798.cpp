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

using pi = pair<int,int>;

const ll INF = LLONG_MAX/3;
const int N = 2002;
ll dp[N][N];

int main(){
    int n;
    cin >>n;

    vector<pi> v(n);
    rep(i,n){
        int a,b;
        cin >>a >>b;
        v[i] = {b,a};
    }
    sort(all(v));
    reverse(all(v));

    rep(i,N)rep(j,N) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n){
        int a = v[i].se, b = v[i].fi;
        // j番目に買う
        rep(j,N)if(dp[i][j] < INF){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+(a+b*j));
        }
    }

    ll ans = INF;
    for(int i=1; i<=n; ++i){
        int num = 0;
        for(int j=1; j<=i; ++j){
            ++num;
            if(j%2 == 0) ++num;
        }
        if(num >= n) ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
