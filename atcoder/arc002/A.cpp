#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int y;
	cin >> y;
	
	bool ans=false;
	if(y%4==0){
		if(y%100==0){
			if(y%400==0) ans=true;
			else ans=false;	
		}
		else ans=true;
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
}