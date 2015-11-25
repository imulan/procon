#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		char sn[201];	
		scanf(" %s", sn);
		int length = strlen(sn);
		
		bool A=false, B=false;
		
		if(sn[0]=='>'){
			if(sn[1]=='\''){ //Aの可能性
				int p=2;
				int c1=0, c2=0;
				
				while(sn[p]=='='){
					c1++;
					p++;
				}
				
				if(sn[p++]=='#'){
					while(sn[p]=='=')
				
				
				}
				
			}
			else if(sn[1]=='^'){ //Bの可能性
				int p=2;
				
				
			}
		}
	}
	
	return 0;
}