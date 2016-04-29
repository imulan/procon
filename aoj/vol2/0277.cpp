#include <iostream>
#include <cstdio>

int main(){
	for(int i=0; i<4; ++i){
		int t, n;
		long p;
		scanf(" %d %d", &t, &n);
		
		switch(t){
			case 1:
				p=n*6000;
				break;
			case 2:
				p=n*4000;
				break;
			case 3:
				p=n*3000;
				break;
			case 4:
				p=n*2000;
				break;
			default:
				break;
		}
	
		printf("%ld\n", p);
	}	
	
	return 0;
}