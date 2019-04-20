#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define MOD 1000000009LL
typedef long long ll;

ll dp[1000005][4];
int num[1000005][3];
int len[3];

void update(int pos,int bit,int i){
    ll cv=dp[pos][bit];
    if(num[pos][0]==-1 && num[pos][2]==-1){
        if(bit==3){
            dp[pos+1][bit]+=cv*26LL*26LL;
        }else if(bit==2){
            dp[pos+1][bit]+=cv*26LL;
            if(i>=1)dp[pos+1][bit|1]+=cv*26LL*(i-1LL);
        }else if(bit==1){
            if(i>=1)dp[pos+1][bit]+=cv*26LL;
            dp[pos+1][bit|2]+=cv*26LL*(26LL-i);
        }else{
            if(i>=1)dp[pos+1][bit|3]+=cv*(i-1)*(26-i);
            dp[pos+1][bit|2]+=cv*(26-i);
            if(i>=1)dp[pos+1][bit|1]+=cv*(i-1);
            if(i>=1)dp[pos+1][bit]+=cv;
       }
    }else if(num[pos][0]==-1){
        int nbit=bit;
        if(i>num[pos][2] && ((bit&2)==0))return;
        if(i<num[pos][2])nbit|=2;
        if(i>=1)dp[pos+1][nbit|1]+=cv*(i-1);
        if(i>=1)dp[pos+1][nbit]+=cv;
        if((bit&1)!=0){
            dp[pos+1][nbit]+=cv*(26-i);
        }
    }else if(num[pos][2]==-1){
        int nbit=bit;
        if(i<num[pos][0] && ((bit&1)==0))return;
        if(i>num[pos][0])nbit|=1;
        dp[pos+1][nbit|2]+=cv*(26-i);
        if(i>=1)dp[pos+1][nbit]+=cv;
        if((bit&2)!=0){
            if(i>=1)dp[pos+1][nbit]+=cv*(i-1);
        }
    }else{
        int nbit=bit;
        if(i>num[pos][2] && ((bit&2)==0))return;
        if(i<num[pos][2])nbit|=2;
        if(i<num[pos][0] && ((bit&1)==0))return;
        if(i>num[pos][0])nbit|=1;
        dp[pos+1][nbit]+=cv;
    }
}

void solve(){
    int n=0;
    for(int i=0;i<3;i++){
        string str;
        cin >> str;
        len[i]=str.size();
        n=max(len[i],n);
        for(int j=0;j<len[i];j++){
            if(str[j]=='?')num[j][i]=-1;
            else num[j][i]=(str[j]-'a')+1;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        //printf("i%d %d %d %d\n",i,num[i][0],num[i][1],num[i][2]);
        for(int j=0;j<4;j++){
            //printf("%d %d %lld\n",i,j,dp[i][j]);
            if(num[i][1]==-1){
                for(int k=1;k<=26;k++){
                    update(i,j,k);
                }
            }else{
                update(i,j,num[i][1]);
            }
            for(int k=0;k<4;k++){
                dp[i+1][k]%=MOD;
            }
        }
    }
    ll ans=0;
    for(int i=3;i<4;i++){
        ans+=dp[n][i];
    }
    ans%=MOD;
    printf("%lld\n",ans);
    for(int i=0;i<3;i++){
        for(int j=0;j<len[i];j++){
            num[j][i]=0;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=0;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        solve();
    }
    return 0;
}

