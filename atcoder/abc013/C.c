#include <stdio.h>

long n=0, h=0, a, b, c, d, e=0;
long min = 2000000000;

void rec(long x, long y, long z){

	//printf("now: %ld %ld %ld\n", x, y, z);
	
	if(y<=0 || z>min) {}
	else if(x==n+1){
		if(min > z) min = z;
	}
	else{
		rec(x+1, y-e, z); //抜き
		rec(x+1, y+d, z+c); //しっそ
		rec(x+1, y+b, z+a); //ふつう
	}
		
}

int main(void){
	
	scanf(" %ld %ld", &n, &h);
	scanf(" %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e);
	
	rec(1, h, 0);
	
	printf("%ld\n", min);

	return 0;
}