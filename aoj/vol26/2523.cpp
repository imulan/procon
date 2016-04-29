#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const long LIMIT=1000000000;

int main(){
	unsigned long long n, t, ans=0;
	string s;
	int p[10], pp=0;
	
	cin >> n >> t;
	cin >> s;
	
	int now=0;
	while(now<s.size()){
		p[pp++]=s[now+2]-'0';	
		now+=4;
	}
	sort(p, p+pp);
	
	bool tle=false;
	for(int i=0; i<pp; ++i){
		unsigned long long tmp=1;
		for(int j=0; j<p[i]; ++j){
			tmp*=n;
			if(tmp>LIMIT){
				tle=true;
				break;
			}
		}		
		if(tle) break;
		else{
			tmp*=t;	
			if(tmp>LIMIT){
				tle=true;
				break;
			}
			
			ans+=tmp;
		}
		
		if(ans>LIMIT){
			tle=true;
			break;
		}
	}
	
	if(tle) printf("TLE\n");
	else cout << ans << endl;
}