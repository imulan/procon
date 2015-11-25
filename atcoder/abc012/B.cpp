#include <cstdio>
#include <iostream>
using namespace std;

void pt(int a){
	if(a<10) printf("0");	
	printf("%d", a);
}

int main(){
	long n;
	cin >> n;
	int h, m, s;
	
	h=n/3600;
	n-=h*3600;
	m=n/60;
	n-=m*60;
	s=n;
	
	pt(h);
	printf(":");
	pt(m);
	printf(":");
	pt(s);
	printf("\n");

	return 0;
}