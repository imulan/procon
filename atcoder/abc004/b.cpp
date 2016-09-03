#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	char f[4][8];
	for(int i=0; i<4; ++i){
		for(int j=0; j<8; ++j){
			scanf("%c", &f[i][j]);
		}
	}
	
	for(int i=3; i>=0; i--){
		for(int j=6; j>=0; j--){
			printf("%c", f[i][j]);
		}
		printf("\n");
	}
	return 0;
}