#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
	
		string s;
		int d[6]={1,2,3,4,5,6};
		long ans=1;
		
		for(int i=0; i<n; ++i){
			cin >> s;
			
			int tmp;
			if(s=="North"){
				tmp=d[0];
				d[0]=d[1];
				d[1]=d[5];
				d[5]=d[4];
				d[4]=tmp;
				
				ans+=d[0];
			}
			else if(s=="East"){
				tmp=d[0];
				d[0]=d[3];
				d[3]=d[5];
				d[5]=d[2];
				d[2]=tmp;
				
				ans+=d[0];
			}
			else if(s=="West"){
				tmp=d[0];
				d[0]=d[2];
				d[2]=d[5];
				d[5]=d[3];
				d[3]=tmp;
				
				ans+=d[0];				
			}
			else if(s=="South"){
				tmp=d[0];
				d[0]=d[4];
				d[4]=d[5];
				d[5]=d[1];
				d[1]=tmp;
				
				ans+=d[0];
			}
			else if(s=="Right"){
				tmp=d[1];
				d[1]=d[2];
				d[2]=d[4];
				d[4]=d[3];
				d[3]=tmp;
				
				ans+=d[0];
			}
			else if(s=="Left"){
				tmp=d[1];
				d[1]=d[3];
				d[3]=d[4];
				d[4]=d[2];
				d[2]=tmp;
				
				ans+=d[0];
			}
			
			//printf("now:%d\n", d[0]);
		}
		
		printf("%ld\n", ans);
	}
	return 0;
}