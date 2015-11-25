#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	long x;
	long y;
}point;

int main(){
	int n;
	point p[100];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %ld %ld", &p[i].x, &p[i].y);
	
	long ans=0;
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			for(int k=j+1; k<n; ++k){
				long ax=p[j].x-p[i].x, ay=p[j].y-p[i].y;
				long bx=p[k].x-p[i].x, by=p[k].y-p[i].y;
				
				long s=ax*by-ay*bx;
				if(s<0) s=-s;
				
				if(s!=0 && s%2==0) ++ans;
			}
		}
	}
	
	printf("%ld\n", ans);
}