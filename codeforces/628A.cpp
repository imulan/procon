#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i;

  long n,b,p;
  cin >>n >>b >>p;

  long x=0,y=n*p;

  int pw[10];
  pw[0]=1;
  rep(i,9) pw[i+1]=pw[i]*2;

  while(n>1){
    int k=0;
    while(pw[k+1]<=n) ++k;
    //printf("n:%ld, k:%d, pw:%d\n",n,k,pw[k]);

    //このラウンドの試合で必要になるボトル
    x+=(2*b+1)*pw[k]/2;
    //脱落する人数
    n-=pw[k]/2;
  }

  printf("%ld %ld\n",x,y);
  return 0;
}
