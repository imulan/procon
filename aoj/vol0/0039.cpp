#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	string t="IVXLCDM";
	int m[7]={1, 5, 10, 50, 100, 500, 1000};
	
	while(cin >> s){
		long ans=0;
		int size=s.size();
		
		for(int i=0; i<size; ++i){
			int p=0, q=0;
			while(s[i] != t[p]) p++;
			if(i+1<size) while(s[i+1] != t[q]) q++;
			 
			if(p<q) ans -= m[p];
			else ans += m[p];
		}
		
		printf("%ld\n", ans);
	}
}