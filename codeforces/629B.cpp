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
  long i;

  long n;
  cin >>n;

  long m[370]={0};
  long f[370]={0};

  rep(i,n){
    char sex;
    int a,b;
    scanf(" %c %d %d", &sex,&a,&b);

    if(sex=='M'){
      ++m[a];
      --m[b+1];
    }
    else{
      ++f[a];
      --f[b+1];
    }
  }

  rep(i,370-1){
    m[i+1]+=m[i];
    f[i+1]+=f[i];
  }

  long ans=0;
  for(i=1; i<=366; ++i){
    //printf("%ld: %ld,%ld\n",i,m[i],f[i]);
    ans=max(ans,2*min(m[i],f[i]));
  }

  std::cout << ans << std::endl;
  return 0;
}
