#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	while(1){
		int n, m, atari, d;
		int a[10]; //amida
		string s[30];
		
		scanf(" %d", &n);
		if(n==0) break;
		
		for(int i=0; i<n; ++i) a[i]=i+1;
			
		scanf(" %d %d %d", &m, &atari, &d);
		for(int i=0; i<d; ++i) cin >> s[i];
			
		for(int i=0; i<d; ++i){
			for(int j=0; j<s[i].size(); ++j){
				if(s[i][j]=='1') swap(a[j], a[j+1]);	
			}
		}
		if(m == a[atari-1]){ // 線を引く必要がない
			printf("0\n");
			continue;	
		}
		
		bool flag=true;
		//横線を1つだけ足す
		for(int i=0; i<d; ++i){
			for(int j=0; j<s[i].size(); ++j){
				if(s[i][j]=='1') continue;
				
				int l=j-1, r=j+1;
				if(l>=0 && s[i][l]=='1') continue;
				if(r<n && s[i][r]=='1') continue; 
				
				for(int k=0; k<n; ++k) a[k]=k+1;
				string t[30];
				for(int x=0; x<d; ++x) t[x]=s[x];
				
				t[i][j]='1';
				
				/*
				printf("\n");	
				printf("%d %d\n",i+1 ,j+1);
				for(int x=0; x<d; ++x) cout<<t[x]<<endl;
				printf("\n");
				*/
				
				for(int x=0; x<d; ++x){
					for(int y=0; y<t[x].size(); ++y){
						if(t[x][y]=='1') swap(a[y], a[y+1]);	
					}
				}
				
				/*
				for(int k=0; k<n; ++k) printf("%d ", a[k]);
				printf("\n");
				*/
				
				if(m == a[atari-1]){ // 線を引いたらうまくいった
					printf("%d %d\n",i+1 ,j+1);
					flag=false;
				}	

				if(!flag) break;			
			}
			if(!flag) break;
		}
		
		if(flag) printf("1\n");
	}
}