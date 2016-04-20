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

  int a[10]={20104,20063,19892,20011,19874,20199,19898,20163,19956,19841};

  int i;

  string s;
  cin >>s;

  int ct[10]={0};
  ct[0]=-1;
  s[1]='0';
  rep(i,s.size()) ++ct[s[i]-'0'];

  int x=-1,y=-1;
  rep(i,10){
    if(ct[i]>a[i]) x=i;
    if(ct[i]<a[i]) y=i;
  }

  printf("%d %d\n",x,y);
  return 0;
}
