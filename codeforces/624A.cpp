#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  long d,L,v1,v2;
  cin >>d >>L >>v1 >>v2;
  printf("%.10lf\n",(double)(L-d)/(v1+v2));
  return 0;
}
