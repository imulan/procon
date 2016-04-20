#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  long n,k;
  cin >>n >>k;

  long table[500][500]={0};
  long i,j;

  //(n-1)~(k-1)番目まで順にn^2から順に上から下に詰める
  long now=n*n;
  rep(i,n){
    for(j=n-1; j>=k-1; --j){
      table[i][j]=now;
      --now;
    }
  }
  //(k-2)~0番目も同様に順に上から下に詰める
  rep(i,n){
    for(j=k-2; j>=0; --j){
      table[i][j]=now;
      --now;
    }
  }

  long sum=0;
  rep(i,n) sum+=table[i][k-1];

  printf("%ld\n",sum);
  rep(i,n){
    rep(j,n){
      if(j) printf(" ");
      printf("%ld",table[i][j]);
    }
    printf("\n");
  }
  return 0;
}
