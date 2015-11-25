#include <cstdio>
#include <cmath>

int main(){
	while(1){
		int n, i;
		double r=1, t=0;
		
		scanf(" %d", &n);
		if(n==-1) break;
		
		for(i=1; i<n; i++){
			t += atan(1/r);
			r = sqrt(r*r + 1);
		}
		
		printf("%.2lf\n%.2lf\n", r*cos(t), r*sin(t) );
	}

	return 0;
}
