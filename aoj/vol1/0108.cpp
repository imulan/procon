#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){	
		int n, count=0;
		long before[13], after[13], c[13];
	
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i)scanf(" %ld", &before[i]);
				
		//loop
		while(1){
			
			for(int i=0; i<=12; ++i) c[i]=0;
			
			for(int i=0; i<n; ++i){
				for(int j=0; j<n; ++j){
					if(before[i] == before[j]) c[i]++;
				}
			}
				
			for(int i=0; i<n; ++i) after[i]=c[i];	
			
			bool flag=true;
			for(int i=0; i<n; ++i){
				if(before[i]!=after[i]){
					flag=false;
					break;	
				}
			}
			if(flag) break;
			
			/*
			for(int i=0; i<n; ++i){
				printf("%ld", after[i]);
				if(i<n-1) printf(" ");
			}
			printf("\n");
			*/
			
			count++;
			for(int i=0; i<n; ++i) before[i]=after[i];
		}
		
		printf("%d\n", count);
		for(int i=0; i<n; ++i){
			printf("%ld", after[i]);
			if(i<n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}