#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int count=0, ans=0, base[3];
		for(int i=0; i<3; ++i) base[i]=0; //初期化

		while(count<3){
			string s;
			cin >> s;
			if(s=="HIT"){
				if(base[2]==1) ++ans;
				base[2]=base[1];
				base[1]=base[0];
				base[0]=1;
			}
			else if(s=="HOMERUN"){
				for(int i=0; i<3; ++i) {
					ans+=base[i];
					base[i]=0;
				}
				++ans;
			}
			else if(s=="OUT") ++count;
		}
		
		printf("%d\n", ans);
	}
	return 0;	
}