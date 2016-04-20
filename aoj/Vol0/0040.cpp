#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int gcd(int p, int q){
  if(p<q) swap(p,q);
  while(q!=0){
    int tmp=p%q;
    p=q;
    q=tmp;
  }
  return p;
}

int main(int argc, char const *argv[]) {
  int i,j,k;

  string a="abcdefghijklmnopqrstuvwxyz";

  int n;
  scanf("%d\n",&n);
  for(int times=0; times<n; ++times){
    string s;
    getline(cin,s);
    //cout << s << endl;

    string ans;
    bool end=false;

    for(i=1; i<=25; ++i){//アルファの値
      if(gcd(26,i)!=1) continue;

      rep(j,26){
        //まず正当性検証
        set<int> ch;
        rep(k,a.size()) ch.insert((i*k+j)%26);
        //ダメ
        if(ch.size()!=a.size()) continue;

        //printf("(%d,%d)\n",i,j);

        //ためす
        ans="";
        int p=0;
        rep(k,s.size()){
          if('a'<=s[k] && s[k]<='z'){
            ans+='a'+(i*(s[k]-'a')+j)%26;
          }
          else{
            ans+=s[k];
            string tmp=ans.substr(p,k-p);
            //cout << tmp << endl;

            if(tmp=="this"||tmp =="that")
              end=true;

            p=k+1;
          }
        }

        string tmp=ans.substr(p,k-p);
        //cout << tmp << endl;

        if(tmp=="this"||tmp =="that")
          end=true;


        if(end) break;
      }
      if(end) break;
    }

    std::cout << ans << std::endl;
  }
  return 0;
}
