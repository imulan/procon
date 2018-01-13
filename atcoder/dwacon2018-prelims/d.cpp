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

const int N = 1<<20;
const int INF = 25252525;

int main(){
    int n;
    cin >>n;
    vector<int> x(n);
    rep(i,n) cin >>x[i];

    vector<int> a(n);
    vector<int> must(n);
    for(int i=1; i<n; ++i){
        cin >>a[i];
        --a[i];
        must[a[i]] |= 1<<i;
    }

    vector<int> dp(1<<n,INF);
    dp[0] = 0;
    rep(mask,1<<n){
        int now = 0;
        for(int i=1; i<n; ++i){
            // 自分のデータが有る and まだ親のデータがない
            if((mask>>i&1 && !(mask>>a[i]&1))) now += x[i];
        }
        rep(i,n){
            if(mask>>i&1) continue;
            if((mask&must[i]) != must[i]) continue;
            int nx = mask | 1<<i;
            dp[nx] = min(dp[nx], max(dp[mask],now+x[i]));
        }
    }

    cout << dp.back() << endl;
    return 0;
}
