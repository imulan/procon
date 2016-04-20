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
  long n,m;
  cin >>n >>m;

  //twos,threes
  long tw=6*((n-1)/2)+(((n-1)%2==0)?2:4);
  long th=6*(m-1)+3;
  if(n==0) tw=0;
  if(m==0) th=0;
  //printf("tw:%ld th%ld\n",tw,th);

  long now=6;
  while(1){
    if(max(tw,th)<now) break;

    if(th>3 && tw<th){
      th-=6;
      now+=6;
    }
    else if(tw>2 && tw>th){
      tw-=2;
      if(tw%6==0) tw-=2;
      now+=6;
    }

    //printf("tw:%ld th%ld, now:%ld\n",tw,th,now);
  }

  std::cout << max(now-6,max(th,tw)) << std::endl;
  return 0;
}
