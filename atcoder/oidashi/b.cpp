#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};
const int INF=100000000;

int h,w;
int f[400][400];
//ライトが壊れているか
bool b[400][400];

int flip[400][400];

int get(int x, int y){
  int i;

  int c=f[x][y];
  rep(i,5){
    int nx=x+dx[i], ny=y+dy[i];
    if(0<=nx&&nx<h && 0<=ny&&ny<w) c+=flip[nx][ny];
  }

  return c%2;
}

int calc(){
  int i,j;

  for(i=1; i<h; ++i){
    rep(j,w){
      if(get(i-1,j)!=0){
        if(b[i][j]){
          //壊れているのでムリ
          return -1;
        }
        else flip[i][j]=1;
      }
    }
  }

  rep(i,w){
    if(get(h-1,i)!=0) return -1;
  }

  int ret=0;
  rep(i,h)rep(j,w) ret+=flip[i][j];
  return ret;
}

int main(int argc, char const *argv[]) {
  int i,j;

  cin >>h >>w;
  int tmp[400][400];
  rep(i,h)rep(j,w) scanf(" %d",&tmp[i][j]);

  bool rotate;
  //fにコピー
  if(h<w){//転置
    rep(i,h)rep(j,w) f[j][i]=tmp[i][j];
    swap(h,w);
    rotate=true;
  }
  else{
    rep(i,h)rep(j,w) f[i][j]=tmp[i][j];
    rotate=false;
  }

  int n;
  cin >>n;
  fill(b[0],b[400],false);
  rep(i,n){
    int x,y;
    scanf(" %d %d",&x,&y);
    if(rotate) swap(x,y);
    b[y][x]=true;
  }

  int ans=INF;
  rep(i,1<<w){
    memset(flip,0,sizeof(flip));
    bool valid=true;
    rep(j,w){
      if(i>>j&1 && b[0][w-j-1]){
        valid=false;
        break;
      }
      flip[0][w-j-1]=(i>>j)&1;
    }

    if(!valid) continue;

    int t=calc();
    //printf("i %d: t=%d\n",i,t);
    if(t>0 && t<ans) ans=t;
  }

  std::cout << ans << std::endl;
  return 0;
}
