#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

struct RollingHash{
    static const int MD = 2;
    static const vector<ll> hash_base, hash_mod;

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        rep(i,MD){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    // 1-index
    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    vector<ll> calc(int l, int r){
        vector<ll> ret(MD);
        rep(i,MD) ret[i]=hash_value(l-1,r,i);
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007};

inline int small(const string &x, const string &y)
{
    int n=x.size();
    rep(i,n)
    {
        if(x[i]<y[i]) return 1;
        else if(x[i]>y[i]) return 0;
    }
    return 1;
}

const int V=1000000;
ll pw[V+1];

int n,K;
string N,M;

int num[V];
ll dp[V][2];
ll dfs(int d, int s)
{
    if(d==n) return 1;
    if(dp[d][s]>=0) return dp[d][s];

    ll ret=0;
    if(num[d]==-1)
    {
        // 自由に選べる
        int lim=9;
        if(s==0) lim=N[d]-'0';
        rep(i,lim+1) (ret+=dfs(d+1,s|(i<N[d]-'0')))%=mod;
    }
    else
    {
        // 選べる数は決まっている
        int lim=N[d]-'0';
        if(s==1 || (s==0 && num[d]<=lim)) (ret+=dfs(d+1,s|(num[d]<lim)))%=mod;
    }

    return dp[d][s]=ret;
}

int main()
{
    pw[0]=1;
    for(int i=1; i<=V; ++i) pw[i] = (pw[i-1]*10)%mod;

    cin >>N >>M;
    n = N.size();
    K = M.size();

    ll ans = 0;

    RollingHash h(M);
    for(int i=1; i<=K; ++i)
    {
        int L = 2*K - (K+1-i);
        if(!h.match(1,K+1-i,i,K)) continue;

        if(L<n) ++ans;
        else if(L==n)
        {
            string t = M+M.substr(K+1-i);
            ans += small(t,N);
            break;
        }
    }
    if(2*K<=n)
    {
        int blank = n-2*K;
        rep(i,blank) (ans+=pw[i])%=mod;

        memset(num,-1,sizeof(num));
        rep(i,K) num[i] = M[i]-'0';
        rep(i,K) num[n-K+i] = M[i]-'0';

        memset(dp,-1,sizeof(dp));
        (ans+=dfs(1,num[0]<N[0]-'0'))%=mod;
    }

    cout << ans << endl;
    return 0;
}
