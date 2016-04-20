#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int conv(int month, int day){
  int ret=0;
  int m=1;
  while(m<month){
    if(m==2) ret+=29;
    else if(m==4||m==6||m==9||m==11) ret+=30;
    else ret+=31;
    ++m;
  }

  return ret+day;
}

int main(int argc, char const *argv[]) {
  int i;

  int n;
  cin >>n;

  bool r[367];
  fill(r,r+367,false);

  //日曜日と土曜日
  for(i=1; i<=366; i+=7) r[i]=true;
  for(i=7; i<=366; i+=7) r[i]=true;

  rep(i,n){
    int m,d;
    scanf(" %d/%d",&m,&d);

    int t=conv(m,d);
    while(t<=365 && r[t]) ++t;
    r[t]=true;
  }

  int ans=0;
  int ct=0;
  for(i=1; i<=366; ++i){
    if(r[i]) ++ct;
    else ct=0;
    ans=max(ans,ct);
  }

  std::cout << ans << std::endl;
  return 0;
}
