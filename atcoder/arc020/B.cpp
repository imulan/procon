#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, c, a[100];
	
	scanf(" %d %d", &n, &c);
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
			
	long p=1000;
	for(int i=1; i<=10; ++i){ //1番めの色
		for(int j=1; j<=10; ++j){ //2番めの色
			if(i==j) continue;
			long tmp=0;
			
			for(int k=0; k<n; ++k){
				if(k%2==0){
					if(a[k]!=i) ++tmp;
				}
				else{
					if(a[k]!=j) ++tmp;
				}
			}
			
			if(p>tmp) p=tmp;
		}
	}
		
	printf("%ld\n", p*c);
}