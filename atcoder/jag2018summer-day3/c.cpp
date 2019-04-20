#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define maxch(x,y) x=max(x,y)

#define INF 1e16

ll C,N,M;
ll w[10001],p[10001];
ll dp[2][10001];

int main(){
    cin>>C>>N>>M;

    rep(i,N)cin>>w[i]>>p[i];

    int crt=0,nxt=1;
    rep(j,C+1)dp[crt][j]=-INF;
    dp[crt][0]=0;
    rep(i,N){
        rep(j,C+1)dp[nxt][j]=-INF;
        rep(j,C+1){
            if(j+w[i]<=C)maxch(dp[nxt][j+w[i]],dp[crt][j]+p[i]);
            maxch(dp[nxt][j],dp[crt][j]);
        }
        swap(crt,nxt);
    }

    rep(i,C)maxch(dp[crt][i+1],dp[crt][i]);

    repl(k,1,M+1){
        cout<<(dp[crt][C/k])*k<<endl;
    }

    return 0;
}
