#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int a, sum=0;

	for(int i=0; i<10; ++i){
		cin >> a;
		sum += a;
	}

	printf("%d\n", sum);
	
	return 0;
}