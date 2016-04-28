#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int a, b;
	int c[101];
	memset(c, 0, sizeof(c));
	
	while(cin >> a >> b){
		if(a==0 && b==0){
			int odd=0;
			for(int i=3; i<=100; ++i){
				if(c[i]%2==1) odd++;	
			}
			
			bool ans=false;
			if(c[1]%2==1 && c[2]%2==1 && odd==0) ans=true;
			
			if(ans) printf("OK\n");
			else printf("NG\n");
			
			memset(c, 0, sizeof(c));			
		}
		else{
			c[a]++;
			c[b]++;	
		}
	}
}