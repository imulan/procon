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

const ll mod = 1e9+7;

const int N = 55;
const int M = 3003;
ll dp[N][M][2];

int main(){
    int n,K;
    cin >>n >>K;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    dp[0][0][0] = 1;
    rep(i,n){
        int num = 0;
        ll tmp = a[i];
        while(tmp>0){
            tmp /= 2;
            ++num;
        }

        // num回割ると0になる
        rep(j,M)rep(flg,2)if(dp[i][j][flg]>0){

            // k回割る
            rep(k,num)if(j+k<M){
                (dp[i+1][j+k][flg] += dp[i][j][flg]) %= mod;
            }
            // num回割る
            if(j+num<M) (dp[i+1][j+num][1] += dp[i][j][flg]) %= mod;
        }
    }

    ll ans = 0;
    if(K>=M){
        rep(i,M) (ans += dp[n][i][1]) %= mod;
    }
    else{
        (ans += dp[n][K][0]) %= mod;
        rep(i,K+1) (ans += dp[n][i][1]) %= mod;
    }

    cout << ans << endl;
    return 0;
}
