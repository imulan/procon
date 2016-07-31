#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	long ans=0;
	
	cin >> s;
	long len=s.size();
	
	bool flag=true;
	long ct=0;
	for(long i=0 ; i<len; ++i){
		if(s[i] == s[len-1-i]) ct++;
	}
	
	if(ct!=len) flag=false;
	
	//printf("kaibun? %d\n", flag);
	
	if(len==1) ans=0;
	else if(ct<len-2) ans=len*25;
	else if(ct==len) ans=25*2*(len/2);
	else{
		for(long i=0 ; i<len; ++i){
			long a=25; //アルファベットから元と同じ文字を除く
			if(s[i] != s[len-1-i]) a--;
			ans+=a;
		}
	}	
	
	printf("%ld\n", ans);
}
	