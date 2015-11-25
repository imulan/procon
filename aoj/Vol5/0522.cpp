#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string s;
	
	while(cin >> s){
		int joi=0, ioi=0;
	
		int len=(int)s.size();
	
		if(len>=3){
			for(int i=0; i<len-2; ++i){
				if(s[i]=='J'){
					if(s[i+1]=='O' && s[i+2]=='I') ++joi;
				}
				else if(s[i]=='I'){
					if(s[i+1]=='O' && s[i+2]=='I') ++ioi;
				}
			}
		}
	
		printf("%d\n%d\n", joi, ioi);
	}
	
	return 0;
}