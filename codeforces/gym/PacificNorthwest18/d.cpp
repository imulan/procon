#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define mod 1000000009

ll K,B;

int main(){
    cin>>K>>B;

    vector<ll> m(B,0);
    m[0]=1;
    repl(i,1,B)m[i]=m[i-1]*2%K;
    vector<vector<ll> > dp(B+1,vector<ll>(K,0)),sum(B+1,vector<ll>(K,0));
    dp[0][0]=1;
    rep(i,B)rep(j,K){
        (dp[i+1][j]+=dp[i][j])%=mod;
        (dp[i+1][(j+m[B-1-i])%K]+=dp[i][j])%=mod;
        (sum[i+1][j]+=sum[i][j])%=mod;
        (sum[i+1][(j+m[B-1-i])%K]+=sum[i][j]+dp[i][j])%=mod;
    }
    cout<<sum[B][0]<<endl;
    
    return 0;
}

