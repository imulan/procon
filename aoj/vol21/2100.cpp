#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int t;
	scanf(" %d", &t);
	for(int tt=0; tt<t; ++tt){
		int n, h[100];
		scanf(" %d", &n);
		for(int i=0; i<n; ++i) scanf(" %d", &h[i]);
		
		int up=0, down=0;
		for(int i=1; i<n; ++i){
			int dif=h[i]-h[i-1];
			if(dif>0){
				if(up<dif) up=dif;
			}
			else{
				dif = -dif;
				if(down<dif) down=dif;
			}		
		}		
		
		printf("%d %d\n", up, down);
	}
}