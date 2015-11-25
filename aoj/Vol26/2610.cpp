#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	int ans=0;
	
	scanf(" %d", &n);
	if(n==0) ans=1;
	else if(n==1) ans=2;
	else if(n==2) ans=1;
	
	printf("%d\n", ans);
}