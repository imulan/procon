#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)a;(i)<(int)(b);++(i))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cerr<<#x<<"="<<x<<endl

long double cnt[44][44];
long double dp[44][44];

long double calc(int m,int n,int x){
    long double p1=(long double)m/(long double)(m+n);
    long double p2=(long double)n/(long double)(m+n);

    rep(i,44)rep(j,44)dp[i][j]=cnt[i][j]=0;
    cnt[0][0]=1;
    rep(h,x){
        rep(l,h+1){
            int r=h-l;
            long double d=pow(p1,l)*pow(p2,r);
            {
                cnt[l+1][r]+=cnt[l][r];
                dp[l+1][r]+=dp[l][r];
            }
            {
                cnt[l][r+1]+=cnt[l][r];
                dp[l][r+1]+=dp[l][r]+d*p1*cnt[l][r];
            }
        }
    }

    long double res=0;
    rep(l,x+1){
        int r=x-l;
        res+=pow(p1,l)*pow(p2,r)*(dp[l][r]+cnt[l][r]*pow(p1,l)*pow(p2,r));
    }
    return res;
}

int main(){
    int M,N,X,K,L,Y;
    cin>>M>>N>>X>>K>>L>>Y;
    long double a=calc(N,M,X);
    long double b=calc(L,K,Y);
    printf("%.10Lf\n",a*b);

    return 0;
}
