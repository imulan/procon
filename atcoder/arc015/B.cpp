#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int n;
	int ans[6];
	memset(ans, 0, sizeof(ans));
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		double a, b;
		scanf(" %lf %lf", &a, &b);
		
		if(a>=35) ans[0]++;
		else if(a>=30) ans[1]++;
		else if(a>=25) ans[2]++;
		
		if(b>=25) ans[3]++;
		else if(b<0 && a>=0) ans[4]++;
		else if(b<0) ans[5]++;
	}
	
	for(int i=0; i<6; ++i){
		if(i>0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}