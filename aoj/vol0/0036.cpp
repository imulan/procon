#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	char f[9][9];
	while(1){
		bool flag=false;
		
		for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				if( scanf(" %c", &f[i][j])==EOF){
					flag=true;
					break;
				}
			} 
			if(flag) break;	
		}
		if(flag) break;

		bool ans=false;
		char c='1';
		for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				
				if(f[j][i]==c){
					if(i<=6 && j<=6 && f[j+1][i]==c && f[j][i+1]==c && f[j+1][i+1]==c){
						printf("A\n");	
						ans=true;
						break;
					}
					else if(j<=4 && f[j+1][i]==c && f[j+2][i]==c && f[j+3][i]==c){
						printf("B\n");	
						ans=true;
						break;
					}
					else if(i<=4 && f[j][i+1]==c && f[j][i+2]==c && f[j][i+3]==c){
						printf("C\n");	
						ans=true;
						break;
					}
					else if(1<=j && j<=6 && i<=6 && f[j+1][i]==c && f[j][i+1]==c && f[j-1][i+1]==c){
						printf("D\n");	
						ans=true;
						break;
					}
					else if(j<=6 && i<=5 && f[j][i+1]==c && f[j+1][i+1]==c && f[j+1][i+2]==c){
						printf("E\n");	
						ans=true;
						break;
					}
					else if(j<=5 && i<=6 && f[j+1][i]==c && f[j+1][i+1]==c && f[j+2][i+1]==c){
						printf("F\n");	
						ans=true;
						break;
					}
					else if(1<=j && i<=5 && f[j][i+1]==c && f[j-1][i+1]==c && f[j-1][i+2]==c){
						printf("G\n");	
						ans=true;
						break;
					}
											
				}
	
			}
			if(ans) break;
		}
			
	}
}