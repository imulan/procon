#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double x1, y1, x2, y2, xq, yq, x, y;
	
	while( scanf(" %lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &xq, &yq) != EOF){
	
		if(x1==x2){ //y軸と平行
			y=yq;		
			x=2*x1-xq;
		}
		else if(y1==y2){ //x軸と平行
			x=xq;
			y=2*y1-yq;
		}
		else{
			double m=(y1-y2)/(x1-x2);
			double n=-1.0/m;
			
			double b1=y1-m*x1, b2=yq-n*xq;
			double xm=(b2-b1)/(m-n);
			double ym=n*xm+b2;
			
			x=2*xm-xq;
			y=2*ym-yq;
		}
		
		printf("%lf %lf\n", x, y);
	}
	return 0;
}