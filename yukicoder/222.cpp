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

  string s;
  cin >>s;

  //まず演算子の位置を見つける
  char op='?';
  int op_index=-1;
  bool f=false;
  //数字の直後の演算子
  rep(i,s.size()){
    if('0'<=s[i]&&s[i]<='9') f=true;
    else{//記号
      if(f){
        op_index=i;
        op=s[i];
        break;
      }
    }
  }

  int x=atoi(s.substr(0,op_index).c_str());
  int y=atoi(s.substr(op_index+1).c_str());

  int ans=x+y;
  if(op=='+') ans=x-y;
  std::cout << ans << std::endl;
  return 0;
}
