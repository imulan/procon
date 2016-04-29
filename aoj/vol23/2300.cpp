#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	double L;
	double a;
	double b;
}color;

double dist(color x, color y){
	double p=x.L-y.L, q=x.a-y.a, r=x.b-y.b;
	return p*p+q*q+r*r;
}

int main(){
	int n, m;
	color c[20];
	double max=0;
	
	scanf(" %d %d", &n, &m);
	
	for(int i=0; i<n; ++i){
		scanf(" %lf %lf %lf", &c[i].L, &c[i].a, &c[i].b);
	}
	
	for(int i=(1<<n)-1; i>0; --i){
		int ct=0;
		for(int j=0; j<n; ++j){
			if((i>>j) & 1) ct++;	
		}	
		if(ct!=m) continue;
		
		//mビット分だけ1になっている(1になっているものが色の候補)
		int nums[20];
		int pp=0;
		for(int j=0; j<n; ++j){
			if((i>>j) & 1) nums[pp++]=j; //使う色番号のメモ
		}
		
		/*
		printf("   now:: i= %d\n", i);
		for(int j=0; j<pp; ++j){
			printf("nums[%d]=%d\n", j, nums[j]);		
		}
		*/
		
		//sum of distances
		double tmp=0;
		for(int j=0; j<pp; ++j){
			for(int k=j+1; k<pp; ++k){
				tmp+=dist(c[nums[j]], c[nums[k]]);
			}
		}
		//printf(" tmp= %lf\n", tmp);
		
		if(tmp>max) max=tmp;
	}

	printf("%lf\n", max);
}