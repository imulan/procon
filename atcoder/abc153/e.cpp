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

const int INF = 200000000;

int main(){
    int h,n;
    cin >>h >>n;
    vector<int> a(n),b(n);
    rep(i,n) cin >>a[i] >>b[i];

    vector<int> dp(h+1, INF);
    dp[0] = 0;
    rep(i,h){
        rep(j,n){
            int ni = min(h,i+a[j]);
            dp[ni] = min(dp[ni], dp[i]+b[j]);
        }
    }
    cout << dp[h] << "\n";
    return 0;
}
