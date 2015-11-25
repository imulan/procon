#include <iostream>
#include <cstdio>
using namespace std;

#define N 30000

void printtime(int a){
	int h=a/60, m=a%60;	
	
	if(h<10) printf("0");
	printf("%d", h);
	if(m<10) printf("0");
	printf("%d", m);
}

int main(){
	int n, s[N], e[N];
	
	scanf(" %d", &n);
	
	for(int i=0; i<n; ++i){
		scanf(" %d-%d", &s[i], &e[i]);
		int a = (s[i]/100)*60 + s[i]%100;
		s[i] = a - (a%5);
		
		a = (e[i]/100)*60 + e[i]%100;
		if(a%5!=0) e[i] = a + 5 - (a%5);
		else e[i] = a;
		
		//printf("s=%d, e=%d", s[i], e[i]);
	}
	
	int rain[290] = {0}; //289=24*12+1
	
	for(int i=0; i<n; ++i)
		for(int j=s[i]/5; j<e[i]/5; ++j) rain[j]=1;
	
	bool flag=true;
	
	for(int i=0; i<290; ++i){
		
		//printf("rain[%d] = %d\n",i, rain[i]);
		
		if(flag && rain[i]==1){ //降り始め
			printtime(i*5);
			printf("-");
			flag=false;
		}
			
		if(!flag && rain[i+1]==0){ //降りおわり
			printtime((i+1)*5);
			printf("\n");
			flag=true;
		}
	}
	
	return 0;
}