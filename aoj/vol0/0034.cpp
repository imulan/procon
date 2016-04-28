#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long L[10], v1, v2, s=0;
		bool end=false;
		for(int i=0; i<10; ++i){
			if(scanf(" %ld,", &L[i])==EOF){
				end=true;
				break;
			}	
			s+=L[i];
		}
		if(end) break;
		scanf(" %ld,%ld", &v1, &v2);
		
		s*=v1+v2;
		for(int i=0; i<10; ++i) L[i]*=v1+v2;
		
		int ans=1;
		long now=0;
		long v1t=v1*s/(v1+v2);
		while(now<v1t){
			now+=L[ans-1];
			++ans;	
		}
		
		printf("%d\n", ans-1);
	}
}