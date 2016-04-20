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
  int i,j;

  int n;
  cin >>n;

  int sum=0;
  std::vector<int> s(n);
  rep(i,n){
    cin >>s[i];
    sum+=s[i];
  }

  int k[50][50];
  memset(k,-1,sizeof(k));
  //自分の点数は分かる
  rep(i,n) k[i][i]=s[i];

  int m;
  cin >>m;
  rep(i,m){
    int a,b,c;
    cin >>a >>b >>c;
    --b;
    --c;
    if(a==0){//情報クエリ
      k[b][c]=s[c];
    }
    else{//質問クエリ
      int x=0,y=100;
      if(k[b][c]==-1){//推測

        //現在点数を知っている生徒
        int ct=0;
        int tmp=0;
        rep(j,n){
          if(k[b][j]!=-1){
            ++ct;
            tmp+=k[b][j];
          }
        }

        //残り
        int r=sum-tmp;

        if(n-ct==1){//特定できる
          x=y=k[b][c]=r;
        }
        else{
          //c以外の知らない残りの(n-ct-1)人が100点だったとして
          x=max(0,r-(n-ct-1)*100);
          //最高点に限界
          y=min(100,r);
        }

      }
      else{//知ってる
        x=y=k[b][c];
      }
      printf("%d %d\n",x,y);
    }
  }

  return 0;
}
