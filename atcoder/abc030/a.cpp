#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int a,b,c,d;
	scanf(" %d %d %d %d", &a, &b, &c, &d);
	double TK=(double)b/a;
	double AO=(double)d/c;
	
	if(TK>AO) printf("TAKAHASHI\n");
	else if(TK<AO) printf("AOKI\n");
	else printf("DRAW\n");
}