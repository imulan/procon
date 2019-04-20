#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
string s;
ll dp[1050][1050];
ll rec[1050][11][1050];
int bc[1050];

ll isvalid(int f,int len,int bit){
    //printf("%d %d %d\n",f,len,bit);
    if(rec[f][len][bit]!=-2)return rec[f][len][bit];
    ll val=0;
    for(int i=0;i<len;i++){
        val*=10LL;
        if(!(bit>>i & 1)){
            if(s[f+i]=='+')return rec[f][len][bit]=-1;
        }
        int v=s[f+i]-'0';
        if(bit>>i & 1){
            if(len==1 || i>0)v=0;
            else v=1;
        }
        if(v==0 && len>1 && i==0)return rec[f][len][bit]=-1;
        val+=v;
    }
    //printf("%lld\n",val);
    return rec[f][len][bit]=val;
}


ll bk[11];

int main(){
    ll tgt;
    scanf("%lld",&tgt);
    cin >> s;
    int n=s.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=(1LL<<50);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=1;j<=10;j++){
            for(int k=0;k<(1<<j);k++){
                rec[i][j][k]=-2;
            }
        }
    }
    for(int i=0;i<(1<<10);i++){
        bc[i]=__builtin_popcount(i);
        //printf("%d %d\n",i,bc[i]);
    }
    bk[1]=0;
    ll u=10;
    for(int i=2;i<=10;i++){
        bk[i]=u;
        u*=10LL;
    }
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]>(ll)tgt)continue;
            //printf("i=%d j=%d v=%lld\n",i,j,dp[i][j]);
            for(int len=1;len<=10;len++){
                if(j+len>n)break;
                if(j>0 && j+1+len>n)break;
                if(dp[i][j]+bk[len]>tgt)continue;
                for(int bit=0;bit<(1<<len);bit++){
                    ll val=0;
                    if(j==0)val=isvalid(j,len,bit);
                    else{
                        val=isvalid(j+1,len,bit);
                    }
                    if(val==-1)continue;
                    int nc=bc[bit]+i;
                    //printf("a %d %d %d %lld\n",len,bit,nc,val);
                    if(j>0 && s[j]!='+')nc++;
                    if(nc>n)continue;
                    if(j>0)dp[nc][j+len+1]=min(dp[nc][j+len+1],dp[i][j]+val);
                    else{
                        dp[nc][j+len]=min(dp[nc][j+len],dp[i][j]+val);
                    }
                }
            }
        }
        if(dp[i][n]<=(ll)tgt){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
