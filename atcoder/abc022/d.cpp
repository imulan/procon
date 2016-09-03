#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	double x;
	double y;
}point;

int main(){
	long n;
	scanf(" %ld", &n);
	
	point a[100000], b[100000], ag, bg;
	double alen=0, blen=0;
	ag.x=0;
	ag.y=0;
	bg.x=0;
	bg.y=0;
	
	//for A
	for(long i=0; i<n; ++i){
		scanf(" %lf %lf", &a[i].x, &a[i].y);
		ag.x+=a[i].x;
		ag.y+=a[i].y;
	}
	
	ag.x/=n;
	ag.y/=n;
	
	for(long i=0; i<n; ++i){
		double dist2=(a[i].x-ag.x)*(a[i].x-ag.x) + (a[i].y-ag.y)*(a[i].y-ag.y);
		alen=max(alen, sqrt(dist2));
	}
		
	//for B
	for(long i=0; i<n; ++i){
		scanf(" %lf %lf", &b[i].x, &b[i].y);
		bg.x+=b[i].x;
		bg.y+=b[i].y;
	}
	bg.x/=n;
	bg.y/=n;
	
	for(long i=0; i<n; ++i){
		double dist2=(b[i].x-bg.x)*(b[i].x-bg.x) + (b[i].y-bg.y)*(b[i].y-bg.y);
		blen=max(blen, sqrt(dist2));
	}
	
	//answer
	printf("%.10lf\n", blen/alen);
}