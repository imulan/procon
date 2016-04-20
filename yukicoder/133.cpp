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
  int n;
  cin >>n;
  std::vector<int> a(n),b(n);
  rep(i,n) cin >>a[i];
  rep(i,n) cin >>b[i];

  int f=1;
  for(int i=2; i<=n; ++i) f*=i;
  int all=f*f, ct=0;

  //next_permutationはソートされた列にしか全部回せない
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  do {
    do {
      int a_win=0,b_win=0;
      rep(i,n){
        if(a[i]>b[i]) ++a_win;
        else if(a[i]<b[i]) ++b_win;
      }
      if(a_win>b_win) ++ct;
    } while(next_permutation(b.begin(),b.end()));
  } while(next_permutation(a.begin(),a.end()));

  printf("%.10lf\n", (double)ct/all);
  return 0;
}
