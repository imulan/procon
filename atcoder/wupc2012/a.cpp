#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

//1/1から何日目
int d(int m, int d){
  int ret=0;

  int a=1;
  while(a<m){
    if(a==2) ret+=29;
    else if(a==4 || a==6 || a==9 || a==11) ret+=30;
    else ret+=31;
    ++a;
  }
  ret+=d-1;

  return ret;
}

int main(int argc, char const *argv[]) {
  int ma,da,mb,db;
  cin >>ma >>da >>mb >>db;
  cout << d(mb,db)-d(ma,da) << endl;
  return 0;
}
