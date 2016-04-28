#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const double EBS=1e-8;

int main(){
	while(1){
		int m, v[400];
		int arg=360;
		double a=0, b=0;
		
		scanf(" %d", &m);
		if(m==0) break;
		for(int i=0; i<m-1; ++i){
			scanf(" %d", &v[i]);
			arg-=v[i];
			a+=sin(v[i]*M_PI/180.0);
		}
		a+=sin(arg*M_PI/180.0);
		
		arg=360;
		scanf(" %d", &m);
		for(int i=0; i<m-1; ++i){
			scanf(" %d", &v[i]);
			arg-=v[i];
			b+=sin(v[i]*M_PI/180.0);
		}
		b+=sin(arg*M_PI/180.0);
		
		//printf(" a=%lf, b=%lf\n", a, b);
			
		if(fabs(a-b) < EBS) printf("0\n");
		else if(a>b) printf("1\n");
		else if(a<b) printf("2\n");
	}
}