#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int color[3], r, g, b;
	long ans=10000000;
	
	for(int i=0; i<3; ++i) scanf(" %d", &color[i]);
	r=-100-color[0]/2;
	g=-color[1]/2;
	b=100-color[2]/2+1;
	
	if(r+color[0]-1<g && g+color[1]-1<b){ //3色全部中心でokのとき		
		ans=0;
		for(int i=0; i<3; ++i){
			for(int j=0; j<=color[i]/2; ++j) ans+=2*j;
			if(color[i]%2==0) ans-=color[i]/2;
			//printf("now:%ld\n", ans);
		}
	}
	else{
		for(g=-300; g<=200; g++){ //緑の左端の位置
			long t=0;
			
			for(int i=g; i<=g+color[1]-1; i++) t+=fabs(i);
			
			long rt=10000000;
			for(r=-500; r<=g-color[0]; r++){
				long a=0;
				for(int i=r; i<=r+color[0]-1; i++) a+=fabs(i+100);
				if(a<rt) rt=a;
			}
			//printf("rt=%ld\n",rt);
			
			long bt=10000000;
			for(b=g+color[1]; b<=500; b++){
				long a=0;
				for(int i=b; i<=b+color[2]-1; i++) a+=fabs(i-100);
				if(a<bt) bt=a;
			}
			//printf("%d:bt=%ld\n",g+color[1], bt);
		
			t+=rt+bt;
			//printf("t= %ld\n", t);
		
			if(t<ans) ans=t;
		}
	}

	printf("%ld\n", ans);
	
	return 0;
}