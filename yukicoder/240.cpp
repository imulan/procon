#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<long,long> pl;

long ab(long p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  pl d;
  cin >>d.fi >>d.sc;

  set<pl> s;
  queue< pair<pl,int> > que;
  pl start(0,0);
  que.push(mp(start,0));
  s.insert(start);
  //BFS
  while(!que.empty()){
    pair<pl,int> v=que.front();
    que.pop();

    pl t=v.fi;
    int now=v.sc;

    if(now>=3) continue;

    for(long dx=-2; dx<=2; ++dx){
      if(dx==0) continue;

      long dy=3-ab(dx);
      pl t1(t.fi+dx,t.sc-dy);
      pl t2(t.fi+dx,t.sc+dy);

      s.insert(t1);
      s.insert(t2);
      que.push(mp(t1,now+1));
      que.push(mp(t2,now+1));
    }
  }

  string ans="YES";
  if(s.find(d)==s.end()) ans="NO";
  std::cout << ans << std::endl;
  return 0;
}
