#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	char ans;
	scanf(" %d %d %d", &a, &b, &c);
	
	bool plus=false, minus=false;
	
	if(c == a+b) plus=true;
	if(c== a-b) minus=true;
	
	if(plus && minus) ans='?';
	else if(plus) ans='+';
	else if(minus) ans='-';
	else ans='!';
	
	printf("%c\n", ans);
	return 0;
}