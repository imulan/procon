#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct{
  int x; //横幅
  int y; //縦幅
}rect;

int area(rect r){
  return r.x*r.y;
}

int main(){
  while (1) {
    int n,w,h;
    cin >> n >> w >>h;
    if(n==0 && w==0 && h==0) break;

    vector<rect> v;
    v.resize(1);
    v[0].x=w;
    v[0].y=h;
    for(int i=0; i<n; ++i){
      int p,s;
      scanf(" %d %d", &p, &s);
      p--; //0-indexにあわせる

      //この長方形に注目
      rect f=v[p];

      //長方形を1周以上回るのは無駄
      s%=(f.x+f.y)*2;

      //この長方形の上を時計回りに進むとき
      //移動距離は横、縦、横、縦
      //切る位置がどこに来るかを走査
      rect r1,r2;
      if(s-f.x<0){ //上の辺
        //2つの長方形は、縦f.y、横sとf.x-sになる
        r1.x=s; r1.y=f.y;
        r2.x=f.x-s; r2.y=f.y;
      }
      else if(s-f.x-f.y<0){ //右の辺
        //2つの長方形は、縦s-f.xとf.y-(s-f.x)、横f,xになる
        r1.x=f.x; r1.y=s-f.x;
        r2.x=f.x; r2.y=f.y-(s-f.x);
      }
      else if(s-f.x-f.y-f.x<0){ //下の辺
        //2つの長方形は、縦f.y、横s-f.x-f.yとf.x-(s-f.x-f.y)になる
        r1.x=s-f.x-f.y; r1.y=f.y;
        r2.x=f.x-(s-f.x-f.y); r2.y=f.y;
      }
      else{ //左の辺
        //2つの長方形は、縦s-2*f.x-f.yとf.y-(s-2*f.x-f.y)、横f,xになる
        r1.x=f.x; r1.y=s-2*f.x-f.y;
        r2.x=f.x; r2.y=f.y-(s-2*f.x-f.y);
      }

      //printf("cut (%d*%d) and (%d*%d)\n", r1.x, r1.y, r2.x, r2.y);

      //この長方形はカットされて生まれ変わるので削除
      v.erase(v.begin()+p);
      //そして新しく2つの長方形をプッシュ
      if(area(r1)<area(r2)){
        v.push_back(r1);
        v.push_back(r2);
      }else{
        v.push_back(r2);
        v.push_back(r1);
      }

    }

    vector<int> ans;
    for(int i=0; i<v.size(); ++i){
      ans.push_back(area(v[i]));
    }
    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); ++i){
      if(i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
}
