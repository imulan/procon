#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string s, t;
	cin >> s;
	cin >> t;
	
	bool ans=true;
	
	while(s.size() < t.size()){
		int i=0;
		bool pass=false;
		//printf("s.size=%lu\n", s.size());
		for(i=0; i<s.size(); ++i){
			if(s[i] != t[i]){
				printf("p\n");
				
				if(i==0){
					ans=false;	
					break;
				}
				else if(s[i-1] == t[i]){
					ans=false;
					break;
				}
				else{
					s.insert(s.begin()+i, t[i]);	
					break;
				}	
			}
		}
		
		if(i==s.size()){
			printf("pp\n");
			if(s[i-1] == t[i]) ans=false;			
			else s.insert(s.begin()+i, t[i]);	
		}
			
		cout << s << endl;
		if(!ans) break;
	}
	
	if(s!=t) ans=false;
	
	if(ans) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}