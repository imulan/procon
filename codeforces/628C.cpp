#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

long dist(char x, char y){
  return (x<y)?y-x:x-y;
}

int main(int argc, char const *argv[]) {
  long i;

  //各アルファベットごとにdistの最大値を求めておく
  long dm[26];
  rep(i,26) dm[i]=max(dist('a',i+'a'),dist('z',i+'a'));

  long n,k;
  char str[100010];
  string s;
  cin >>n >>k;
  scanf(" %s",str);
  s=str;

  long lim=0;
  rep(i,s.size()) lim+=dm[s[i]-'a'];

  if(lim<k) printf("-1\n");
  else{
    string ans="";

    //現在注目しているindex
    long now=0;
    while(now<s.size()){
      //この桁で終わりにしてそれ以降はコピー
      if(dm[s[now]-'a']>=k){
        int p=s[now]-'a';

        if(p-k>=0) ans+='a'+p-k;
        else if(p+k<=26) ans+='a'+p+k;
        else printf("??????\n");

        ++now;
        break;
      }
      else{
        if(s[now]-'a'<'z'-s[now]){
          ans+='z';
          k-='z'-s[now];
        }
        else{
          ans+='a';
          k-=s[now]-'a';
        }
        ++now;
      }

      //printf("k=%ld\n",k);
    }

    ans+=s.substr(now);

    std::cout << ans << std::endl;
  }

  return 0;
}
