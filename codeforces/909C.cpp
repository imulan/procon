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

const int N = 5005;
ll dp[N][N]={};

int main(){
    int n;
    cin >>n;
    vector<char> s(n);
    rep(i,n) cin >>s[i];

    dp[0][0] = 1;
    rep(i,n){
        if(s[i]=='s'){
            ll sum = 0;
            for(int j=N-1; j>=0; --j){
                (sum += dp[i][j]) %= mod;
                dp[i+1][j]=sum;
            }
        }
        else{
            rep(j,n) (dp[i+1][j+1] += dp[i][j]) %= mod;
        }
    }

    cout << dp[n][0] << endl;
    return 0;
}
