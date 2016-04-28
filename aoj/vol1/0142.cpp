#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		
		long num[10000];
		int ct=0;
		
		for(int i=1; i<n; ++i){
			long p=(i*i)%n;	
			
			bool newin=true;
			for(int j=0; j<ct; ++j){
				if(num[j]==p){
					newin=false;
					break;
				}
			}
			if(newin) num[ct++]=p;
		}
		
		int count[5000];
		for(int i=0; i<5000; ++i) count[i]=0;
		
		for(int i=0; i<ct; ++i){
			for(int j=0; j<ct; ++j){	
				long tmp=num[i]-num[j];
				if(tmp<0) tmp+=n;
				if(tmp>(n-1)/2) tmp=n-tmp;
				
				count[tmp]++;
			}
		}
	
		for(int i=1; i<=(n-1)/2; ++i) printf("%d\n", count[i]);
	}
}