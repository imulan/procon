#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

typedef struct{
	int num;
	int pr[11]; //waの数，acしたら-1
	int ac;
	long time;
}team;

int main(){
	while(1){
		int M, T, P, R;
		team a[51];
		
		scanf(" %d %d %d %d", &M, &T, &P, &R);
		if(M==0) break;
		
		//初期化
		for(int i=1; i<=50; ++i){
			a[i].num=i;	
			for(int j=1; j<=10; ++j) a[i].pr[j]=0;
			a[i].ac=0;
			a[i].time=0;
		}
		
		
		for(int i=0; i<R; ++i){
			int m, t, p, j;
			scanf(" %d %d %d %d", &m, &t, &p, &j);
			
			if(j!=0){ //不正解
				a[t].pr[p]++;
			}
			else{ //正解
				if(a[t].pr[p]==-1) continue;
				
				a[t].ac++;
				a[t].time+=m+20*a[t].pr[p];	
				a[t].pr[p]=-1;
			}
		}	
		
		//sort
		for(int i=1; i<=T; ++i){
			for(int j=i; j<=T; ++j){
				if(a[i].ac < a[j].ac) swap(a[i], a[j]);
				else if(a[i].ac == a[j].ac){
					
					if(a[i].time > a[j].time) swap(a[i], a[j]);
					else if(a[i].time == a[j].time){
						
						if(a[i].num < a[j].num) swap(a[i], a[j]);
					}					
				}
				
			}
		}
			
		//for(int i=1; i<=T; ++i) printf("%d :ac%d, tine%ld\n", a[i].num, a[i].ac, a[i].time);
		
		for(int i=1; i<=T; ++i){
			printf("%d", a[i].num);
			if(i<T){
				if(a[i].ac==a[i+1].ac && a[i].time==a[i+1].time) printf("=");
				else printf(",");
			}
		}
		printf("\n");
	}
	return 0;
}