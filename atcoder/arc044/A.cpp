#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	bool p=true;
	if(n%2==0) p=false;
	
	for(int i=3; i<=sqrt(n); i+=2){
		//printf("i= %d\n", i);
		if(n%i==0){
			p=false;
			break;	
		}	
	}	
	
	bool ans=true;
	if(p) ans=true; //素数
	else{ //合成数
		if(n%2==0) ans=false;
		if(n%5==0) ans=false;
		
		int s=0;
		int q=n;
		while(q>0){
			s+=q%10;
			q/=10;	
		}
		//printf("s=%d\n", s);
		if(s%3==0) ans=false;
	}
	
	if(n==1) ans=false;
	if(n==2) ans=true;
	
	if(ans) printf("Prime\n");
	else printf("Not Prime\n");
	
}