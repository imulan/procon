#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int num;
	double h, w;
	while( scanf(" %d,%lf,%lf", &num, &w, &h) != EOF )
		if(w/h/h >= 25.0) printf("%d\n", num);
	return 0;
}