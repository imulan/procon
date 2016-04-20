#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int l=0,r=1000000001;
  int mid;
  while(l<r){
    mid=(l+r)/2;

    bool end=(r-l<=1);
    if(end) mid=r;

    printf("? %d\n",mid);
    cout <<flush;

    int ans;
    cin >>ans;

    if(end){
      if(!ans) mid=l;
      break;
    }
    
    if(ans) l=mid;
    else r=mid;
  }
  printf("! %d\n",mid);
  cout <<flush;
  return 0;
}
