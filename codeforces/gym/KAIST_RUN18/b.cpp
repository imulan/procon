#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;
string str;
bool dp[10005][10005];
vector<int> G[30];
int ch[10005];

int main(){
    scanf("%d",&n);
    cin >> str;
    memset(dp,false,sizeof(dp));
    int ans=0;
    int len=0;
    for(int i=0;i<n;i++){
        if(i>0)printf(" ");
        if(str[i]=='-'){
            len--;
            int v=ch[len];
            dp[len][len+1]=false;
            ans--;
            for(int j=0;j+1<G[v].size();j++){
                int pos=G[v][j];
                if(pos+1==len){
                    dp[pos][len+1]=false;
                    ans--;
                }else{
                    if(dp[pos][len+1])ans--;
                    dp[pos][len+1]=false;
                }
            }
            G[v].pop_back();
        }else{
            int v=str[i]-'a';
            G[v].push_back(len);
            ch[len]=v;
            dp[len][len+1]=true;
            ans++;
            for(int j=0;j+1<G[v].size();j++){
                int pos=G[v][j];
                if(pos+1==len){
                    dp[pos][len+1]=true;
                    ans++;
                }else{
                    dp[pos][len+1]=dp[pos+1][len];
                    if(dp[pos][len+1])ans++;
                }
            }
            len++;
        }
        printf("%d",ans);
    }
    printf("\n");
    return 0;
}
