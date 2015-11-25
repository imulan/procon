#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main(){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
	
		string s[100000];
		s[0]="%";
		int now=0;
		
		for(int i=0; i<n; ++i){
			string ss;
			getline(cin, ss);	
			istringstream sin(ss);
			while(sin>>s[++now]);
		}
		
		char target;
		scanf(" %c", &target);
		
		sort(s, s+now);
		
		bool flag=false;
		for(int i=1; i<now; ++i){
			if(s[i][0]==target && s[i]!=s[i-1]){
				if(flag) printf(" ");
				cout << s[i] << flush;
				flag=true;
			}
		}	
		printf("\n");
	}
	return 0;
}