#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;

int judge(int a){
	int ret=0;
	
	if(a==0){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				int b1=0, w1=0, b2=0, w2=0, b3=0, w3=0;
				ret=0;
				
				for(int k=1; k<=n; ++k){
					if(f[i][j][k]==0){
						b1=0;
						w1=0;
					}
					else if(f[i][j][k]==1) b1++;
					else if(f[i][j][k]==2) w1++;
					
					if(f[i][k][j]==0){
						b2=0;
						w2=0;
					}
					else if(f[i][k][j]==1) b2++;
					else if(f[i][k][j]==2) w2++;

					if(f[i][j][k]==0){
						b3=0;
						w3=0;
					}
					else if(f[k][i][j]==1) b3++;
					else if(f[k][i][j]==2) w3++;
	
					if(b1==m || b2==m || b3==m) ret=1;
					if(w1==m || w2==m || w3==m) ret=2;
					
					if(ret!=0) break;
				}
				if(ret!=0) break;					
			}
			if(ret!=0) break;
		}
	}
	else if(a<7){
		
	}
	else if(a<11){
		
		
	}
	
	return ret;
}


int main(){
	while(1){
		int p;
		int f[8][8][8];
		int h[8][8];
		
		scanf(" %d %d %d", &n, &m, &p);
		if(n==0)	 break;
		
		memset(f, 0, sizeof(f));
	
		for(int i=1; i<=7; ++i)
		for(int j=1; j<=7; ++j)
		h[i][j]=1;
	
		for(int i=0; i<p; ++i){
			int a, b;
			scanf(" %d %d", &a, &b);	
			f[a][b][ h[i][j]++ ] = (i%2)+1 //black=1, white=2
			
			
			
		}
		
		
	}
}