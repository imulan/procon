#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	char f[10][10];
	
	//行にあるかどうか
	int w[9]={0}, b[9]={0};
	
	for(int i=1; i<=8; ++i)
	for(int j=1; j<=8; ++j)
	scanf(" %c", &f[i][j]);
	
	int wt=-1,bt=-1;
	//白
	for(int i=1; i<=8; ++i){
		for(int j=1; j<=8; ++j){
			if(f[i][j]=='W'){
					//その上に黒がないか
					bool no=true;
					for(int k=1; k<i; ++k){
						if(f[k][j]=='B'){
							no=false;
							break;	
						}	
					}
					
					if(no){
						wt=i-1;	
						break;
					}
			}
		}
		if(wt!=-1)break;
	}
		
	//黒
	for(int i=8; i>=1; --i){
		for(int j=1; j<=8; ++j){
			if(f[i][j]=='B'){
				//その下に黒がないか
				bool no=true;
				for(int k=i+1; k<=8; ++k){
					if(f[k][j]=='W'){
						no=false;
						break;	
					}	
				}
					
				if(no){
					bt=8-i;	
					break;
				}
			}			
		}
		if(bt!=-1)break;
	}	
	
	//printf("wt:%d, bt:%d\n",wt, bt);
	
	if(wt<=bt) printf("A\n");
	else printf("B\n");
}