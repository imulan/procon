#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	long n ,blood[4]={0};
	char s[3];
	while(scanf(" %ld,%s", &n, s)!=EOF){
		if(strcmp(s,"A")==0) ++blood[0];
		else if(strcmp(s,"B")==0) ++blood[1];
		else if(strcmp(s,"AB")==0) ++blood[2];
		else if(strcmp(s,"O")==0) ++blood[3];
	}
	
	for(int i=0; i<4; ++i) printf("%ld\n", blood[i]);

	return 0;
}