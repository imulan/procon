#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	char a[4]="abc";
	
	int n;
	cin >> n;
	
	for(int i=0; i<pow(3,n); ++i){
		int b[8]={0};
		int cp[8]={0};
		
		int p=i;
		int index=0;
		
		while(index<n){
			b[index++] = p%3;
			p/=3;	
		}
		
		//printf("index= %d\n", index);
		
		for(int j=0; j<index; ++j) cp[index-j-1] = b[j];
		
		//output
		for(int j=0; j<index; ++j) printf("%c", a[cp[j]]);
		printf("\n");
	}

}