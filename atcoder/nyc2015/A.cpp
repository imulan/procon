#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	long n;
	int c; //桁数
	int bin[100];
	scanf(" %ld", &n);
	
	for(c=0; c<100; ++c){
		if(n < pow(2, c)) break;
	}
	
	int a=c-1;
	while(n > 0){
		bin[a]=n%2;
		n=n/2;
		a--;
	}
	
	//for(int i=0; i<c; ++i) printf("%d\n", bin[i]);
	
	bool ans=true;
	for(int i=0; i<c; ++i){
		if(bin[i] != bin[c-1-i]){
			ans=false;
			break;	
		}
	}
	
	if(ans) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}