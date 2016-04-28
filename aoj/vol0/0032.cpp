#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a, b, c, x=0, y=0;
	while( scanf(" %d,%d,%d", &a, &b, &c) != EOF ){
		
		if(c*c == a*a+b*b) ++x;
		else if(a==b) ++y;
	
	}
	
	printf("%d\n%d\n", x, y);

	return 0;
}