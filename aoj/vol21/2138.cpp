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

const int INF = 19191919;

int main(){
    int n,m;
    while(scanf(" %d %d", &n, &m),n){
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        vector<int> c(1<<n);
        rep(mask,1<<n){
            rep(i,n)if(mask>>i&1) c[mask] += a[i];
        }

        vector<int> dp(m+1,INF);
        dp[0] = 0;
        rep(i,m){
            rep(mask,1<<n){
                if(i+c[mask]>m) continue;
                dp[i+c[mask]] = min(dp[i+c[mask]], dp[i]+1);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
