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
  int i,j;

  int n;
  scanf("%d\n",&n);
  for(int T=0; T<n; ++T){
    string s;
    getline(cin,s);

    string h="Hoshino";
    string r="Hoshina";

    if(h.size()<=s.size()){
      rep(i,s.size()-h.size()+1){
        if(s.substr(i,h.size())==h){
          s[i+h.size()-1]='a';
        }
      }
    }

    std::cout << s << std::endl;
  }
  return 0;
}
