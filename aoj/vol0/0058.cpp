#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps=1e-10;

int main(){
	while(1){
		double x[4], y[4];
		bool flag=false;
		
		for(int i=0; i<4; ++i){
			if(scanf(" %lf %lf", &x[i], &y[i]) == EOF){
				flag=true;
				break;
			}
		}
		if(flag) break;
		
		if( fabs((x[1]-x[0])*(x[3]-x[2]) + (y[1]-y[0])*(y[3]-y[2])) <= eps) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}