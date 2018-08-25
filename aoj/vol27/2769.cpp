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

ll make(int d, int mask){
    string s = "";
    rep(i,d){
        if(mask>>i&1) s += '8';
        else s += '2';
    }
    return atoll(s.c_str());
}

const int INF = 19191919;
vector<ll> v;
int V;

const int N = 1<<10;
map<ll,int> dp[N];
int dfs(int d, ll n){
    if(d==V){
        if(n==1) return 0;
        return -INF;
    }
    if(dp[d].count(n)) return dp[d][n];

    int ret = -INF;
    if(n%v[d]==0) ret = max(ret, dfs(d, n/v[d])+1);
    ret = max(ret, dfs(d+1, n));

    return dp[d][n] = ret;
}

int main(){
    ll n;
    cin >>n;
    if(n==1){
        cout << -1 << endl;
        return 0;
    }

    for(int i=1; i<=9; ++i){
        rep(mask,1<<i) v.pb(make(i,mask));
    }
    V = v.size();

    int ans = -1;

    ans = max(ans, dfs(0,n));
    for(int i=10; i<=18; ++i){
        rep(mask,1<<i){
            ll val = make(i,mask);
            if(n%val==0){
                ans = max(ans, dfs(0, n/val)+1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
