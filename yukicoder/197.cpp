#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  string a,b;
  long n;

  cin >>b >>n >>a;

  int i;
  //before
  int o_b=0,x_b=0;
  //after
  int o_a=0,x_a=0;
  rep(i,3){
    if(b[i]=='o') ++o_b;
    else ++x_b;

    if(a[i]=='o') ++o_a;
    else ++x_a;
  }

  bool v=true;
  if(o_b!=o_a) v=false;
  else{
    if(n==1){
      string t1=b,t2=b;
      swap(t1[0],t1[1]);
      swap(t2[1],t2[2]);
      v=(a==t1)|(a==t2);
    }
    else if(n==0) v=(b==a);
  }

  string r="SUCCESS";
  if(v) r="FAILURE";
  std::cout << r << std::endl;
  return 0;
}
