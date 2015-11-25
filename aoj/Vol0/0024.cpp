#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	double v;
	while(cin >> v){
		double 	t=v/9.8;
		int n=1;
		while(5*n-5 <= 4.9*t*t) ++n;
		printf("%d\n", n);
	}
	return 0;
}