#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int f;
	int s;
}point;

int main(){
	while(1){
		char f[12][12];
		
		bool flag=false;
		for(int i=0; i<12; ++i){
			for(int j=0; j<12; ++j){
				if(scanf(" %c", &f[i][j]) == EOF){
					flag=true;
					break;
				}	
			}
			if(flag) break;
			//printf("%d ok\n", i);
		}
		if(flag) break;
		//printf("ok\n");
		
		int ans=0;
		int df[4]={0,1,0,-1}, ds[4]={1,0,-1,0};
		
		for(int i=0; i<12; ++i){
			for(int j=0; j<12; ++j){
				if(f[i][j]!='1') continue;
				
				//printf("%d %d\n", i, j);
				++ans;
				
				point st;
				st.f=i; st.s=j;
				f[i][j]='c';
				queue<point> que;
				que.push(st);
				
				while(!que.empty()){
					point v=que.front();
					que.pop();
					for(int k=0; k<4; ++k){
						int nf=v.f+	df[k], ns=v.s+ds[k];
						if(nf>=0 && nf<12 && ns>=0 && ns<12 && f[nf][ns]=='1'){
							f[nf][ns]='c';
							point tmp;
							tmp.f=nf;
							tmp.s=ns;	
							que.push(tmp);
							//printf("push %d %d\n", nf, ns);
						}	
					}
				}
						
			}
		}
		
		printf("%d\n", ans);
	}
}