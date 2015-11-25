#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int max=0;
	int now=0;
	string s[1000];
	while(getline(cin,s[now])){
		if(s[now].size() > max) max=s[now].size();
		now++;
	}
	
	for(int i=0; i<max+2; ++i) printf("*");
	printf("\n");

	int tt=1;
	for(int i=0; i<now; ++i){
		printf("*");	
		int len=s[i].size();
		
		int b;
		
		if(s[i].size()>0 && s[i].size()%2!=max%2){
			//真ん中に来ない時には
			tt=(tt+1)%2; //左寄せ，右寄せは交互に
			b=(max-len)/2+tt;
			//printf("tt=%d\n",tt);
		}
		else b=(max-len)/2;
		
		for(int j=0; j<b; ++j) cout<<" ";
		cout<<s[i];
		for(int j=0; j<max-len-b; ++j) cout<<" ";		
		
		cout<<"*"<<endl;
	}	
	
	
	for(int i=0; i<max+2; ++i) printf("*");
	printf("\n");
}