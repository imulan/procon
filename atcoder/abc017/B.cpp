#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int a=0;
	bool ans=true;
	
	cin >> s;
	
	while(a<s.size() && ans){
		
		if(s[a]=='o' || s[a]=='k' || s[a]=='u') ++a;
		else if(s[a]=='c'){
			++a;
			if(a==s.size()){
				ans=false;	
			}	
			
			if(s[a]=='h') ++a;
			else ans=false;
		}
		else ans=false;
		
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}