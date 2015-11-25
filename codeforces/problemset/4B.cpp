#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int d, sum;
	int min[30], max[30];
	
	scanf(" %d %d", &d, &sum);
	
	int sup=0, inf=0;
	for(int i=0; i<d; ++i){
		scanf(" %d %d", &min[i], &max[i]);
		inf+=min[i];
		sup+=max[i];
	}
	
	if(inf<=sum && sum<=sup){ //ぴったりにできる
		printf("YES\n");
		
		int b=sup-sum; //余裕
		
		for(int i=0; i<d; ++i){
			if(i!=0) printf(" ");
			
			int c=max[i]-min[i]; //削れる時間
			if(b-c>=0){
				printf("%d", min[i]);
				b-=c;
			}
			else if(b>0 && b-c<0){
				printf("%d", max[i]+b-c);
				b+=b-c;
			}
			else printf("%d", max[i]);
		
		}
		
		printf("\n");
	}
	else printf("NO\n"); //無理
}