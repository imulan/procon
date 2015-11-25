#include <iostream>
#include <cstdio>

int main(){
	while(1){
		int n, m, now=1, count=0;
		int p[1001] = {0};
		
		scanf(" %d %d", &n, &m);
		if(n==0 && m==0) break;
		
		int max=n;
		
		while(count < n-1){
			int i=0;
			while(i<m-1){
				
				if(p[now]==0){
					++i;
					if(now==n) now=1;
					else ++now;	
				}
				while(p[now]==1){
					if(now==n) now=1;
					else ++now;
				}
				
				//printf("now=%d\n", now);
			}
		
			p[now]=1;
			//3printf("%d,out\n", now);
			++count;
		}
	
		for(int j=1; j<=n; ++j){
			if(p[j]==0){
				printf("%d\n", j);
			}
		}
	
	}

	return 0;
}