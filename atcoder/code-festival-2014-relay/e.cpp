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

  int h,w;
  scanf(" %d %d",&h,&w);
  int ans=0;
  rep(i,h*w){
    char c;
    scanf(" %c",&c);
    if(c!='.') ans+=c-'0';
  }
  printf("%d\n",ans);
  return 0;}
