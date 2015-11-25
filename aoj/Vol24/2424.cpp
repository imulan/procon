#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

long kakezan(long a){
	int d=0, num[7];
	long t=a;
	
	while(t>0){
		++d;
		t/=10; 
	}
	//printf("d=%d\n", d);
	t=a;
	for(int i=0; i<d; ++i){
		num[d-i-1]=t%10;
		t/=10;	
	}
	/*	
	for(int i=0; i<d; ++i)
		printf("num[%d]=%d\n", i,num[i]);
	*/
	long ret=0;
	
	for(int i=1; i<d; ++i){ //分割位置
		long x=0, y=0;
		
		for(int j=0; j<i; ++j){
			x += num[j]*pow(10, i-j-1);	
		}
		
		for(int j=i; j<d; ++j){
			y += num[j]*pow(10, d-1-j);	
		}
		
		if(ret<x*y) ret=x*y;
	} 
	
	return ret;
}

int main(){
	int q;	
	long lim=10000000;
	
	scanf(" %d", &q);
	for(int i=0; i<q; ++i){
		long n, count=0;
		scanf(" %ld", &n);
		
		while(n>9 && count<lim){
			n=kakezan(n);
			++count;
			//printf(" %ld\n", n);
		}	
		
		if(count==lim) printf("-1\n");
		else printf("%ld\n", count);
	}
	
	return 0;
}