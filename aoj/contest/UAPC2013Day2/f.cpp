#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007LL

typedef pair<int,int> P;

int r,c;
int a[6][6];
int b[6][6];
vector<P> pos[6][6];
ll dp[2][1<<20];
int dx[6]={0,0,1,1,-1,-1};
int dy[6]={-1,1,0,1,0,1};

bool check(int y,int x){
    int sum=0;
    for(int i=0;i<6;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<c && ny>=0 && ny<r){
            sum+=b[ny][nx];
        }
    }
    return sum==a[y][x];
}

bool valid(int y,int x,int bit,int num){
    memset(b,0,sizeof(b));
    b[y][x]=num;
    for(int i=0;i<(int)pos[y][x].size();i++){
        int v=((bit>>(i*2))&1)+((bit>>(i*2+1))&1)*2;
        b[pos[y][x][i].fi][pos[y][x][i].se]=v;
    }
    if(y==(r-1) && x==(c-1) && a[y][x]>0){
        if(!check(y,x))return false;
    }
    if(y==(r-1) && x>0 && a[y][x-1]>0){
        if(!check(y,x-1))return false;
    }
    if(y>0 && x==(c-1) && a[y-1][x]>0){
        if(!check(y-1,x))return false;
    }
    if(y>0 && x>0 && a[y-1][x-1]>0){
        if(!check(y-1,x-1))return false;
    }
    return true;
}

int calcbit(int y,int x,int bit,int val){
    int ans=0;
    if(y==(r-1) && x==(c-1))return 0;
    int nx=(x+1)%c;
    int ny=y+(x+1)/c;
    for(int i=0;i<pos[y][x].size();i++){
        for(int j=0;j<pos[ny][nx].size();j++){
            if(pos[y][x][i]==pos[ny][nx][j]){
                int v=((bit>>(i*2))&1)+((bit>>(i*2+1))&1)*2;
                ans+=v<<(j*2);
            }
        }
    }
    for(int i=0;i<pos[ny][nx].size();i++){
        if(pos[ny][nx][i]==P(y,x))ans+=val<<(i*2);
    }
    return ans;
}

int main(){
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0){
                for(int k=0;k<j;k++){
                    if(a[0][k]==0)pos[i][j].push_back(P(0,k));
                }
            }else{
                for(int k=0;k<j;k++){
                    if(a[i][k]==0)pos[i][j].push_back(P(i,k));
                    else{
                        if(k>0 && a[i][k-1]==0)pos[i][j].push_back(P(i,k-1));
                        if(k+1<c && a[i][k+1]==0 && (k+1)!=j)pos[i][j].push_back(P(i,k+1));
                        if(a[i-1][k]==0)pos[i][j].push_back(P(i-1,k));
                    }
                }
                for(int k=max(0,j-1);k<c;k++){
                    if(a[i-1][k]==0)pos[i][j].push_back(P(i-1,k));
                    else{
                        if(k>0 && a[i-1][k-1]==0)pos[i][j].push_back(P(i-1,k-1));
                        if(k+1<c && a[i-1][k+1]==0)pos[i][j].push_back(P(i-1,k+1));
                        if(i>1 && a[i-2][k]==0)pos[i][j].push_back(P(i-2,k));
                    }
                }
            }
            sort(pos[i][j].begin(),pos[i][j].end());
            pos[i][j].erase(unique(pos[i][j].begin(),pos[i][j].end()),pos[i][j].end());
        }
    }
    int cur=0,nxt=1;
    dp[0][0]=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int bit=0;bit<(1<<(2*(int)pos[i][j].size()));bit++){
                int loop=4;
                if(a[i][j]>0)loop=1;
                for(int k=0;k<loop;k++){
                    if(valid(i,j,bit,k)){
                        int nbit=calcbit(i,j,bit,k);
                        dp[nxt][nbit]+=dp[cur][bit];
                        dp[nxt][nbit]%=MOD;
                    }
                }
            }
            swap(cur,nxt);
            memset(dp[nxt],0,sizeof(dp[nxt]));
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<2*c);i++){
        ans=(ans+dp[cur][i])%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
