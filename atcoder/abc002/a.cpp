#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long x, y;
	scanf(" %ld %ld", &x, &y);
	printf("%ld\n", (x>y) ? x : y);
	return 0;
}