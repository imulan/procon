#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int n,k;
  cin >>n >>k;

  int e; //敵の入力

  if(n-1<=k){//初ターンで勝てる
    cout << n-1 << endl;
    cout <<flush;

    cin >>e;
  }
  else{
    //初手を取るべきか否か
    bool first=true;
    if(n%(k+1)==1) first=false;

    //毎回自分の出力を割った余りはrになるようにする
    int r=n%(k+1);
    if(r==0) r=k+1;
    --r;

    cout << r << endl;
    cout <<flush;

    while(1){
      cin >>e;
      if(e>=n) break;

      int q=e/(k+1);
      int rr=e%(k+1);

      int m=e;
      if(rr<r){
        m+=r-rr;
      }
      else if(rr>r){
        m+=r+k+1-rr;
      }

      cout << m << endl;
      cout <<flush;
    }

  }

  return 0;
}
