#include <cstdio>
#include <iostream>
using namespace std;

double waterTemp(int t1, int v1, int t2, int v2){
	return (double)(t1*v1+t2*v2)/(v1+v2);	
}

int main(){
	int T,D,ta,tb,da,db;
	
	cin >> T >> D;
	cin >> ta >> tb;
	cin >> da >> db;
	
	double diff=100000;
	
	for(int i=0; i*da<=D; ++i){
		for(int j=0; i*da+j*db<=D; ++j){
			double tmp = waterTemp(ta,i*da,tb,j*db);
			double td = tmp-T;
			if(td<0) td=-td;
			
			if(td<diff) diff=td;
		}	
	}
	
	printf("%.10lf\n", diff);
}