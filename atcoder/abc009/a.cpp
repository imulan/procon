#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	
	if(n%2==1) ++n;
	printf("%d\n", n/2);
	
	return 0;
}