#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

typedef struct{
	int pid;
	long long sell;
}people;

int main(){
	while(1){
		long n;
		people p[4000];
		
		scanf(" %ld", &n);
		if(n==0) break;
		
		int now=0;
		
		for(long i=0; i<n; ++i){
			int num;
			long t, u;
			scanf(" %d %ld %ld", &num, &t, &u);
			
			bool find=false;
			for(int j=0; j<now; ++j){
				if(p[j].pid==num){
					p[j].sell+=t*u;	
					find=true;
				}
			}
			if(!find){
				p[now].pid=num;
				p[now].sell=t*u;
				now++;
			}
		}		
		
		int count=0;
		for(int i=0; i<now; ++i){
			if(p[i].sell>=1000000){
				printf("%d\n", p[i].pid);
				++count;
			}		
		}
		
		if(count==0) printf("NA\n");
	}	
}