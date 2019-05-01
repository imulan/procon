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

const ll mod = 1000000007;
const int N = 3003;

// dp[i][j] := p[i]まで決定p[i]にはj番目に小さい値
ll dp[N][N];

int main(){
    int n;
    string s;
    cin >>n >>s;

    dp[0][0] = 1;
    for(int i=1; i<n; ++i){
        if(s[i-1] == '<'){
            ll t = 0;
            rep(j,i+1){
                dp[i][j] = t;
                (t += dp[i-1][j]) %= mod;
            }
        }
        else{
            ll t = 0;
            for(int j=i; j>=0; --j){
                dp[i][j] = t;
                if(j>0) (t += dp[i-1][j-1]) %= mod;
            }
        }
    }

    ll ans = 0;
    rep(i,N) (ans += dp[n-1][i]) %= mod;
    cout << ans << endl;
    return 0;
}
