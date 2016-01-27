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

const long N = 1000001;

long s;
long dat[2*N-1];

void init(int n_){
  s=1;
  while(s<n_) s*=2;

  for(long i=0; i<2*s-1; ++i) dat[i] = -1;
}

void update(long k, long a){
  k+=s-1;
  dat[k]=a;
  while(k>0){
    k = (k-1)/2;
    dat[k] = max(dat[k*2+1],dat[k*2+2]);
  }
}

long query(long a, long b, long k, long l, long r){
  if(r<=a || b<=l) return -1;

  if(a<=l && r<=b) return dat[k];
  else{
    long vl = query(a,b,k*2+1,l,(l+r)/2);
    long vr = query(a,b,k*2+2,(l+r)/2,r);
    return max(vl,vr);
  }
}

queue< pair<long,long> > q[200001]; //y座標-x座標+100000


int main(){
  long n;
  cin >> n;

  init(n);

  vector< pair<long,long> > p(n);
  for(long i=0; i<n; ++i) scanf(" %ld %ld", &p[i].first, &p[i].second);
  sort(p.begin(),p.end());

  for(long i=0; i<n; ++i){
    //printf(" focus %ld, %ld\n", p[i].first, p[i].second);
    q[p[i].second-p[i].first+100000].push(p[i]);
  }

  vector< pair<long,long> > ans;
  ans.resize(n);

  bool valid=true;
  for(long i=0; i<n; ++i){
    long w;
    scanf(" %ld", &w);

    if(valid){
      if(q[w+100000].size()==0){
        valid=false;
      }
      else{ //要素が見つかった
        pair<long,long> tmp = q[w+100000].front();
        //printf("%ld, %ld\n", tmp.first, tmp.second);
        q[w+100000].pop();

        long lim = query(tmp.first,100001,0,0,s);
        //printf("lim=%ld\n", lim);
        if(lim<tmp.second){ //大丈夫
          update(tmp.first,tmp.second);
          ans[i].first = tmp.first;
          ans[i].second = tmp.second;
        }
        else valid=false;
      }
    }
  }

  if(valid){
    printf("YES\n");
    for(long i=0; i<n; ++i) printf("%ld %ld\n",ans[i].first, ans[i].second);
  }
  else printf("NO\n");
}
