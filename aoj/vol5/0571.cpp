#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;

	long p=0;
	long ans=0;
	
	while(p<s.size()){
		if(s[p]=='O'){
			long st=p;
			while(s[p]=='O') p++;
			long ed=p;
			
			long tmplevel=ed-st; //このレベルの可能性
			bool flag=true;
			
			long jst=st-tmplevel;
			if(jst<0) flag=false;
			if(flag){
				for(long i=jst; i<st; ++i){
					if(s[i]!='J') flag=false;	
				}	
			}
			
			long ied=ed+tmplevel;
			if(ied>s.size()) flag=false;
			if(flag){
				for(long i=ed; i<ied; ++i){
					if(s[i]!='I') flag=false;
				}	
			}
			
			if(flag){
				if(ans<tmplevel) ans=tmplevel;	
			}
			p=ed;
		}	
		else p++;
	}
	
	printf("%ld\n", ans);
}