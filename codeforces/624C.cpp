#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  long n,m;
  int r[500][500]={0};

  cin >>n >>m;
  for(long i=0; i<m; ++i){
    long a,b;
    scanf(" %ld %ld", &a, &b);
    --a;
    --b;
    r[a][b]=1;
    r[b][a]=1;
  }

  /*
  for(long i=0; i<n; ++i){
    for(long j=0; j<n; ++j){
      printf("%d", r[i][j]);
    }
    printf("\n");
  }
  */

  bool valid=true;
  string ans="";

  for(long i=0; i<n; ++i){ //今i番目の頂点に注目
    //頂点のつながっている数をカウント
    long t=0;
    for(long j=0; j<n; ++j) t+=r[i][j];

    //全ての辺とつながっている
    if(t==n-1) ans+="b";
    else{
      //繋がっていないところがある
      //今の頂点をaまたはcに設定したい
      //既に設定したところと矛盾がないか見る
      char now='a';
      char other='c';
      bool ok=true;

      for(long j=0; j<i; ++j){
        if(r[i][j]==0){//繋がっていない場合
          if(ans[j]!=other){
            ok=false;
            break;
          }
        }
        else{//つながっている場合
          if(ans[j]==other){
            ok=false;
            break;
          }
        }
      }

      if(!ok){
        now='c';
        other='a';
        ok=true;
        for(long j=0; j<i; ++j){
          if(r[i][j]==0){//繋がっていない場合
            if(ans[j]!=other){
              ok=false;
              break;
            }
          }
          else{//つながっている場合
            if(ans[j]==other){
              ok=false;
              break;
            }
          }
        }

        if(!ok) valid=false;
      }

      if(valid) ans+=now;
      else break;
    }

  }

  //output
  if(valid){
    printf("Yes\n");
    std::cout << ans << std::endl;
  }
  else printf("No\n");

  return 0;
}
