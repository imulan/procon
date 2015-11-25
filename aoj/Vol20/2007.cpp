#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	bool flag=false;
	
	while(1){
		int n, m[4];
		int ans[4]={0}, tmp[4], x[4];
		int money[4]={10, 50, 100, 500};
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<4; ++i){
			scanf(" %d", &m[i]);
			ans[i]=m[i];
		}
		
		for(int a=0; a<=m[0]; ++a){ //10
			int now1=n;
			int t1=now1%50;
			
			if(t1<=a*10){
				if( (now1-a*10)%50 != 0 ) continue;
			}
			now1 -= a*10;
			
			for(int b=0; b<=m[1]; ++b){ //50
				int now2=now1;
				int t2=now2%100;
				printf("t2=%d\n",t2);
			
				if(t2<=b*50){
					if( (now2-b*50)%100 != 0 ) continue;
				}
				now2 -= b*50;
					
				for(int c=0; c<=m[2]; ++c){ //100
					int now3=now2;
					int t3=now3%500;
					printf("t3=%d\n",t3);
			
					
					if(t3<=c*100){
						if( (now3-c*100)%500 != 0 ) continue;
					}
					now3 -= c*100;
					
					for(int d=0; d<=m[3]; ++d){ //500
						if(now3-d*500<=-500) break;
						
						//printf(" %d %d %d %d\n", a, b, c, d);
								
						int charge=-(now3-d*500);
							
						if(charge>=0){
							
							tmp[3]=m[3]-d+charge/500;
							charge-=(charge/500)*500;
							
							tmp[2]=m[2]-c+charge/100;
							charge-=(charge/100)*100;
							
							tmp[1]=m[1]-b+charge/50;
							charge-=(charge/50)*50;
							
							tmp[0]=m[0]-a+charge/10;
							charge-=(charge/10)*10;
							
							//printf("%d %d %d %d -> %d %d %d %d\n", a, b, c, d, tmp[0], tmp[1], tmp[2], tmp[3]);
							
							int t1=0, t2=0;
							for(int i=0; i<4; ++i){
								t1+=ans[i];
								t2+=tmp[i];
							}
							if(t2<t1){
								for(int i=0; i<4; ++i){
									ans[i]=tmp[i];	
									x[i]=m[i]-tmp[i];
								}
							}
						}
						
					}	
				}	
			}
		}
		
		if(flag) printf("\n");
		for(int i=0; i<4; ++i){
			if(x[i] > 0) printf("%d %d\n", money[i], x[i]);
		}
		flag=true;
	}	
	return 0;
}