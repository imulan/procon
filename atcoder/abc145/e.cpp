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

using pi = pair<int,int>;
const int N = 6006;

int main(){
    int n,t;
    cin >>n >>t;

    vector<pi> p(n);
    rep(i,n){
        int a,b;
        cin >>a >>b;
        p[i]={a,b};
    }
    sort(all(p));

    vector<int> dp(N);
    rep(i,n){
        int a = p[i].fi, b = p[i].se;
        for(int j=t-1; j>=0; --j){
            int nj = j+a;
            dp[nj] = max(dp[nj], dp[j]+b);
        }
    }

    int ans = 0;
    for(int i:dp) ans = max(ans, i);
    cout << ans << "\n";
    return 0;
}
