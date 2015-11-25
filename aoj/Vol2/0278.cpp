#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		int x, y, b, p;
		scanf(" %d %d %d %d", &x, &y, &b, &p);
		
		int price = ( ((b>=5) ? b : 5)*x+((p>=2) ? p : 2)*y)*0.8;
		if(price > x*b+y*p) price=x*b+y*p;
	
		printf("%d\n", price);
	}

	return 0;
}