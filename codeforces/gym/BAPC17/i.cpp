#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()

int dp[105][105][2];
bool used[105][105][2];
int n,m;

int solve(int y,int x,int c){
    if(y==0 || x==m)return 0;
    if(used[y][x][c])return dp[y][x][c];
    used[y][x][c]=true;
    if(c==0){
        int ans=-100000;
        for(int i=x;i<m;i++){
            int val=0;
            if((i-x)%2==0 && y%2==1){
                if(x%2==0)val=1;
                else val=-1;
            }
            ans=max(ans,val+solve(y,i+1,1));
        }
        //printf("%d %d %d %d\n",y,x,c,ans);
        return (dp[y][x][c]=ans);
    }else{
        int ans=100000;
        for(int i=0;i<y;i++){
            int val=0;
            if((y-i)%2==1 && (m-x)%2==1){
                if((x+i)%2==0)val=-1;
                else val=1;
            }
            ans=min(ans,val+solve(i,x,1));
        }
        //printf("%d %d %d %d\n",y,x,c,ans);
        return (dp[y][x][c]=ans);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    printf("%d\n",solve(n,0,0));
    return 0;
}
