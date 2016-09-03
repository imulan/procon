#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int i, j;
	string s, t;
	bool ans=true;
	char check[9]="@atcoder";
	
	cin >> s;
	cin >> t;
	
	for(i=0; i<s.size(); ++i){	
			
		if(s[i]=='@'){
			for(j=0; j<9; ++j){
				if(check[j]==t[i]) break;		
			}
			if(j==9) ans=false;
		}
		else if(t[i]=='@'){
			for(j=0; j<9; ++j){
				if(check[j]==s[i]) break;		
			}
			if(j==9) ans=false;		
		}
		else if(s[i]!=t[i]) ans=false;
		
		if(!ans) break;
	}
	
	if(ans) printf("You can win\n");
	else printf("You will lose\n");
	
	return 0;
}