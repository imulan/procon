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
  string a="abcdefghijklmnopqrstuvwxyz";
  a += a;

  string s;

  while(getline(cin,s)){
    //cout << s << endl;

    string t="";
    bool end=false;
    int i;
    for(int w=0; w<=25; ++w){
      //printf("w=%d\n", w);
      t="";
      int p=0;
      rep(i,s.size()){
        if('a'<=s[i] && s[i]<='z'){
          t+=a[s[i]-'a'+w];
        }
        else{
          t+=s[i];
          string tmp=t.substr(p,i-p);
          //cout << tmp << endl;

          if(tmp=="this" || tmp=="the" || tmp =="that") end=true;

          p=i+1;
        }
      }

      if(end) break;
    }

    std::cout << t << std::endl;
  }
  return 0;
}
