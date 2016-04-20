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
  int i;

  int n;
  cin >>n;
  vector< pair<int,int> > v(n);

  map<char,int> d;
  d['D']=0;
  d['C']=1;
  d['H']=2;
  d['S']=3;

  rep(i,n){
    char mark,num;
    scanf(" %c%c", &mark, &num);

    v[i].fi=d[mark];

    int t;
    if(num=='A') t=1;
    else if(num=='T') t=10;
    else if(num=='J') t=11;
    else if(num=='Q') t=12;
    else if(num=='K') t=13;
    else t=num-'0';
    v[i].sc=t;
  }

  sort(v.begin(),v.end());

  //復元
  string mm="DCHS";
  rep(i,n){
    if(i) printf(" ");

    printf("%c",mm[v[i].fi]);

    int t=v[i].sc;
    char pp;
    if(t==1) pp='A';
    else if(t==10) pp='T';
    else if(t==11) pp='J';
    else if(t==12) pp='Q';
    else if(t==13) pp='K';
    else pp='0'+t;
    printf("%c", pp);
  }
  printf("\n");

  return 0;
}
