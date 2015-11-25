#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		double x1,y1,x2,y2,x3,y3;
		scanf(" %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
		double dx=x1, dy=y1; //平行移動
		x1-=dx; x2-=dx; x3-=dx;
		y1-=dy; y2-=dy; y3-=dy;
		
		double ansx, ansy;
		
		if(y2==0){
			ansx = x2/2.0;
			double b3= x3*x3/y3/2.0 + y3/2.0;
			ansy = -x3*ansx/y3+b3;			
		}
		else if(y3==0){
			ansx = x3/2.0;
			double b2= x2*x2/y2/2.0 + y2/2.0;
			ansy = -x2*ansx/y2+b2; 
		}
		else{
			double b2= x2*x2/y2/2.0 + y2/2.0;
			double b3= x3*x3/y3/2.0 + y3/2.0;

			ansx = (b2-b3)*y2*y3/(x2*y3-x3*y2);
			ansy = -x2*ansx/y2+b2; 			
		}
		
		double r=sqrt(ansx*ansx + ansy*ansy);
		//printf("r=%lf\n", r);
		r*=1000;
		r=round(r);
		r/=1000;
		
		printf("%.3lf %.3lf %.3lf\n", ansx+dx, ansy+dy, r);
		
	}	
}