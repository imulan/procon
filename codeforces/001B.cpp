#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	long n;
	
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i){
		string s;
		cin >> s;
		
		bool flag=false;
		int now=0;
		while(now<s.size()){
			if('0'<=s[now]	&& s[now]<='9') flag=true;		
			
			if(flag && s[now]=='C'){
				flag=false;
				break;
			}
			now++;
		}
	
		//printf("%d\n", flag);
		
		if(flag){ //toRXCY
			long r=0, c=0;
			
			int now=0;
			while('A'<=s[now] && s[now]<='Z'){
				c=c*26+(s[now]-'A'+1);
				now++;	
			}
			
			stringstream ss;
			while(now<s.size()) ss<<s[now++];
			istringstream is(ss.str());
			is>>r;
			is.clear();
			
			printf("R%ldC%ld\n", r, c);
		}
		else{ //fromRXCY
			long r, c;
			
			int now=1;
			stringstream ss1;
			while(s[now]!='C') ss1<<s[now++];
			now++;
			istringstream is1(ss1.str());
			is1>>r;
						
			stringstream ss2;
			while(now<s.size()) ss2<<s[now++];
			istringstream is2(ss2.str());
			is2>>c;
				
			//printf(" %ld %ld\n", r, c);

			now=0;
			int p[100];
			while(c!=0){
				int t=c%26;
				if(t==0){
					t=26;
					c-=26;
				}
				p[now]=t;
				p[now+1]=-1;
				now++;
				c/=26;
			}
			
			for(int i=now-1; i>=0; i--) printf("%c", 'A'+p[i]-1);
			printf("%ld\n", r); 
		}
		
	}
		
}