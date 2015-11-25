#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a, b;
	
	scanf(" %d %d", &a, &b);
	if(a<0) a=-a;
	if(b<0) b=-b;
	
	if(a<b) printf("Ant\n");
	else if(a>b) printf("Bug\n");
	else printf("Draw\n");
}