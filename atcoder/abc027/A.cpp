#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	scanf(" %d %d %d", &a, &b, &c);
	
	int ans;
	if(a==b) ans=c;
	else if(a==c) ans=b;
	else if(b==c) ans=a;
	
	printf("%d\n", ans);
}