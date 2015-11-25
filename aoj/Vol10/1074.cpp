#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

typedef struct{
	string name;
	int popularity;
	bool scene[30];
}character;

int main(){
	while(1){
		int n;
		character c[20];
		
		for(int i=0; i<20; ++i){
			c[i].popularity=0;
			for(int j=0; j<30; ++j) c[i].scene[j]=false;
		}
		
		scanf(" %d", &n);
		if(n==0) break;	
		
		for(int i=0; i<n; ++i){
			int m;
			
			cin >> c[i].name;
			scanf(" %d", &m);
			
			for(int j=0; j<m; ++j){
				int a;
				scanf(" %d", &a);
				c[i].scene[a]=true;	
			}		
		}
		
		for(int i=0; i<30; ++i){ //シーン数
			int count=0;
			for(int j=0; j<n; ++j){
				if(c[j].scene[i]) ++count;	
			}
			for(int j=0; j<n; ++j){
				if(c[j].scene[i]){
					c[j].popularity+=n-count+1;	
				}	
			}
		}
		
		for(int i=0; i<n; ++i){
			for(int j=i; j<n; ++j){
				if(c[i].popularity > c[j].popularity) swap(c[i], c[j]);
				else if(c[i].popularity == c[j].popularity){
					if(c[i].name > c[j].name) swap(c[i], c[j]);	
				}
			}
		}
		
		cout << c[0].popularity << " " << c[0].name << endl;
	}
}