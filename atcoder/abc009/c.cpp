#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int fit(char *a, char *b, int size){
	int num[26][2]={0}; //それぞれの文字列のアルファベット数
	int ret=0;
	
	for(int i=0; i<size; ++i){
		num[a[i]-'a'][0]++;	
		num[b[i]-'a'][1]++;
	}
	
	for(int i=0; i<26; ++i){
		ret += min(num[i][0], num[i][1]);	
	}
		
	return ret;
}

int main(){
	int n, k;
	char s[101], t[101], ss[101];
	string ans="";
	
	scanf(" %d %d", &n, &k);
	scanf(" %s", s);
	
	strcpy(t, s);
	sort(t, t+n);
	//tにはsの文字が小さい方から順に並んでいる。
	
	for(int i=0; i<n; ++i){
		int size=0;
		char sub[101]; //次に入る文字の候補
		char remain[101]; //sのi番目以下の文字列
		
		//subとremainの作成
		for(int j=0; j<n; ++j){
			if(t[j] == '0') continue;
			sub[size++]=t[j];	
		}
		sort(sub, sub+size);
		
		for(int j=i+1; j<n; ++j){
			remain[j-i-1]=s[j];	
		}	
		
		
		for(int j=0; j<size; ++j){
			int limit=k;
			char c=sub[j]; //次の文字がsubのj番目の文字として
			sub[j] = '0';
			if(s[i] != c) limit--;
			
			//subのj文字目以外で構成される文字列を作る
			int p=0;
			char nex[101];
			for(int z=0; z<size; ++z){
				if(sub[z]!='0') nex[p++]=sub[z];
			}
			
			//printf("i:%d,j:%d\n",i,j);
			if( size-1-fit(nex, remain, p) <= limit ){ //次の文字にできるなら
				ans += c;	
				if(s[i] != c) --k; //違う文字が入るなら異なって良い文字は1つ減る
				
				for(int i=0; i<n; ++i){
					if(t[i]==c){
						t[i]='0'; //すでに使われた文字
						break;	
					}
				}
				
				break;
			}
			else sub[j]=c;
			
		}
		
	}
	
	cout << ans <<endl;
	return 0;
}