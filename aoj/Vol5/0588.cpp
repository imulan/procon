#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long n, a;
	char c;
	
	scanf(" %ld", &n);
	
	while(1){	
		scanf(" %c", &c);
		if(c=='=') break;
		else{
			long a;
			scanf(" %ld", &a);
			
			if(c=='+') n+=a;
			else if(c=='-') n-=a;
			else if(c=='*') n*=a;
			else if(c=='/') n/=a;
		}
	}	
	
	printf("%ld\n", n);

	return 0;
}