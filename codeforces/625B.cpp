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
  string g,p;
  cin >>g >>p;

  long ng=0;
  long ans=0;

  long n=g.size();
  long p_len=p.size();

  while(1){
    //printf(" ng=%ld\n", ng);
    if(ng+p_len>n) break;

    if(p[0]==g[ng]){//先頭の文字が一致する時、判定
      if(g.substr(ng,p_len)==p){
        ++ans;
        ng+=p_len;
      }
      else ++ng;
    }
    else ++ng;
  }

  std::cout << ans << std::endl;
  return 0;
}
