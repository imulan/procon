#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){	
		int n;
		long a[51]={0};
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %ld", &a[i]);
		sort(a, a+n);
		
		int now=0;
		bool flag=false;
		while(now<n){
			bool ct=false;
			
			//printf("now=%d\n",now);
			
			if(flag) printf(" ");	
			printf("%ld", a[now]);
			
			while(a[now+1] == a[now]+1){
				ct=true;
				++now;	
			}
			if(ct) printf("-%ld", a[now]);
			++now;
			flag=true;
		}
		printf("\n");
	}
	return 0;
}