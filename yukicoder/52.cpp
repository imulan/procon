#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  string s;
  cin >>s;

  //n文字になったら入れる
  set<string> ans;
  //スタート
  string st="";
  //残り
  string r=s;

  //BFS
  queue< pair<string,string> > que;
  que.push(mp(st,r));
  while(!que.empty()){
    pair<string,string> v=que.front();
    que.pop();

    int len=v.sc.size();
    if(len==1) ans.insert(v.fi+v.sc);
    else{
      string a,b;

      //先頭から取ってくる
      a=v.fi+v.sc[0];
      b=v.sc.substr(1,len-1);
      que.push(mp(a,b));
      //末尾から取ってくる
      a=v.fi+v.sc[len-1];
      b=v.sc.substr(0,len-1);
      que.push(mp(a,b));

    }
  }

  std::cout << ans.size() << std::endl;
  return 0;
}
