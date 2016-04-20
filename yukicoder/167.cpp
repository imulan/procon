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
  string n,m;
  cin >>n >>m;

  int ans=-1;
  if(m=="0") ans=1;
  else{
    int a=n[n.size()-1]-'0';
    int b;
    if(m.size()<3) b=atoi(m.c_str());
    else b=atoi(m.substr(m.size()-2,2).c_str());

    //printf("%d %d\n",a,b);

    int ct=0;
    ans=a;
    while(ct<(b-1+4)%4){
      ++ct;
      ans*=a;
      ans%=10;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
