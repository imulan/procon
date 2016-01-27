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

ll calc_m(ll n, ll x){
  ll ret=-1;
  if( (6*x-n+n*n*n) % (3*n*(n+1)) == 0){
    ret = (6*x-n+n*n*n) / (3*n*(n+1));
  }
  //cout << "ret =" << ret <<endl;
  return ret;
}

int main(){
  ll x;
  cin >> x;

  ll n=1;
  vector< pair<ll,ll> > ans;

  while(6*x>=2*n*n*n+3*n*n+n){
    ll m=calc_m(n,x);
    if(m!=-1) ans.push_back(make_pair(n,m));
    n++;
  }

  //折り返し
  ll lim=ans.size();
  if(ans[ans.size()-1].first == ans[ans.size()-1].second) lim--;
  for(ll i=lim-1; i>=0; --i){
    ans.push_back(make_pair(ans[i].second,ans[i].first));
  }

  //output answer
  cout << ans.size() << endl;
  for(ll i=0; i<ans.size(); ++i){
    cout << ans[i].first << " " << ans[i].second << endl;
  }

}
