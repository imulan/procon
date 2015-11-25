#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	while(1){
		int n, field=0, p[10]={0};
		char a;
		
		cin >> n;
		if(n==0) break;
		
		for(int i=0; i<100; ++i){
			scanf(" %c", &a);
			
			if(a=='M'){
				++p[i%n];
			}else if(a=='S'){
				field += p[i%n]+1;
				p[i%n]=0;
			}else if(a=='L'){
				p[i%n] += field+1;
				field=0;
			}	
		}
			
		sort(p, p+n);
		
		for(int i=0; i<n; ++i)
			printf("%d ", p[i]);
		printf("%d\n", field);
	
	}

	return 0;
}