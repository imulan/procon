#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool check(string a, char c){
	bool ans=false;
	
	for(int i=0; i<3; ++i){
		if(a[0+i]==c && a[3+i]==c && a[6+i]==c) ans=true;
	}
	
	for(int i=0; i<3; ++i){
		if(a[i*3]==c && a[i*3+1]==c && a[i*3+2]==c) ans=true;
	}
	
	if(a[0]==c && a[4]==c && a[8]==c) ans=true;
	if(a[2]==c && a[4]==c && a[6]==c) ans=true;
	
	return ans;
} 

int main(){
	string s;
	while(cin >> s){
		if(check(s, 'o'))
			printf("o\n");
		else if(check(s, 'x'))
			printf("x\n");
		else printf("d\n");
	}
	return 0;
}