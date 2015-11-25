#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	long ans=0;
		
	cin >> s;
	
	long a=0;
	while(a<s.size()-1){
		if(s[a]=='2' && s[a+1]=='5'){
			long count=1;
			a+=2;
			while(a<s.size()-1 && s[a]=='2' && s[a+1]=='5'){
				a+=2;
				++count;	
			}
			ans+=count*(count+1)/2;
		}
		else ++a;
		
		//printf("now a=%ld\n",a);
	}
		
	printf("%ld\n", ans);
	
	return 0;
}