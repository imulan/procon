#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	int L;
	int R;
}permission;

int main(){
	int n, d, k;
	permission p[10000];
	
	scanf(" %d %d %d", &n, &d, &k);
	for(int i=0; i<d; ++i) scanf(" %d %d", &p[i].L, &p[i].R);
	
	for(int i=0; i<k; ++i){
		int s, t, ans=0;
		scanf(" %d %d", &s, &t);
		
		bool right=(s<t);
		int pos=s; 
		
		//printf("right?:%d\n", right);
		
		for(int j=0; j<d; ++j){
			if(p[j].L<=pos && pos<=p[j].R){
				if(right) pos=p[j].R;
				else pos=p[j].L;	
			}
			
			if(right){
				if(pos>=t){ans=j+1; break;}	
			}
			else{
				if(pos<=t){ans=j+1; break;}	
			}	
		}	
		
		printf("%d\n", ans);
	}	
}