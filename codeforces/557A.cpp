#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	long n, a[3], b[3];
	
	scanf(" %ld", &n);
	for(int i=0; i<3; ++i) scanf(" %ld %ld", &a[i], &b[i]);
	
	long lim=a[1]+a[2];
	
	long f, s, t;
	f=min(b[0],n-lim);
	
	n -= f;
	s=min(b[1],n-a[2]);
	t=n-s;
	
	printf("%ld %ld %ld\n",f, s, t); 
}