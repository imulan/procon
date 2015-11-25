#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	for(int i=0; i<1000; ++i){
		string s;
		cin >> s;
		bool ans=true;
		int p=0;
		while(p<s.size()-1){
			if(s[p]=='A'){
				if(s[p+1]=='B' || s[p+1]=='D');
				else ans=false;
			}
			else if(s[p]=='B'){
				if(s[p+1]=='A' || s[p+1]=='C' || s[p+1]=='E');
				else ans=false;
			}
			else if(s[p]=='C'){
				if(s[p+1]=='B' || s[p+1]=='F');
				else ans=false;
			}
			else if(s[p]=='D'){
				if(s[p+1]=='A' || s[p+1]=='E' || s[p+1]=='G');
				else ans=false;
			}
			else if(s[p]=='E'){
				if(s[p+1]=='B' || s[p+1]=='D' || s[p+1]=='F' || s[p+1]=='H');
				else ans=false;
			}
			else if(s[p]=='F'){
				if(s[p+1]=='C' || s[p+1]=='E' || s[p+1]=='I');
				else ans=false;
			}
			else if(s[p]=='G'){
				if(s[p+1]=='D' || s[p+1]=='H');
				else ans=false;
			}
			else if(s[p]=='H'){
				if(s[p+1]=='E' || s[p+1]=='G' || s[p+1]=='I');
				else ans=false;
			}
			else if(s[p]=='I'){
				if(s[p+1]=='F' || s[p+1]=='H');
				else ans=false;
			}
				
			if(!ans) break;
			++p;
		}
		
		if(ans) cout << s << endl;
	}	
}