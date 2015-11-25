#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, sum=0;
	cin >> n;
	
	for(int i=1; i<10; ++i)
		for(int j=1; j<10; ++j) 
			sum+=i*j;
	
	int ans=sum-n;
	
	for(int i=1; i<10; ++i){
		if(ans%i==0 && ans/i<10)	
			printf("%d x %d\n", i, ans/i);
	}
	
	return 0;
}