#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	if('a'<=s[0] && s[0]<='z') s[0]=s[0]-'a'+'A';	
	
	for(int i=1; i<s.size(); ++i) 
		if('A'<=s[i] && s[i]<='Z') s[i]=s[i]-'A'+'a';	
		
	cout << s << endl;
	return 0;
}