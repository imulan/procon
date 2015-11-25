#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int lim=60*12;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n;++i){
		int h, m;
		scanf(" %d:%d", &h, &m);
		
		//printf("h=%d,m=%d\n", h, m);
		
		int now=h*60+m;
		
		double arg1=(double)now/(double)lim*360;
		double arg2=m*6;
		
		double arg=fabs(arg1-arg2);
		if(arg>180) arg=360-arg;
		
		if(arg<30) printf("alert\n");
		else if(arg<90) printf("warning\n");
		else if(arg<=180) printf("safe\n");
	}
	return 0;
}