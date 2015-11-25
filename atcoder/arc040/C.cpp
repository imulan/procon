#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	char f[100][101];
	
	//int rlim[100]={0}; //i行目の一番右の'.'がある位置(なければ-1)
	
	//initialize
	//for(int i=0; i<100; ++i) rlim[i]=-1;
	
	//input
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf(" %c", &f[i][j]);
			
			//if(f[i][j]=='.') rilm[i]=j;		
		}
	} 
	
	//calculation
	int ans=0;
	for(int i=0; i<n-1; ++i){
		
		//今i行目に注目
		int rlim=-1;
		
		for(int j=0; j<n; ++j){
			if(f[i][j]=='.') rlim=j;	
		}
		
		if(rlim>=0){ //この行には塗られていない部分がある
			//Z塗り
			for(int j=0; j<=rlim; ++j) f[i][j]='o';
			for(int j=rlim; j<n; ++j) f[i+1][j]='o';
			ans++;
		}	
		
	}
	
	//一番下の行に塗り残しが有れば塗って終わり
	for(int i=0; i<n; ++i){
		if(f[n-1][i]=='.'){
			ans++;
			break;
		}
	}
	
	printf("%d\n", ans);
}