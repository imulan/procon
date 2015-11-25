#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long n, m;
		string s;
		scanf(" %ld", &n);
		if(n==0) break;
		scanf(" %ld", &m);
		cin >> s;
		
		long a=0;
		long ans=0;
		long lim=m-2*n-1;
		while(a<m){
			long ct=0;
			if(s[a]=='I'){
				while(a<m && s[a+1]=='O' && s[a+2]=='I'){
					a+=2;
					ct++;
				}
				ct = ct-n+1;
				if(ct>0)ans+=ct;
			}
			++a;
			//printf("%ld\n", a);
		}
		
		printf("%ld\n", ans);
	}	
}