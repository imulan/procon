#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  long n;
  cin >> n;

  long now=0;
  long long ans=0;
  for(long i=0; i<n; ++i){ //i番目の要素に注目
    long b;
    cin >> b;

    if(now<b){ //今より大きかったらそこまで足す操作をする
      ans += b-now;
      now = b;
    }
    else if(b<now){ //今より小さかったらそこまで引く
      ans += now-b;
      now = b;
    }
  }
  cout << ans << endl;
}
