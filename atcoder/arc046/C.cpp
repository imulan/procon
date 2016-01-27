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
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  int N, M;
  cin >>N >>M;
  vector< pair<int,int> > m(N), f(M); //a,b //d,c

  for(int i=0; i<N; ++i) scanf(" %d %d", &m[i].first, &m[i].second);
  for(int i=0; i<M; ++i) scanf(" %d %d", &f[i].second, &f[i].first);

  sort(m.begin(), m.end());
  sort(f.begin(), f.end());
  /*
  for(int i=0; i<N; ++i) printf(" %d %d\n", m[i].first, m[i].second);
  printf("\n");
  for(int i=0; i<M; ++i) printf(" %d %d\n",f[i].second, f[i].first);
  */

  int mm=0;
  int ct=0;
  for(int i=0; i<M; ++i){ //d_iに注目
    while(m[mm].first < f[i].first){
      mm++;
      if(mm>N) break;
    }
    mm++;
    if(mm>N) break;

    ct++;
    //printf(" %d %d ::\n", i, mm);
  }

  printf("%d\n",ct);
  return 0;
}
