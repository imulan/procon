#include <stdio.h>

int main(void){
	int n, i, j;
	while( scanf(" %d", &n) * n != 0){
		int f[15][15]={0};
		f[n/2+1][n/2]=1;
		int now=2, nx=n/2, ny=n/2+1;
		
		while(now<=n*n){
			if( f[(ny+1) % n][(nx+1) % n] == 0 ){
				nx = (nx+1)%n;
				ny = (ny+1)%n;
				f[ny][nx]=now;
				++now;
			}
			else{ 
				if(nx-1<0) nx=n-1;
				else --nx;
				
				ny = (ny+1)%n;
			}
		}
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				printf("%4d", f[i][j]);
			}
			printf("\n");
		}
	
	}
	return 0;
}