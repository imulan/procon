#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long a, b, n;
	while(cin >> a >> b >> n){
		long s=0;
		long f=a;
		
		for(int i=1; i<=n; ++i){
			f=f%b*10;
			s+=f/b;
		}
		
		printf("%ld\n", s);
	}
}