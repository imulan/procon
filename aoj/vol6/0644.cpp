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

const int INF = 10101010;

int main(){
    int n;
    cin >>n;
    vector<int> l(n);
    rep(i,n) cin >>l[i];

    vector<int> pre(n+1);
    rep(i,n) pre[i+1] = l[i];
    rep(i,n) pre[i+1] += pre[i];

    vector<int> v;
    rep(i,n)for(int j=i; j<n; ++j) v.pb(pre[j+1]-pre[i]);
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    int ans = INF;
    for(int lb:v){
        vector<int> dp(n+1,INF);
        dp[0]=0;
        rep(i,n){
            for(int j=i; j<n; ++j){
                if(i==0 && j==n-1) continue;

                int t = pre[j+1]-pre[i];
                if(t<lb) continue;
                dp[j+1] = min(dp[j+1], max(dp[i],t));
            }
        }

        ans = min(ans, dp[n]-lb);
    }
    cout << ans << endl;
    return 0;
}
