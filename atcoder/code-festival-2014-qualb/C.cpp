#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string x, y, z;
	int a[26]={0}, b[26]={0}, c[26]={0};
	
	cin >> x;	
	cin >> y;	
	cin >> z;	
	
	for(int i=0; i<x.size(); ++i){
		a[x[i]-'A']++;
		b[y[i]-'A']++;	
		c[z[i]-'A']++;
	}
	
	//for(int i=0; i<26; ++i) printf("%c : %d %d %d\n", 'A'+i, a[i], b[i], c[i]);	
		
	int small[26], large[26];
	int S=0, L=0;
	for(int i=0; i<26; ++i){
		small[i]=max(0,c[i]-b[i]); //xから取る最低限必要な文字数	
		large[i]=min(a[i],c[i]); //xから取る上限
		
		S+=small[i];
		L+=large[i];
	}
	
	if(S <= x.size()/2 && x.size()/2 <= L) printf("YES\n");
	else printf("NO\n");
	
}