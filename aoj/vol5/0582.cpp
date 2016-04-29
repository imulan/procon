#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int a[3], x=0, y=0, z=0;
	while( scanf(" %d %d %d", &a[0], &a[1], &a[2]) != EOF ){
		sort(a, a+3);
		if(a[2]>=a[0]+a[1]) break;
	
		if(a[2]*a[2] == a[0]*a[0]+a[1]*a[1]) ++x;
		else if(a[2]*a[2] < a[0]*a[0]+a[1]*a[1]) ++y;
		else ++z;
	
	}
	
	printf("%d %d %d %d\n", x+y+z, x, y, z);

	return 0;
}