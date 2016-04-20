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

  int n,m;
  cin >>n >>m;

  int d[16][16]={0};
   rep(i,m){
    int a,b;
    cin >>a >>b;
    --a; --b;
    d[a][b]=d[b][a]=1;
  }




  return 0;
}
