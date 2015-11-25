#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  long n, x1, x2;
  long k[100000], b[100000];

  cin >> n;
  cin >> x1 >> x2;

  //線分の端点のペア
  vector< pair<ll, ll> > p(n);
  vector<ll> lim1(n), lim2(n);

  for(long i=0; i<n; ++i){
    scanf(" %ld %ld", &k[i], &b[i]);

    lim1[i]=(ll)k[i]*x1+b[i];
    lim2[i]=(ll)k[i]*x2+b[i];
    p[i]=make_pair( lim1[i], lim2[i] );
  }

  sort(p.begin(), p.end());
  sort(lim1.begin(), lim1.end());
  sort(lim2.begin(), lim2.end());

  bool cross=false;
  for(long i=0; i<n; ++i){
    //今見ている中で最も低い端点同士を結んでいる線なのでどれとも交差しない
    if(p[i].first==lim1[i] && p[i].second==lim2[i]) continue;
    else cross=true;
  }

  if(cross) printf("YES\n");
  else printf("NO\n");
}
