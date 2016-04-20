#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i;

  int n,m;
  cin >>n >>m;

  vector<pair<int,int>> p(n);
  vector<int> a(m);

  rep(i,n) scanf(" %d %d",&p[i].fi,&p[i].sc);
  sort(p.begin(),p.end());
  rep(i,m) scanf(" %d",&a[i]);
  sort(a.begin(),a.end());

  priority_queue<int,vector<int>,greater<int>> que;
  int ans=0, p_index=0;
  rep(i,m){
    while(p_index<n && p[p_index].fi<=a[i]){
      //上限をpush
      que.push(p[p_index].sc);
      ++p_index;
    }
    if(que.empty()) continue;

    while(que.top()<a[i]) que.pop();
    if(que.empty()) continue;

    ++ans;
    que.pop();
  }
  std::cout << ans << std::endl;
  return 0;
}
