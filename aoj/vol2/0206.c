#include <stdio.h>

int main(void){
	long L;
	while( scanf(" %ld", &L) * L != 0 ){
		int i, ans=0, flag=0;
		long m, n, now=0;
		
		for(i=0; i<12; i++){
			scanf(" %ld %ld", &m, &n);
			now+=m-n;
			if(flag==0 && now>=L) {
				ans = i+1;
				flag=1;
			}
		}
		
		if(ans==0) printf("NA\n");
		else printf("%d\n", ans);
	}
	return 0;
}