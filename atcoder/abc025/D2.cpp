#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MOD=1e9+7;

int ct[26]={0};

int dp[40000000];

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

int rec(int st){ //現在盤面の状態をビットで表す
	if(dp[st]>=0) return dp[st];

	//全てのマスが埋まった
	if(st==(1<<25)-1) return 1;

	int now=1; //今置こうとしている数字
	for(int i=0; i<25; ++i){
		if((st>>i)&1){ //既に数字が置かれている
			++now;
		}
	}
	//printf("now %d, ct:%d\n", now, ct[now]);
	int ret=0;

	if(ct[now]>=0){ //最初から指定されている
		//置くはずの場所にすでにあるのはNG
		if( ((st>>(ct[now]))&1) == 0 ){
			if(isValid(st,ct[now])){
				//printf("th %d\n", now);
				ret =rec(st+(1<<ct[now]));
				ret%=MOD;
			}
		}
	}
	else{ //決まってないのでおける位置を試す
		for(int i=0; i<25; ++i){ //マスを左上から順に探していく
			if((st>>i)&1){ //もう埋まってて置けない
				continue;
			}

			if(isValid(st,i)){
				//printf("put %d to %d\n", now, i);
				ret += rec(st+(1<<i));
				ret %= MOD;
			}
			//else printf("fail\n");
		}
	}

	return dp[st]=ret;
}

int main(int argc, char const *argv[]) {
	//初期化
	for(int i=1; i<=25; ++i) ct[i]=-1;

	//input
	for(int i=0; i<25; ++i){
		int x;
		scanf(" %d", &x);
		if(x>0) ct[x]=i;
		//printf("ct[%d]=%d\n",x,ct[x]);
	}

	memset(dp,-1,sizeof(dp));
	printf("%d\n", rec(0));

	return 0;
}
