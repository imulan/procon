#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int dp[200][200][200];
//残り個数で何が作れるか r4g2b1
int rec(int r,int g,int b){
  if(dp[r][g][b]>=0) return dp[r][g][b];

  int ret=0;
  if(r+g+b==1){
    if(r) ret=4;
    if(g) ret=2;
    if(b) ret=1;
  }
  else{
    if(r>=2) ret|=rec(r-1,g,b);
    if(g>=2) ret|=rec(r,g-1,b);
    if(b>=2) ret|=rec(r,g,b-1);
    if(r>=1&&g>=1) ret|=rec(r-1,g-1,b+1);
    if(r>=1&&b>=1) ret|=rec(r-1,g+1,b-1);
    if(g>=1&&b>=1) ret|=rec(r+1,g-1,b-1);
  }

  return dp[r][g][b]=ret;
}

int main(int argc, char const *argv[]) {
  int i;

  int n;
  string s;
  cin >>n >>s;

  int r=0,g=0,b=0;
  rep(i,n){
    if(s[i]=='R') ++r;
    else if(s[i]=='G') ++g;
    else ++b;
  }

  memset(dp,-1,sizeof(dp));
  int ret=rec(r,g,b);

  //BGR
  if(ret&1) printf("B");
  if(ret&2) printf("G");
  if(ret&4) printf("R");
  printf("\n");
  return 0;
}
