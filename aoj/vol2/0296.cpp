#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int money[6]={1,5,10,50,100,500};
	long sum=0;
	for(int i=0; i<6; ++i){
		int a;
		scanf(" %d", &a);
		sum+=a*money[i];	
	}
	
	printf("%d\n", sum>=1000);
	return 0;
}