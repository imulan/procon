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

long n,m;
string s;

//極小値、oがこの値以上じゃないとsは使えない
long lmin=1000000;
//最終的にsを使った時の増減
long ssum=0;

ll dp[2010][2010][2];

//n-m+1個のパーツを並べる
//現在注目している位置、開きが多い数、既にsを使ったか
ll rec(long now, long o, int used){
  if(dp[now][o][used]>=0) return dp[now][o][used];

  ll ret=0;
  if(now==n-m+1){//おわり
    ret=(o==0);
  }
  else if(now==n-m && used==0){//sを使わないといけない
    if(o>=-lmin){
      ret+=rec(now+1,o+ssum,1);
      ret%=mod;
    }
    else ret=0;
  }
  else{
    //(
    if(o<2005){
      ret+=rec(now+1,o+1,used);
      ret%=mod;
    }
    //)
    if(o>0){
      ret+=rec(now+1,o-1,used);
      ret%=mod;
    }

    //s
    if(used==0 && o>=-lmin && o+ssum<2005){
      ret+=rec(now+1,o+ssum,1);
      ret%=mod;
    }
  }

  ret%=mod;
  return dp[now][o][used]=ret;
}

int main(int argc, char const *argv[]) {
  long i;

  cin >>n >>m;
  cin >>s;

  bool valid=true;
  //そもそも買ったパーツの時点で可能かどうか判定
  rep(i,m){
    if(s[i]=='(') ++ssum;
    else --ssum;
    lmin=min(lmin,ssum);
  }

  //printf("lmin=%ld, ssum=%ld\n",lmin,ssum);

  //どう頑張ってもとりもどせない
  if(ssum>n-m || ssum<-(n-m)) valid=false;

  //答え
  if(valid){
    memset(dp,-1,sizeof(dp));
    std::cout << rec(0,0,0) << std::endl;
  }
  else printf("0\n");

  return 0;
}
