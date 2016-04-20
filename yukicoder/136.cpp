#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int N=100000;

int main(int argc, char const *argv[]) {
  int i,j;

  bool prime[N+1];
  rep(i,N+1) prime[i]=true;
  prime[0]=prime[1]=false;
  for(i=2;i<=N;++i){
    if(prime[i])
      for(j=2;i*j<=N;++j) prime[i*j]=false;
  }

  vector<int> p;
  rep(i,N) if(prime[i]) p.pb(i);

  int n,k;
  cin >>n >>k;

  int r=1;
  rep(i,p.size()){
    if(n<=p[i]) break;

    if(n%p[i]==0){
      r=n/p[i];
      break;
    }
  }

  std::cout << r << std::endl;
  return 0;
}
