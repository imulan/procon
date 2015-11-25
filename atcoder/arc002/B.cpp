#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int y, m, d;
	
	scanf(" %d/%d/%d", &y, &m, &d);

	//printf("   %d/%d/%d\n", y,m,d);
	
	//うるう年判定
	bool uru=false;
	if(y%4==0){
		if(y%100==0){
			if(y%400==0) uru=true;
			else uru=false;	
		}
		else uru=true;
	}
	
	//月ごとの日の数
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(uru) day[1]++;
		
	while(1){
		if(y%(m*d)==0) break;	
		
		d++;
		
		if(day[m-1]+1==d){ //月末になったら次の月
			m++;	
			d=1;
		}
		
		if(m==13){
			m=1;
			y++;
		}
	}	

	printf("%d/", y);
	if(m<10) printf("0");
	printf("%d/", m);
	if(d<10) printf("0");
	printf("%d\n", d);
	
}