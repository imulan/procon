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

int main(){
    int n,m;
    string s;
    cin >>n >>m >>s;

    vector<vector<int>> ct(m, vector<int>(m));
    rep(i,n-1){
        int u = s[i]-'a', v = s[i+1]-'a';
        ++ct[u][v];
        ++ct[v][u];
    }

    vector<int> dp(1<<m,19191919);
    dp[0] = 0;
    rep(mask,1<<m){
        int pos = __builtin_popcount(mask);

        rep(i,m)if(!(mask>>i&1)){
            int nx = mask|(1<<i);
            int add = 0;
            rep(j,m)if(i!=j){
                if(mask>>j&1) add += ct[i][j]*pos;
                else add -= ct[i][j]*pos;
            }
            dp[nx] = min(dp[nx], dp[mask]+add);
        }
    }

    cout << dp.back() << "\n";
    return 0;
}
