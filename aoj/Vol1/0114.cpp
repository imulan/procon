#include <iostream>
#include <cstdio>

int gcd(int x, int y){
	int r;
	while( (r = x%y) != 0){
		x=y;
		y=r;
	}

	return y;
	
}

long lcm(int x, int y){
	return (long)x*y/gcd(x,y);
}

int main(){
	while(1){
		int a[3], m[3], p[3], memo[3], flag[3]={0};

		for(int i=0; i<3; ++i)
			scanf(" %d %d", &a[i], &m[i]);
	
		if(a[0]==0 && m[0]==0) break;

		for(int i=0; i<3; ++i)
			p[i] = a[i]%m[i];
		long count=1;
		int mcount=0;
		
		while(1){
			for(int i=0; i<3; ++i){
				if(p[i]==1 && flag[i]==0){
					memo[i]=count;
					flag[i]=1;
					++mcount;
					//printf("mmm\n");
				}
			}
			
			if(mcount==3) break;
		
			for(int i=0; i<3; ++i)
				p[i] = (a[i]*p[i]) % m[i];
			
			++count;
		}
		
		long tmp = lcm(memo[0], memo[1]);
		long ans = lcm(memo[2], tmp);
		
		printf("%ld\n", ans);	
	}

	return 0;
}