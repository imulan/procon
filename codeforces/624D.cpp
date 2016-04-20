#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const ll INF = 3000000000000000000LL;

//dp[今注目している要素][除去区間が 0:まだ始まっていない/1:始まっている/2:もう終わった]
ll dp[1000001][3];

//素因数を返す
void pf(long a, set<long> &s){
  long i;

  for(i=2; i*i<=a; ++i){
    if(a%i==0){
      s.insert(i);
      while(a%i==0) a/=i;
    }
  }

  if(a>1) s.insert(a);
}


int main(int argc, char const *argv[]) {
  long i,j;

  long n;
  ll A,B;
  cin >>n >>A >>B;
  std::vector<long> a(n);
  rep(i,n) scanf(" %ld",&a[i]);

  set<long> p;
  //まずGCDの候補になる値を列挙しておく
  pf(a[0]-1,p);
  pf(a[0]  ,p);
  pf(a[0]+1,p);
  pf(a[n-1]-1,p);
  pf(a[n-1]  ,p);
  pf(a[n-1]+1,p);

  ll ans=INF;
  each(it,p){//各要素に対して
    //cout << *it << endl;
    int d = *it;

    //初期化
    rep(i,3) dp[0][i]=0;

    //dpを更新していく
    rep(i,n){
      //このxの値によって場合分け
      long x=a[i]%d;
      if(x==0){
        //そのまま
        dp[i+1][0]=dp[i][0];
        //次から開く、もしくは開いている区間の継続
        dp[i+1][1]=min(dp[i][0],dp[i][1]+A);
        //次で閉じる、または既に閉じている
        dp[i+1][2]=min(dp[i][1],dp[i][2]);
      }
      else if(x==1 || x==d-1){
        //区間を開かないなら値を変更するしか無い
        dp[i+1][0]=dp[i][0]+B;
        //今注目している値を変更して次から開く、もしくは開いている区間の継続
        dp[i+1][1]=min(dp[i][0]+B,dp[i][1]+A);
        //ここで閉じて値を変更する、もしくは既に閉じているので値を変更する
        dp[i+1][2]=min(dp[i][1]+B,dp[i][2]+B);
      }
      else{
        //絶対に区間をひらかないといけない
        dp[i+1][0]=INF;
        //区間を開いておく
        dp[i+1][1]=min(dp[i][0],dp[i][1])+A;
        //列の末尾で閉じる
        dp[i+1][2]=dp[i+1][1];
      }
    }

    ll tmp=INF;
    rep(i,3) tmp=min(tmp,dp[n][i]);
    ans=min(ans,tmp);
  }

  std::cout << ans << std::endl;
  return 0;
}
