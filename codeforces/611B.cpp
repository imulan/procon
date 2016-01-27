#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  ll a,b;
  cin >>a >>b;

  --a; //1減らしておく、1~aと1~bの２つの範囲で個数を求め、引き算する

  ll p2[63]={0};
  p2[0]=1;
  for(ll i=1; i<63; ++i){
    p2[i]=p2[i-1]*2;
    //cout << "p2["<< i << "]=" << p2[i] << endl;
  }

  ll bit_a=0, bit_b=0;
  while(p2[bit_a+1]<=a) ++bit_a;
  while(p2[bit_b+1]<=b) ++bit_b;

  //数える
  //まず、自身の数のビット数未満の部分は全て含まれるのでカウント
  ll na=(ll)(bit_a-1)*bit_a/2;
  ll nb=(ll)(bit_b-1)*bit_b/2;

  //次に、自分と同じビット数の数がどこまで含まれるか調べる
  //まず1~a
  ll tp;
  for(ll i=0; i<bit_a; ++i){
    tp=((ll)1<<(bit_a+1))-1;
    tp -= ((ll)1<<i);
    if(tp<=a) ++na;
  }
  //1~b
  for(ll i=0; i<bit_b; ++i){
    tp=((ll)1<<(bit_b+1))-1;
    tp -= ((ll)1<<i);
    if(tp<=b) ++nb;
  }

  cout << nb-na << endl;

  return 0;
}
