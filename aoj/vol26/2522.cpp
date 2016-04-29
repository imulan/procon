#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	bool ans=true;
	
	if(s.size()<6) ans=false;
	
	int a=0, b=0, c=0;
	for(int i=0; i<s.size(); ++i){
		if('0'<=s[i] && s[i]<='9') a++;
		else if('A'<=s[i] && s[i]<='Z') b++;
		else if('a'<=s[i] && s[i]<='z') c++;
	}
	
	if(a==0 || b==0 || c==0) ans=false;
	
	if(ans) printf("VALID\n");
	else printf("INVALID\n");
}