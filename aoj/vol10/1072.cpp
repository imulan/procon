#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int r, c;
		scanf(" %d %d", &r, &c);
		if(r==0) break;
		
		if(r%2==1 && c%2==1) printf("no\n");
		else printf("yes\n");		
	}
}