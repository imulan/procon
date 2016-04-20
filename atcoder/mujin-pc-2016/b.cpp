#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int ab(int p){
  return (p>0)?p:-p;
}

bool tri(int a, int b, int c){
  return (a+b)>c && (b+c)>a && (c+a)>b;
}

int main(int argc, char const *argv[]) {
  int a,b,c;
  cin >>a >>b >>c;

  int x=a+b+c;

  int y;
  if(tri(a,b,c)) y=0;
  else y=min(ab(a-b+c),min(ab(a-b-c),ab(a+b-c)));

  //printf("x=%d, y=%d\n",x,y);
  printf("%.10lf\n", acos(-1.0)*(x*x-y*y));
  return 0;
}
