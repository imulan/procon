#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char SmallToLarge(char x){
	return x-'a'+'A';
}

char LargeToSmall(char x){
	return x-'A'+'a';	
}

int main(){
	string s;
	char c;
	while(cin >> s >> c){
		if(c=='X') break;
		
		string t=s;
		//UpperCmaelCase変換
		if('a'<=s[0] && s[0]<='z'){
			bool underscore=false;
			for(int i=0; i<s.size(); ++i){
				if(s[i]=='_'){
					underscore=true;
					break;	
				}	
			}	
			
			stringstream ss;
			ss << SmallToLarge(s[0]);
			
			if(underscore){
				for(int i=1; i<s.size(); ++i){
					if(s[i]=='_') continue;
					
					if(s[i-1]=='_') ss << SmallToLarge(s[i]);
					else ss << s[i];
				}
			}
			else for(int i=1; i<s.size(); ++i) ss << s[i];	
			
			t=ss.str();
		}
		
		//cout << t <<endl;
		
		if(c=='L') t[0]=t[0]-'A'+'a';
		else if(c=='D'){
			stringstream tt;
			tt<<LargeToSmall(t[0]);
			for(int i=1; i<t.size(); ++i){
				if('A'<=t[i] && t[i]<='Z'){
					tt<<'_';
					tt<<LargeToSmall(t[i]);	
				}
				else tt<<t[i];	
			}
			
			t=tt.str();
		}
		
		cout << t <<endl;		
		
	}
}