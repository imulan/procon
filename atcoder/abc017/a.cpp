#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int s, e;
	int ans=0;
	
	for(int i=0; i<3; ++i){
		scanf(" %d %d", &s, &e);	
		ans+=s*e/10;
	}
	
	printf("%d\n", ans); 
	return 0;
}