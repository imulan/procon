#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const long mod=(long)1e9+7;

long m,d;
string a,b;

//現在注目している位置、mでの剰余、最小値より大きいことが確定しているか、最大値より小さいことが確定しているか
long dp[2001][2001][2][2];

long rec(long now, long r, int small, int large){

  if(dp[now][r][small][large]>=0)
    return dp[now][r][small][large];

  long ret=0;
  if(now==a.size()) ret=(r==0);
  else{
    for(int i=0; i<=9; ++i){
      //d以外を選ぶ
      if(now%2==0 && i==d) continue;
      //dしかダメ
      if(now%2==1 && i!=d) continue;

      //まだaより大きいことが確定していないのにaより小さい値を選ぶのはダメ
      if(small==0 && i<a[now]-'0') continue;
      //まだbより小さいことが確定していないのにbより大きい値を選ぶのはダメ
      if(large==0 && b[now]-'0'<i) continue;

      ret+=rec(now+1, (r*10+i)%m, small||a[now]-'0'<i, large||i<b[now]-'0');
      ret%=mod;
    }
  }

  return dp[now][r][small][large]=ret;
}

int main(int argc, char const *argv[]) {
  cin >>m >>d;
  cin >>a >>b;

  memset(dp,-1,sizeof(dp));
  std::cout << rec(0,0,0,0) << std::endl;
  return 0;
}
