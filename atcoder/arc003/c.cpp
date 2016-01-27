#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

struct point{
  int x,y;
};

int main(int argc, char const *argv[]) {
  int n,m;
  cin >>n >>m;

  vector<string> c(n);
  REP(i,n) cin >>c[i];

  int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};

  point start,goal;
  REP(i,n){
    REP(j,m){
      if(c[i][j]=='s'){
        start.x=j;
        start.y=i;
      }
      if(c[i][j]=='g'){
        goal.x=j;
        goal.y=i;
      }
    }
  }

  //まず到達可能性判定
  queue<point> que;
  int visit[500][500]={0};
  que.push(start);
  visit[start.y][start.x]=1;
  while(!que.empty()){
    point v=que.front();
    que.pop();
    REP(i,4){
      int nx=v.x+dx[i], ny=v.y+dy[i];
      if(nx>=0&&nx<m&&ny>=0&&ny<n){
        if(visit[ny][nx]==0&&c[ny][nx]!='#'){
          que.push((point){nx,ny});
          visit[ny][nx]=1;
        }
      }
    }
  }

  if(visit[goal.y][goal.x]==0){
    printf("-1\n");
  }
  else{//到達可能なので、明るさを決め打ちにして二分探索
    double pw[2000];
    pw[0]=1;
    REP(i,2000-1) pw[i+1]=pw[i]*0.99;

    double left=0, right=9;
    double mid=5, oldmid=0;

    while(1){
      mid=(left+right)/2.0;
      if(fabs(mid-oldmid)<1e-10) break;

      //start地点からたどり着くのに必要な時間の最小値
      int dist[500][500];
      int INF=1000000;

      REP(i,500)REP(j,500)dist[i][j]=INF;
      dist[start.y][start.x]=0;

      bool valid=false; //到達可能かどうか
      queue<point> Q;
      Q.push(start);
      while(!Q.empty()){
        point v=Q.front();
        Q.pop();
        REP(i,4){
          int nx=v.x+dx[i], ny=v.y+dy[i];

          if(nx>=0&&nx<m&&ny>=0&&ny<n){
            if(c[ny][nx]=='g'){
              valid=true;
              break;
            }
            else if(c[ny][nx]!='#' && dist[ny][nx]>dist[v.y][v.x]+1 && (c[ny][nx]-'0')*pw[dist[v.y][v.x]+1]>=mid){
              Q.push((point){nx,ny});
              dist[ny][nx]=dist[v.y][v.x]+1;
            }
          }

        }
        if(valid) break;
      }

      /*
      REP(i,n){
        REP(j,n){
          if(dist[i][j]==INF) printf("X");
          else printf("%d", dist[i][j]);
        }
        printf("\n");
      }
      */

      if(valid) left=mid;
      else right=mid;

      oldmid=mid;
    }

    printf("%.20lf\n", mid);
  }

  return 0;
}
