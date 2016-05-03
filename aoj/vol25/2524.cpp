#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string s;
	int now=0; //分割位置
	int ans=0;
	
	cin >> s;
	
	while(now<=s.size()){
		long p=0, q=0;
		stringstream ss1, ss2;
		
		if(s[now]!='0'){ //先頭を0にすることは不可
			
			for(int i=0; i<now; ++i) ss1<<s[i];
			for(int i=now; i<s.size(); ++i) ss2<<s[i];
			
			ss1>>q;
			ss2>>p;
			
			//printf("p=%ld, q=%ld\n", p, q);
			
			if(p-q>=0 && (p+q)%2==0) ++ans;
		}
		now++;
	}
	
	printf("%d\n", ans);
}