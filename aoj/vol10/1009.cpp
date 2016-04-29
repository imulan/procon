#include <iostream>
#include <cstdio>

using namespace std;

void swap(int *x, int *y){
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

int main(){
	long a, b;
	while( scanf(" %ld %ld", &a, &b) != EOF ){
		if(a<b) swap(a,b);
		
		if(b!=0){
			while(b!=0){
				long r=a%b;
				a=b;
				b=r;
			}
		}
		printf("%ld\n", a);
	}
	
	return 0;
}