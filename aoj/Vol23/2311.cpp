#include <cstdio>
#include <iostream>
using namespace std;

//真上から時計回り
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};

//fの状況でx,yにcを置いた時に、ひっくり返せる個数
int revnums(char f[8][9], int x, int y, char c, int flag){
  int ret=0;

  char e_cookie;
  if(c=='o') e_cookie='x';
  else e_cookie='o';

  if(f[x][y]=='.'){ //クッキーがないのでおけるかどうか調べる
    //8方向に対して
    for(int i=0; i<8; ++i){
      int r=1;

      while(0<=x+r*dx[i] && x+r*dx[i]<8 && 0<=y+r*dy[i] && y+r*dy[i]<8){
        char focus=f[x+r*dx[i]][y+r*dy[i]];
        if(focus==c){ //自分のクッキー
          //間にある敵クッキーがひっくり返せる個数になる

          //実際にひっくり返す
          if(flag==1){
            //まず置く
            f[x][y]=c;
            //ひっくり返す
            for(int j=1; j<r; ++j){
              f[x+j*dx[i]][y+j*dy[i]] = c;
            }
          }

          ret+=r-1;
          break;
        }
        else if(focus==e_cookie){ //相手のクッキーがある
          r++;
        }
        else{ //どのクッキーもなかった
          break;
        }
      }

    }

  }
  return ret;
}

bool charlotte(char f[8][9]){
  int rev=0;
  int x=-1,y=-1;
  char c='x';
  //右下から
  for(int i=7; i>=0; --i){
    for(int j=7; j>=0; --j){
      int tmp=revnums(f,i,j,c,0);
      if(rev<tmp){
        rev=tmp;
        x=i;
        y=j;
      }
    }
  }

  //置ける場所があったらその場所に実際に置いて変更
  if(x>=0){
    revnums(f,x,y,c,1);
  }

  return (rev>0);
}

bool tomoe(char f[8][9]){
  int rev=0;
  int x=-1,y=-1;
  char c='o';
  //左上から
  for(int i=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      int tmp=revnums(f,i,j,c,0);
      if(rev<tmp){
        rev=tmp;
        x=i;
        y=j;
      }
    }
  }

  //置ける場所があったらその場所に実際に置いて変更
  if(x>=0){
    revnums(f,x,y,c,1);
  }

  return (rev>0);
}

void print_field(char f[8][9]){
  for(int i=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      printf("%c", f[i][j]);
    }
    printf("\n");
  }
}

int main(){
  char f[8][9];

  for(int i=0; i<8; ++i)
  for(int j=0; j<8; ++j)
  scanf(" %c", &f[i][j]);

  bool c=true, t=true;
  while(c || t){
    t=tomoe(f);
    c=charlotte(f);
  }

  print_field(f);
}
