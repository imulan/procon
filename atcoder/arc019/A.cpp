#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	for(int i=0; i<s.size(); ++i){
		if(s[i]=='O') s[i]='0';
		else if(s[i]=='D') s[i]='0';
		else if(s[i]=='I') s[i]='1';
		else if(s[i]=='Z') s[i]='2';
		else if(s[i]=='S') s[i]='5';
		else if(s[i]=='B') s[i]='8';
	}
	
	cout << s << endl;
}