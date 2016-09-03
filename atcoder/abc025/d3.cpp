//TLE
//既に数字が決まっている部分については除外してDPする必要がある

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MOD=1e9+7;

int dp[34000000];

//現在の盤の状態nowSTのとき、posに置くことは出来るか
bool isValid(int st, int pos){
	//置くことが許されている場所か判定する
	bool valid=true;
	//左右判定
	if(pos%5==0 || pos%5==4){ //端なのでok
	}
	else{
		//左隣と右隣のbitのXORをとって1なら片方空き、ダメ
		if( ((st>>(pos-1))&1)^((st>>(pos+1))&1) ){
			valid=false;
		}
	}

	//上下判定
	if(pos<5||19<pos){ //端なのでok
	}
	else{
		//上と下のbitのXORをとって1なら片方空き、ダメ
		if( ((st>>(pos-5))&1)^((st>>(pos+5))&1) ){
			valid=false;
		}
	}

	return valid;
}

int main(int argc, char const *argv[]) {
  int ct[26]={0};

  //初期化
	for(int i=1; i<=25; ++i) ct[i]=-1;

	//input
	for(int i=0; i<25; ++i){
		int x;
		scanf(" %d", &x);
		if(x>0) ct[x]=i;
		//printf("ct[%d]=%d\n",x,ct[x]);
	}

	dp[0]=1;
  for(int st=1; st<(1<<25); ++st){
    dp[st]=0;
    //printf("go %d\n", st);

    int now=0; //直前に置いた数字
    for(int i=0; i<25; ++i){
      if((st>>i)&1){ //既に数字が置かれている
        ++now;
      }
    }

    if(ct[now]>=0){ //nowを置く位置が決まってた
      if( (st>>ct[now])&1 ){
        if(isValid(st-(1<<ct[now]), ct[now])){
          dp[st] += dp[st-(1<<ct[now])];
          dp[st] %= MOD;
        }
      }
    }
    else{
      //stという盤面状態にたどり着く状況を考える
      for(int i=0; i<25; ++i){
        if((st>>i)&1){
          if(isValid(st-(1<<i), i)){
            dp[st] += dp[st-(1<<i)];
            dp[st] %= MOD;
          }
        }
      }
    }

  }

	printf("%d\n", dp[(1<<25)-1]);

	return 0;
}
