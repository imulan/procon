#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define mod 998244353

ll N,K;
vector<ll> d,ds;

int main(){
    cin>>N>>K;
    d.resize(N); ds.resize(N);
    rep(i,N){
        cin>>d[i];
        ds[i]=d[i];
    }
    sort(all(ds)); unique(all(ds));
    ll M=ds.size();
    vector<ll> cnt(M,0);
    rep(i,N){
        cnt[lower_bound(all(ds),d[i])-ds.begin()]++;
    }
    
    vector<vector<ll> > dp(M+1,vector<ll>(K+1,0));
    dp[0][0]=1;
    rep(i,M)rep(j,K+1){
        if(j<K&&cnt[i]>0){
            (dp[i+1][j+1]+=dp[i][j]*cnt[i]%mod)%=mod;
        }
        (dp[i+1][j]+=dp[i][j])%=mod;
    }
    cout<<dp[M][K]<<endl;
    
    return 0;
}

