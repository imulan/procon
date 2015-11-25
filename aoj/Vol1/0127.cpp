#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		if(s.size()%2!=0) {
			printf("NA\n");
			continue;
		}
		
		int now=0;
		bool flag=false;
		string ans="";
		
		while(now<s.size()){
			int a=s[now]-'0', b=s[now+1]-'0';
			int p=(a-1)*5+b-1;
			
			//printf("a,b,p=%d,%d,%d\n",a,b,p);
			
			if(a<1 || 6<a || b<1 || 5<b){
				flag=true;
				break;
			}
			else if(p<=25) {
				string tmp(1,p+'a');
				ans.append(tmp);
			}
			else if(p==26) ans.append(".");
			else if(p==27) ans.append("?");
			else if(p==28) ans.append("!");
			else if(p==29) ans.append(" ");
			 
			now+=2;	
		}
		
		if(flag) printf("NA\n");
		else cout << ans << endl;
	}
	return 0;
}