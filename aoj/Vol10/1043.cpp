#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;

typedef struct{
	int num;
	int u;
	int ac;
	long p;
}team;


int main(){
	while(1){
		int n;
		team t[300];
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %d %d %d %ld", &t[i].num, &t[i].u, &t[i].ac, &t[i].p);
		
		//sort
		for(int i=0; i<n; ++i){
			for(int j=i+1; j<n; ++j){
				
				if(t[i].ac<t[j].ac) swap(t[i],t[j]);
				else if(t[i].ac==t[j].ac){
					if(t[i].p>t[j].p) swap(t[i],t[j]);
					else if(t[i].p==t[j].p){
						if(t[i].num>t[j].num) swap(t[i],t[j]);
					}
				}
				
			}
		}
		
		//for(int i=0; i<n; ++i) printf(" %d %d %d %ld\n", t[i].num, t[i].u, t[i].ac, t[i].p);
		
		int now=0;
		int bel[1001]; //所属から選ばれたチーム数	
		bool sel[1001]; //選ばれたかどうか
		
		memset(bel, 0, sizeof(bel));
		for(int i=0; i<=1000; ++i) sel[i]=false;
		
		for(int i=0; i<n; ++i){
			if(sel[t[i].num]) continue;
			
			if(bel[t[i].u]<3){
				printf("%d\n", t[i].num);
				sel[t[i].num]=true;
				bel[t[i].u]++;
				now++;
			}
			
			if(now==10) break;
		}
	
		for(int i=0; i<n; ++i){
			if(sel[t[i].num]) continue;
			
			if(bel[t[i].u]<2){
				printf("%d\n", t[i].num);
				sel[t[i].num]=true;	
				bel[t[i].u]++;
				now++;
			}
			
			if(now==20) break;
		}
	
		for(int i=0; i<n; ++i){
			if(sel[t[i].num]) continue;
			
			if(bel[t[i].u]<1){
				printf("%d\n", t[i].num);
				sel[t[i].num]=true;	
				bel[t[i].u]++;
				now++;
			}
			
			if(now==26) break;
		}
	

	}
}