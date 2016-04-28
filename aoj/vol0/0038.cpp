#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int c[5];
	while( scanf(" %d,%d,%d,%d,%d", &c[0], &c[1], &c[2], &c[3], &c[4]) != EOF ){
		sort(c, c+5);
		
		//four card
		bool flag=true;
		for(int i=0; i<=2; ++i){
			if(c[i] != c[i+1]) flag=false;
		}
		if(flag){
			printf("four card\n");
			continue;
		}
		flag=true;
		for(int i=1; i<=3; ++i){
			if(c[i] != c[i+1]) flag=false;
		}
		if(flag){
			printf("four card\n");
			continue;
		}
		
		//full house
		flag=false;
		if(c[0]==c[1] && c[2]==c[3] && c[3]==c[4]) flag=true;
		if(c[0]==c[1] && c[1]==c[2] && c[3]==c[4]) flag=true;
		if(flag){
			printf("full house\n");
			continue;
		}
		
		//straight	
		flag=true;	
		for(int j=0; j<=4; ++j){
			if(c[j]!=c[0]+j) flag=false;
		}
		if(flag){
			printf("straight\n");
			continue;
		}

		if(c[0]==1){
			flag=true;
			for(int i=1; i<=4; ++i){
				if(c[i]!=9+i) flag=false;	
			}	
		}
		if(flag){
			printf("straight\n");
			continue;
		}
		
		//three card
		flag=false;
		for(int i=0; i<=2; ++i)
			if(c[i]==c[i+1] && c[i+1]==c[i+2]) flag=true;
		if(flag){
			printf("three card\n");
			continue;
		}	
		
		//two pair
		flag=false;
		if(c[0]==c[1] && c[2]==c[3]) flag=true;
		if(c[0]==c[1] && c[3]==c[4]) flag=true;
		if(c[1]==c[2] && c[3]==c[4]) flag=true;
		if(flag){
			printf("two pair\n");
			continue;
		}	

		//one pair
		flag=false;
		for(int i=0; i<=3; ++i)
			if(c[i]==c[i+1]) flag=true;		
	
		if(flag){
			printf("one pair\n");
			continue;
		}	

		//null
		printf("null\n");
	}
}