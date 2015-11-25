#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	
	int red=0, blue=0;
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		
		for(int j=0; j<s.size(); ++j){
			if(s[j]=='R') red++;
			else if(s[j]=='B') blue++;
		}	
	}
	
	if(red>blue) printf("TAKAHASHI\n");
	else if(red<blue) printf("AOKI\n");
	else printf("DRAW\n");
}