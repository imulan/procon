#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <utility>
using namespace std;

typedef long long ll;
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

long zet(long a){
  if(a<0) a=-a;
  return a;
}

long gcd(long x, long y){
  if(x<y) swap(x,y);
  if(y==0) return x;
  else return gcd(y,x%y);
}

int main(){
  long T; cin >> T;
  for(long t=0; t<T; ++t){
    long n;
    cin >>n;

    map<pair<long,long>, set<double> > mp;
    for(long i=0; i<n; ++i){
      long a,b,c;
      scanf(" %ld %ld %ld", &a, &b, &c);

      long g=gcd(zet(a),zet(b));
      double cc=(double)c;
      a/=g; b/=g; cc/=g;
      if(b<0 || (b==0 && a<0)){
        a=-a;
        b=-b;
        cc=-cc;
      }
      /*
      printf(" g=%ld :: ", g);
      printf(" a, b, c : %ld, %ld, %ld\n", a, b, c);
      */
      mp[make_pair(a,b)].insert(cc);
    }

    long ans=0;
    foreach(it,mp){
      ans = max(ans, (long)(it->second).size());
    }
    /*
    foreach(it,mp){
      ans = max(ans,*)

      cout << it->first.first << " " << it->first.second << " :" << flush;
      foreach(it2,it->second){
        cout << *it2 << flush;
      }
      cout << endl;
    }
    */
    cout << ans << endl;
  }
}
