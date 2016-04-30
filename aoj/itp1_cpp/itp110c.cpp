#include <cstdio>
#include <cmath>

int main(){
	while(1){
		int n, s[1000];
		double m=0, alpha=0;
		
		scanf(" %d", &n);
		if(n==0) break;
		
		for(int i=0; i<n; ++i){
			scanf(" %d", &s[i]);
			m += s[i];
		}
		
		m /= (double)n;
		
		for(int i=0; i<n; ++i)
			alpha += pow(s[i]-m, 2.0);
		alpha /= (double)n;
		
		printf("%lf\n", sqrt(alpha));
	}	
		return 0;
}