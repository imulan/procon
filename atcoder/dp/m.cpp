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

const int mod = 1000000007;

int main(){
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> dp(k+1);
    dp[k] = 1;
    rep(i,n){
        vector<int> nx(k+1);

        int x = 0;
        for(int j=k; j>=k-a[i]; --j){
            (x += dp[j]) %= mod;
            nx[j] = x;
        }
        for(int j=k-a[i]-1; j>=0; --j){
            (x += dp[j]) %= mod;
            (x += mod-dp[j+a[i]+1]) %= mod;
            nx[j] = x;
        }

        dp = nx;
    }
    cout << dp[0] << "\n";
    return 0;
}
