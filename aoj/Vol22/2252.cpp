#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	char r[12]="yuiophjklnm";
	
	while(cin >> s){
		if(s=="#") break;
		
		int ans=0;
		bool right=false;
		
		for(int i=0; i<12; ++i){
			if(s[0]==r[i]){	
		   		right=true;
				break;
			}
		}
		
		for(int i=1; i<s.size(); ++i){
			bool before = right;
			
			for(int j=0; j<12; ++j){
				if(s[i]==r[j]){	
		   			right=true;
					break;
				}
				
				if(j==11) right=false;
			}	
			
			if(before != right) ++ans;
		}
		printf("%d\n", ans);
	}		
	return 0;
}