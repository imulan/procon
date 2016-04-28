#include <iostream>
#include <cstdio>

void print(int x, int y, int z){
	if(x<10) printf("0");
	printf("%d:", x);
	if(y<10) printf("0");
	printf("%d:", y);
	if(z<10) printf("0");
	printf("%d\n", z);
}


int main(){
	while(1){
		int h, m, s;

		scanf(" %d %d %d", &h, &m, &s);
		if(h==-1) break;
		
		int sum = h*3600+m*60+s;
		int ans = 2*3600-sum;
		int a=0, b=0, c=0;
		
		while(ans/3600>0){
			++a;
			ans-=3600;
		}
		while(ans/60>0){
			++b;
			ans-=60;
		}
		c=ans;	
		print(a,b,c);
		
		ans = 3*(2*3600-sum);
		a=0;
		b=0; 
		c=0;
	
		while(ans/3600>0){
			++a;
			ans-=3600;
		}
		while(ans/60>0){
			++b;
			ans-=60;
		}
		c=ans;
		
		print(a,b,c);
	
	}

	return 0;
}