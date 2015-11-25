#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	while(1){
		char n[9];
		int index, c[3] = {0};
		double min = 1000, d;
	
		scanf(" %s", n);
		if(strcmp(n, "0") == 0) break;
		
		for(int i=0; i<3; i++){
			if(n[2*i+1] <= '9') c[i] += 16*(n[2*i+1]-'0');
			else c[i] += 16*(n[2*i+1]-'a'+10);
			
			if(n[2*i+2] <= '9') c[i] += n[2*i+2]-'0';
			else c[i] += n[2*i+2]-'a'+10;
		}
		
		/*for(int i=0; i<3; i++)
			printf("%d ", c[i]);*/
		
		for(int i=0; i<8; i++){
			int p;
			if(i%4==0 || i%4==1) p=0;
			else p=1;
		
			d=sqrt( pow(c[0]-(i/4)*255, 2) + pow(c[1]-p*255, 2) + pow(c[2]-(i%2)*255, 2) );
			if(min > d){
				min = d;
				index = i;
			}
		}
		
		if(index==0) printf("black\n");
		else if(index==1) printf("blue\n");
		else if(index==2) printf("lime\n");
		else if(index==3) printf("aqua\n");
		else if(index==4) printf("red\n");
		else if(index==5) printf("fuchsia\n");
		else if(index==6) printf("yellow\n");
		else if(index==7) printf("white\n");

	}

	return 0;
}