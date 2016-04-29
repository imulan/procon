#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=100;

int main(){
	while(1){
		int n;
		int taro[N];
		int hanako[N];
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %d", &taro[i]);
	
		sort(taro, taro+n);
		
		int t=0;
		int h=0;
		for(int i=1; i<=2*n; ++i){
			if(i==taro[t]) ++t;
			else{	
				hanako[h]=i;
				++h;
			}	
		}
		
		/*
		printf("hanako:\n");
		for(int i=0; i<n; ++i) printf("%d\n", hanako[i]);
		printf("%d %d\n", t, h);
		*/
		
		int field=0;
		while(t>0 && h>0){
			for(int i=0; i<n; ++i){
				if(taro[i]>field){
					field=taro[i];
					taro[i]=-1;
					t--;
					break;	
				}
				
				if(i==n-1) field=0;//pass	
			}
			//printf("now field=%d\n", field);
			
			if(t<=0) break;
			
			for(int i=0; i<n; ++i){
				if(hanako[i]>field){
					field=hanako[i];
					hanako[i]=-1;
					h--;
					break;
				}
				
				if(i==n-1) field=0;//pass
			}
			//printf("now field=%d\n", field);	
		}
		
		printf("%d\n%d\n", h, t); 	
	}
	return 0;
}