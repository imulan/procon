#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		if(s==".") break;
		stack<int> st;
		bool ans=true;
		
		while(!st.empty()) st.pop();
		
		for(int i=0; i<s.size(); ++i){
			if(s[i]=='(') st.push(1);	
			else if(s[i]=='[') st.push(2);
			
			if(s[i]==')'){
				if(st.empty()) ans=false;
				else{
					int ch=st.top();
					st.pop();
					if(ch!=1) ans=false;
				}	
			}
			else if(s[i]==']'){
				if(st.empty()) ans=false;
				else{
					int ch=st.top();
					st.pop();
					if(ch!=2) ans=false;	
				}	
			}
			
			if(!ans) break;
		}
		
		if(!st.empty()) ans=false;
		if(s[s.size()-1] != '.') ans=false;
		
		if(ans) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}