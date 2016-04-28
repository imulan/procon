#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
	int no;
	double time;
}person;


int main(){
	person p[24];
	double a[8], b[8], c[8], loser[18], f[8];
	
	for(int i=0; i<8; ++i) {
		scanf(" %d %lf", &p[i].no, &p[i].time);
		a[i]=p[i].time;
	}
	for(int i=0; i<8; ++i) {
		scanf(" %d %lf", &p[i+8].no, &p[i+8].time);
		b[i]=p[i+8].time;
	}
	for(int i=0; i<8; ++i) {
		scanf(" %d %lf", &p[i+16].no, &p[i+16].time);
		c[i]=p[i+16].time;
	}
		
	sort(a, a+8);
	f[0]=a[0]; f[1]=a[1];
	sort(b, b+8);
	f[2]=b[0]; f[3]=b[1];
	sort(c, c+8);
	f[4]=c[0]; f[5]=c[1];
	
	//for(int i=0; i<6; ++i) printf("f[%d]=%lf\n", i, f[i]);
	
	for(int i=2; i<8; ++i) loser[i-2]=a[i];
	for(int i=2; i<8; ++i) loser[i-2+6]=b[i];
	for(int i=2; i<8; ++i) loser[i-2+12]=c[i];
	
	sort(loser, loser+16);
	f[6]=loser[0]; f[7]=loser[1];
	
	for(int i=0; i<8; ++i){
		for(int j=0; j<24; ++j){
			if(f[i]==p[j].time){
				printf("%d %.2lf\n", p[j].no, p[j].time);
			}
		}
	}
	
	return 0;
}