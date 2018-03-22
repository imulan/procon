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

const ll mod = 1e9+7;
const int N = 100010;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

int n,m;
int a[N],b[N];

ll M;
ll dp[N][2];
ll dfs(int x, int l){
    if(x==n) return l;
    if(dp[x][l]>=0) return dp[x][l];

    ll ret = 0;
    if(l==0){
        if(a[x]==0 && b[x]==0){
            (ret += m*dfs(x+1,0)) %= mod;
            (ret += M*dfs(x+1,1)) %= mod;
        }
        else if(a[x]==0){
            (ret += dfs(x+1,0)) %= mod;
            (ret += (m-b[x])*dfs(x+1,1) ) %= mod;
        }
        else if(b[x]==0){
            (ret += dfs(x+1,0)) %= mod;
            (ret += (a[x]-1)*dfs(x+1,1) ) %= mod;
        }
        else{
            if(a[x]==b[x]) (ret += dfs(x+1,0)) %= mod;
            else if(a[x]>b[x]) (ret += dfs(x+1,1)) %= mod;
        }
    }
    else{
        ll mul = 1;
        if(a[x]==0) (mul *= m) %= mod;
        if(b[x]==0) (mul *= m) %= mod;
        (ret += mul*dfs(x+1, 1)) %= mod;
    }

    return dp[x][l] = ret;
}

int main(){
    cin >>n >>m;
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    int zero = 0;
    rep(i,n){
        zero += !a[i];
        zero += !b[i];
    }

    M = (ll)m*(m-1)/2;
    M %= mod;

    memset(dp,-1,sizeof(dp));
    ll ans = dfs(0,0);
    (ans *= mod_inv(mod_pow(m, zero))) %= mod;
    cout << ans << endl;
    return 0;
}
