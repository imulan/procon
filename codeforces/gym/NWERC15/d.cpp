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

const int N = 1000010;
const ll INF = LLONG_MAX/3;
ll dp[N];

ll r,p;
ll dfs(int n){
    if(n<=1) return 0;
    if(dp[n]>=0) return dp[n];

    ll ret = INF;
    for(int i=1; i<=n; ++i) ret = min(ret, p*i + dfs((n+i)/(i+1)) + r);

    return dp[n] = ret;
}

int main(){
    int n;
    cin >>n >>r >>p;

    fill(dp,dp+N,-1);
    cout << dfs(n) << endl;
    return 0;
}
