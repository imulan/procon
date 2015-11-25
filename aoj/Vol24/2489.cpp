#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	
	bool ans=true;
	int a=n, b=n;
	while(ans){
		if(a>=0){	
			stringstream ss1;
			ss1<<a;
			string s=ss1.str();
			
			bool flag=true;
			for(int i=0; i<s.size(); ++i){
				if(s[i] != s[s.size()-1-i]) flag=false;	
			}
			
			if(flag){
				ans=false;
				printf("%d\n", a);
				break;	
			}
			a--;
		}
		
		stringstream ss2;
		ss2<<b;
		string t=ss2.str();
		
		bool flag=true;
		for(int i=0; i<t.size(); ++i){
			if(t[i] != t[t.size()-1-i]) flag=false;	
		}
			
		if(flag){
			ans=false;
			printf("%d\n", b);
				break;	
		}
		b++;
	}
}