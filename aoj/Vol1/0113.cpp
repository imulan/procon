#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long p, q;
	while(cin >> p >> q){
		long r[10000];
		int ans[10000];
		int now=1;
		
		bool flag=true;
		long start=-1, end=-1;
		
		r[0]=p;
		ans[0]=-1;
		
		while(flag){
			p*=10;
		
			long s=p/q;
			p=p%q;
			r[now]=p;
			ans[now]=s;
			//printf("s=%ld\n", s);
			now++;
			
			for(long i=0; i<now-1; ++i){
				if(r[i]==p){
					start=i;
					end=now;
					flag=false;
					break;	
				}
			}
			
			if(flag){	
				if(p==0){
					flag=false;
					break;
				}
			}		
		
		}
		
		for(long i=1; i<now; ++i) printf("%d", ans[i]);
		printf("\n");
		
		if(start!=-1){
			for(long i=1; i<=start; ++i) printf(" ");
			for(long i=start+1; i<end; ++i) printf("^");
			printf("\n");	
		}
		
		/*
		for(long i=0; i<now; ++i){
			printf("r[%ld]=%ld\n", i, r[i]);
		}
		*/
		
	}
}