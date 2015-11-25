#include <stdio.h>
 
int main(){
	int a, b, c, d, n, tw[2048] = {0};
	long long th[4096] = {0};
	for(a = 0;a <= 1000;a++) 
		for(b = 0;b <= 1000;b++) 
			tw[a+b]++;
			
	for(a = 0;a <= 2000;a++) 
		for(b = 0;b <= 2000;b++) 
			th[a+b] += tw[a]*tw[b];
 
	while(scanf(" %d", &n) != EOF)
    	printf("%lld\n", th[n]);
  	
  	return 0;
}