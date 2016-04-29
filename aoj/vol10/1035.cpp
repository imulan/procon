#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int w, q;
		int a[101];
		
		scanf(" %d %d", &w, &q);
		if(w==0) break;
		
		memset(a, -1, sizeof(a));
		for(int i=0; i<q; ++i){
			char order;
			scanf(" %c", &order);
			
			if(order=='s'){
				int x, y;
				scanf(" %d %d", &x, &y);	
				
				bool flag=true;
				for(int i=0; i+y<=w; ++i){
					if(a[i]==-1){
						bool sl=true;
						for(int j=0; j<y; ++j){
							if(a[i+j]!=-1){
								sl=false;
								break;	
							}
						}
						
						if(sl){
							for(int j=0; j<y; ++j) a[i+j]=x;	
							printf("%d\n", i);
							flag=false;
						}	
					}
					
					if(!flag) break;
				}
				
				if(flag) printf("impossible\n");
			}
			else if(order=='w'){
				int z;
				scanf(" %d", &z);
				
				for(int i=0; i<w; ++i){
					if(z==a[i]) a[i]=-1;	
				}
				
			}
			
		}
		printf("END\n");
	}
} 