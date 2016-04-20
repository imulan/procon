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

  int n;
  string s;
  cin >>n >>s;

  int lb[100001]={0},rb[100001]={0},qm[100001]={0};
  rep(i,n){
    if(s[i]=='(') ++lb[i+1];
    if(s[i]==')') ++rb[i+1];
    if(s[i]=='?') ++qm[i+1];
  }
  rep(i,n){
    lb[i+1]+=lb[i];
    rb[i+1]+=rb[i];
    qm[i+1]+=qm[i];
  }

  rep(i,n+1){
    printf("l,r,q:%d,%d,%d\n", lb[i], rb[i], qm[i]);
  }

  int Q;
  cin >>Q;
  for(int q=0; q<Q; ++q){
    int l,r;
    scanf(" %d %d",&l,&r);

    //部分列の長さが奇数なのはダメ
    if((r-l)%2==0){
      printf("No\n");
      continue;
    }





  }
  return 0;
}
