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
  int d;
  cin >>d;
  std::vector<int> a(d+1);
  rep(i,d+1) cin >>a[i];

  int a0=a[0];
  int a1=0,a_1=0;

  rep(i,d+1) a1+=a[i];
  int r=1;
  rep(i,d+1){
    a_1+=r*a[i];
    r*=-1;
  }

  //printf("a1:%d. a_1:%d\n",a1, a_1);

  int u=a0;
  int s=(a1+a_1)/2-u;
  int t=(a1-a_1)/2;

  if(s!=0) printf("2\n%d %d %d\n",u,t,s);
  else if(t!=0) printf("1\n%d %d\n",u,t);
  else printf("0\n%d\n",u);

  return 0;
}
