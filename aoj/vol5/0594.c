#include <stdio.h>
#include <math.h>

int main(void){
	int w, h, n, i;
	int x[1000], y[1000];
	int now=0;
	long ans=0;

	scanf(" %d %d %d", &w, &h, &n);
	for(i=0; i<n; i++) scanf(" %d %d", &x[i], &y[i]);
	
	int nx=x[0], ny=y[0];
	
	while(now<n-1){
		if(x[now+1] > nx && y[now+1] > ny){
			while(x[now+1] != nx && y[now+1] != ny){
				++nx;
				++ny;
				++ans;
			}
			
			if(x[now+1] == nx){
				while(y[now+1] != ny) {
					++ny;
					++ans;
				}
			}
			else if(y[now+1] == ny){
				while(x[now+1] != nx) {
					++nx;
					++ans;
				}
			}	
		}
		else if(x[now+1] < nx && y[now+1] < ny){
			while(x[now+1] != nx && y[now+1] != ny){
				--nx;
				--ny;
				++ans;
			}
			
			if(x[now+1] == nx){
				while(y[now+1] != ny) {
					--ny;
					++ans;
				}
			}
			else if(y[now+1] == ny){
				while(x[now+1] != nx) {
					--nx;
					++ans;
				}
			}	
		}
		else{
			ans += fabs(nx-x[now+1]) + fabs(ny-y[now+1]);
			nx = x[now+1];
			ny = y[now+1];
		}
	
		now++;
		//printf("%d %d, %ld\n", nx, ny, ans);
	}
	
	printf("%ld\n", ans);

	return 0;
}