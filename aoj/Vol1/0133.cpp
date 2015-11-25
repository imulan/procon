#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	char f[8][9];
	
	for(int i=0; i<8; ++i)
		scanf(" %s", f[i]);
		
	printf("90\n");
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			printf("%c", f[7-j][i]);	
		}
		printf("\n");
	}
	
	printf("180\n");
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			printf("%c", f[7-i][7-j]);	
		}
		printf("\n");
	}
	
	printf("270\n");
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			printf("%c", f[j][7-i]);	
		}
		printf("\n");
	}
	
	return 0;
}