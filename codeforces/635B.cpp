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

  vector<long> a,b;
  rep(i,n){
    long t;
    scanf(" %ld",&t);
    if(t!=0) a.pb(t);
  }
  rep(i,n){
    long t;
    scanf(" %ld",&t);
    if(t!=0) b.pb(t);
  }

  long st=0;
  while(a[0]!=b[st]) ++st;

  bool valid=true;
  rep(i,n-1){
    if(a[i]!=b[(st+i)%(n-1)]){
      valid=false;
      break;
    }
  }

  string ans="NO";
  if(valid) ans="YES";
  std::cout << ans << std::endl;
  return 0;
}
