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

const int mod = 1e9+7;
const int M = 13;

int main(){
    string s;
    cin >>s;

    int n = s.size();

    int dp[M] = {};
    dp[0] = 1;

    rep(i,n){
        int l = 0, r = 10;
        if(s[i] != '?'){
            l = s[i]-'0';
            r = l+1;
        }

        int nx[M] = {};
        for(int j=l; j<r; ++j){
            rep(k,M){
                int a = (k*10+j)%M;
                (nx[a] += dp[k]) %= mod;
            }
        }

        rep(j,M) dp[j] = nx[j];
    }

    cout << dp[5] << endl;
    return 0;
}
