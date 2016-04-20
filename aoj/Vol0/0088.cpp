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
  map<char,string> m;
  m[' '] ="101";
  m['\'']="000000";
  m[','] ="000011";
  m['-'] ="10010001";
  m['.'] ="010001";
  m['?'] ="000001";
  m['A'] ="100101";
  m['B'] ="10011010";
  m['C'] ="0101";
  m['D'] ="0001";
  m['E'] ="110";
  m['F'] ="01001";
  m['G'] ="10011011";
  m['H'] ="010000";
  m['I'] ="0111";
  m['J'] ="10011000";
  m['K'] ="0110";
  m['L'] ="00100";
  m['M'] ="10011001";
  m['N'] ="10011110";
  m['O'] ="00101";
  m['P'] ="111";
  m['Q'] ="10011111";
  m['R'] ="1000";
  m['S'] ="00110";
  m['T'] ="00111";
  m['U'] ="10011100";
  m['V'] ="10011101";
  m['W'] ="000010";
  m['X'] ="10010010";
  m['Y'] ="10010011";
  m['Z'] ="10010000";

  int i;
  string s;
  string al="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (getline(cin,s)){
    string ans="";

    string a="";
    rep(i,s.size()) a+=m[s[i]];

    int tmp=a.size()%5;
    if(tmp!=0){
      rep(i,5-tmp) a+="0";
    }

    //cout << a << endl;

    for(int j=0; j<a.size(); j+=5){
      //5文字ごと切り出す
      string b=a.substr(j,5);
      if(b=="11010") ans+=" ";
      else if(b=="11011") ans+=".";
      else if(b=="11100") ans+=",";
      else if(b=="11101") ans+="-";
      else if(b=="11110") ans+="'";
      else if(b=="11111") ans+="?";
      else{
        int val=0;
        for(int k=0; k<5; ++k){
          val+=(b[k]-'0')*pow(2,4-k);
        }
        ans+=al[val];
      }

    }

    std::cout << ans << std::endl;
  }
  return 0;
}
