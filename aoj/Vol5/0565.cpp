#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int p[3], j[2];
	
	for(int i=0; i<3; ++i) scanf(" %d", &p[i]);
	for(int i=0; i<2; ++i) scanf(" %d", &j[i]);
	sort(p, p+3);
	sort(j, j+2);
	
	printf("%d\n", p[0]+j[0]-50);
	return 0;
}