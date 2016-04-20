/*p.47 貪欲法*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N=2000;

int main(){
	int n;
	char s[MAX_N];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i)
		scanf(" %c", &s[i]);
	
	int a=0, b=n-1, count=0;
	
	while(a<=b){
		bool left=false;
		
		for(int i=0; a+i<=b; ++i){
			if(s[a+i] < s[b-i]){
				left=true;
				break;
			}
			else if(s[a+i] > s[b-i]){
				left=false;
				break;
			}
		}
		
		if(left) putchar(s[a++]);
		else putchar(s[b--]);
		++count;
		if(count%80==0) putchar('\n');
	} 

	putchar('\n');

	return 0;
}