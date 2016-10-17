#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int L;
	int b[100000];
	
	scanf(" %d", &L);
	for(int i=0; i<L; ++i) scanf(" %d", &b[i]);
	
	int p=b[0];
	for(int i=1; i<L-1; ++i) p = p^b[i];
	
	bool existAns=true;
	if(p!=b[L-1]) existAns=false;
	
	if(!existAns) printf("-1\n");
	else{
		int a=0;
		printf("%d\n", a);
		for(int i=0; i<L-1; ++i){
			a = a^b[i];
			printf("%d\n", a);	
		}	
	}
}