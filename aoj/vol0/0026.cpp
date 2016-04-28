#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int x, y, s;
	int f[10][10];
	
	memset(f, 0, sizeof(f));
	
	while( scanf(" %d,%d,%d", &x, &y, &s) != EOF ){
		if(s==1){
			for(int i=y-1; i<=y+1; ++i){
				int a=0;
				if(i==y) a=1;	
				for(int j=x-a; j<=x+a; ++j){
					if(i>=0 && i<10 && j>=0 && j<10) f[i][j]++;
				}	
			}
		}
		else if(s==2){
			for(int i=y-1; i<=y+1; ++i){
				for(int j=x-1; j<=x+1; ++j){
					if(i>=0 && i<10 && j>=0 && j<10) f[i][j]++;
				}
			}	
		}
		else if(s==3){
			for(int i=y-2; i<=y+2; ++i){
				int a=y-i;
				if(a<0) a=-a;
				a=a-2;
				if(a<0) a=-a;	
				for(int j=x-a; j<=x+a; ++j){
					if(i>=0 && i<10 && j>=0 && j<10) f[i][j]++;
				}	
			}
		}
	}
	
	int max=0, count=100;
	for(int i=0; i<10; ++i){
		for(int j=0; j<10; ++j){
			//printf("%d", f[i][j]);
			if(f[i][j]>0) count--;
			if(f[i][j]>max) max=f[i][j];
		}
		//printf("\n");
	}
	
	printf("%d\n%d\n", count, max);
}