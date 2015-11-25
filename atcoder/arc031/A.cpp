#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool ans=true;
	for(int i=0; i<s.size(); ++i){
		if(s[i]!=s[s.size()-1-i]){
			ans=false;
			break;
		}
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}