#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a[6][6]={0};
	int df[4]={0,-1,0,1}, ds[4]={1,0,-1,0};
	
	for(int i=1; i<=4; ++i)
	for(int j=1; j<=4; ++j)
	scanf(" %d", &a[i][j]);
	
	/*
	for(int i=0; i<6; ++i){
		for(int j=0; j<6; ++j){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	} 
	*/
	
	bool ans=false;
	for(int i=1; i<=4; ++i){
		for(int j=1; j<=4; ++j){
			for(int k=0; k<4; ++k){
				int f=i+df[k], s=j+ds[k];
				if(a[i][j] == a[f][s]) ans=true;
			}	
		}
	}
	
	if(ans) printf("CONTINUE\n");
	else printf("GAMEOVER\n");
}