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

int n;
vector<ll> a;

const int N = 2020;
const ll INF = LLONG_MAX/3;
ll dp[N][2];

ll dfs(int d, int t){
    if(dp[d][t]<INF) return dp[d][t];

    ll ret = abs(a[n-1]-a[d-1]);
    for(int i=d; i<n-1; ++i){
        if(t==0) ret = max(ret, dfs(i+1,!t));
        else ret = min(ret, dfs(i+1,!t));
    }
    return dp[d][t] = ret;
}

int main(){
    int z,w;
    cin >>n >>z >>w;
    a.pb(w);
    rep(i,n){
        int x;
        cin >>x;
        a.pb(x);
    }

    n = a.size();

    fill(dp[0],dp[N],INF);
    cout << dfs(1,0) << endl;
    return 0;
}
