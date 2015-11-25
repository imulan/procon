#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, a, b, s[100000];
	int min=1100000000, max=-1;
	
	long sum=0;
	//input
	scanf(" %d %d %d", &n, &a, &b);
	for(int i=0; i<n; ++i){
		scanf(" %d", &s[i]);
		sum+=s[i];
		if(s[i]<min) min=s[i];
		if(max<s[i]) max=s[i];
	}
	
	double p=1,q=1; 
	if(min==max) printf("-1\n");
	else{
		p=(double)b/(max-min);
		q=(double)a-p*sum/n;	
		printf("%.8lf %.8lf\n", p, q);
	}
	
}