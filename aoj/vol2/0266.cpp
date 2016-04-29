#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int a[6][2];
	for(int i=0; i<6; ++i)
		for(int j=0; j<2; ++j) a[i][j]=-1;
	a[0][0]=1; a[0][1]=2; a[1][1]=3; a[2][0]=1; a[3][0]=4; a[3][1]=5; a[4][0]=5; a[4][1]=2; a[5][0]=2; a[5][1]=1;	
	
	while(1){
		string s;
		cin >> s;
		if(s=="#") break;
		
		int now=0;
		for(int i=0; i<s.size(); ++i){
			now=a[now][(int)(s[i]-'0')];
			//printf(":::%dnow=%d\n",s[i]-'0',now);
			if(now==-1) break;
		}
		
		if(now==5) printf("Yes\n");
		else printf("No\n"); 
	}
	return 0;
}