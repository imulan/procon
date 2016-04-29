#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	int h;
	int m;
}cktime;

int main(){
	int a, b;
	cktime t[101], i[101];
	int nowN=0, nowM=0;
	
	scanf(" %d", &a);
	for(int k=0; k<a; ++k) scanf(" %d %d", &t[k].h, &t[k].m);
	t[a].h=25;
	scanf(" %d", &b);
	for(int k=0; k<b; ++k) scanf(" %d %d", &i[k].h, &i[k].m);
	i[b].h=25;
	
	bool flag=false;
	while(nowN<a || nowM<b){
		cktime p;
		if(flag) printf(" ");
		
		if(t[nowN].h < i[nowM].h) p=t[nowN++];
		else if(t[nowN].h > i[nowM].h) p=i[nowM++];
		else{
			if(t[nowN].m < i[nowM].m) p=t[nowN++];
			else if(t[nowN].m > i[nowM].m) p=i[nowM++];
			else{
				p=t[nowN];
				nowN++;
				nowM++;	
			}
		}	
		
		printf("%d:", p.h);
		if(p.m<10) printf("0");
		printf("%d", p.m);
		flag=true;
	}
	printf("\n");
	
	return 0;
}