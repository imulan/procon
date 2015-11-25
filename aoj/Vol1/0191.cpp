#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
double g[100][100];
double dp[101][100];

double rec(int a, int b){ //a回目，前に与えた肥料b
	if(dp[a][b]>0) return dp[a][b];
	
	double ret=1.0;

	if(a==m-1) ret=1.0;
	else{
		double t=-1;
		for(int i=0; i<n; ++i){
			double s=g[b][i]*rec(a+1, i);	
			//printf("s=%lf\n", s);
			if(s>t) t=s;
		}
		ret=t;
		//printf("t=%lf\n", t);
	}
	
	return dp[a][b]=ret;
}

int main(){
	while(1){
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		scanf(" %lf", &g[i][j]);
		
		for(int i=0; i<101; ++i)
		for(int j=0; j<100; ++j)
		dp[i][j]=-1.0;		
		
		double ans=0;
		for(int i=0; i<n; ++i){
			double tmp=rec(0, i);
			if(tmp>ans) ans=tmp;	
		}
		
		/*
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				printf("%.4lf ", dp[i][j]);		
			}
			printf("\n");
		}
		*/
		
		ans*=100;
		ans=round(ans);
		ans/=100;
		printf("%.2lf\n", ans);
	}
}	