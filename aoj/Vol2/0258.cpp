#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int n, count=0; 
		long h[101]={0}, c[100]={0};
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<=n; ++i)
			scanf(" %ld", &h[i]);
			
		for(int i=0; i<=n; ++i){
			int count=0;
			
			for(int j=0; j<=n; ++j){ 
				if(i!=j){
					c[count]=h[j];
					++count;
				}
			}
			bool flag=true;
			
			for(int j=1; j<n; ++j){
 				if(c[1]-c[0]!=c[j]-c[j-1]) flag=false;
 			}
 			
 			if(c[1]<=c[0]) flag=false;
 			
 			if(flag){
 				printf("%ld\n", h[i]);
 				break;
 			}
 		}
 		
 	}
 		
	return 0;
}