#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	int bus[15]={0,1,2,3,4,5,6,7,8,9,5,4,3,2,1};
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int a, b;
		scanf(" %d %d", &a, &b);
		
		if(a==0 || 5<a){ //1通りしかありえない
			int start=0, goal;
			while(bus[start] != a) start++;
			
			goal=start;
			bool flag=false;
			while(1){
				if(flag) printf(" ");
				printf("%d", bus[goal%15]);
				if(bus[goal%15] == b) break;
				goal++;
				flag=true;
			}
			printf("\n");
		}
		else{ //2通りある
			int start=0, goal, count1=0, count2=0;
			
			while(bus[start] != a) start++;
			goal=start;
			while(bus[goal%15] != b){
				goal++;
				count1++;
			}
			
			start++;
			int tmp=0;
			while(bus[start%15] != a) start++;
			goal=start;
			while(bus[goal%15] != b){
				goal++;
				count2++;
			}
			
			if(count1 < count2) goal=a;
			else goal=15-a;
			
			bool flag=false;
			while(1){
				if(flag) printf(" ");
				
				printf("%d", bus[goal%15]);
				if(bus[goal%15] == b) break;
				goal++;
				flag=true;
			}
			printf("\n");
			
		}
		
	}
	return 0;
}