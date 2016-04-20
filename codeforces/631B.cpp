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
  long i,j;

  long n,m,k;
  cin >>n >>m >>k;

  //色、更新時間(遅いほうが選ばれる)
  //横
  vector<pair<long,long>> row(n);
  rep(i,n){
    row[i].fi=0;
    row[i].sc=-1;
  }
  //縦
  vector<pair<long,long>> col(m);
  rep(i,m){
    col[i].fi=0;
    col[i].sc=-1;
  }

  rep(i,k){
    int op;
    long p,a;
    scanf(" %d %ld %ld",&op,&p,&a);
    --p;
    if(op==1){//r行目を色aに
      row[p].fi=a;
      row[p].sc=i;
    }
    else{//c列目を色aに
      col[p].fi=a;
      col[p].sc=i;
    }
  }

  rep(i,n){
    rep(j,m){
      long ret=-1;
      if(row[i].sc>col[j].sc) ret=row[i].fi;
      else ret=col[j].fi;

      if(j) printf(" ");
      printf("%ld",ret);
    }
    printf("\n");
  }

  return 0;
}
