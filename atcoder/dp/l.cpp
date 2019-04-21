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

const int N = 3003;
int n;
ll a[N];

ll dp[N][N];
ll dfs(int l, int r){
    if(l>r) return 0;
    if(dp[l][r] != INF) return dp[l][r];

    int t = l+n-1-r;
    ll ret;
    if(t%2==0){
        // maximize
        ret = -INF;
        ret = max(ret, dfs(l+1,r)+a[l]);
        ret = max(ret, dfs(l,r-1)+a[r]);
    }
    else{
        // minimize
        ret = INF;
        ret = min(ret, dfs(l+1,r)-a[l]);
        ret = min(ret, dfs(l,r-1)-a[r]);
    }
    return dp[l][r] = ret;
}

int main(){
    cin >>n;
    rep(i,n) cin >>a[i];

    fill(dp[0],dp[N],INF);
    cout << dfs(0,n-1) << "\n";
    return 0;
}
