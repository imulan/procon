#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll dp[6][60];

int main(){
    ll n;
    scanf("%lld",&n);
    dp[0][0]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<40;j++){
            if(i%2==0){
                for(int k=0;k<5;k++){
                    dp[i+1][j+k]+=dp[i][j];
                }
            }else{
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j]+=dp[i][j];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=min(59LL,n);i++){
        ans+=dp[5][i];
    }
    printf("%lld\n",ans);
    return 0;
}
