#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll s,x;
ll dp[42][2];

//下からdigit桁目に注目、繰り上がりの有無
ll rec(int digit, int carry){
  if(dp[digit][carry]>=0) return dp[digit][carry];

  ll ret=0;
  if(digit==41){
    if(carry) return 0;
    else return 1;
  }

  if((x>>digit)&1){
    if((s>>digit)&1){
      if(!carry) ret+=2*rec(digit+1,0);
    }
    else{
      if(carry) ret+=2*rec(digit+1,1);
    }
  }
  else{
    if((s>>digit)&1){
      if(carry) ret+=rec(digit+1,0)+rec(digit+1,1);
    }
    else{
      if(!carry) ret+=rec(digit+1,0)+rec(digit+1,1);

    }
  }

  return dp[digit][carry]=ret;
}

int main(int argc, char const *argv[]) {
  cin >>s >>x;
  memset(dp,-1,sizeof(dp));

  ll ans=rec(0,0);
  if(s==x){//(0,s)と(s,0)を除外
    ans-=2;
  }

  std::cout << ans << std::endl;
  return 0;
}
