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

const ll INF = LLONG_MAX/3;
const int MAXV = 100010;

int main(){
    int n,W;
    cin >>n >>W;
    vector<int> w(n),v(n);
    rep(i,n) cin >>w[i] >>v[i];

    vector<ll> dp(MAXV, INF);
    dp[0] = 0;
    rep(i,n){
        for(int j=MAXV-1; j>=0; --j)if(dp[j]<INF){
            int nj = j+v[i];
            dp[nj] = min(dp[nj], dp[j]+w[i]);
        }
    }

    int ans = MAXV-1;
    while(dp[ans] > W) --ans;
    cout << ans << "\n";
    return 0;
}
