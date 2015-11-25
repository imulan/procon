#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	
	cin >> n;
	cin >> s;
	
	int ans=0;
	while(1){
		int ct=0;
		bool ed=true;
		while(ct<s.size()-1){
			if(s[ct]!=s[ct+1]){
				if(s=="10" || s=="01"){
					ed=true;
					ans=-1;	
					break;
				}
				else{
					string x = s.substr(0, ct);
					string y = s.substr(ct+2);
					s=x+y;
					ed=false;
					if(ct>0) ct--;
					//cout << "converted to " << s <<endl;
				}
			}
			else ct++;
		}	
		
		if(ed) break;
		//printf("loop\n");
	}
	
	if(ans==-1) printf("0\n");
	else cout << s.size() <<endl;
}
