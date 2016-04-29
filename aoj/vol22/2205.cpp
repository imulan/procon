#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	while(1){
		int n, m;
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		
		string p[100];
		long prize[100];
		for(int i=0; i<n; ++i) cin >> p[i] >> prize[i];
		
		long ans=0;
		
		for(int i=0; i<m; ++i){
			string s;
			cin >> s;
			
			for(int j=0; j<n; ++j){
				bool hit=true;
				for(int k=0; k<8; ++k){
					if(p[j][k]=='*') continue;
					
					if(s[k]!=p[j][k]) hit=false;
				}
				
				if(hit) ans+=prize[j];
			}
				
		}
				
		printf("%ld\n", ans);
	}
}		