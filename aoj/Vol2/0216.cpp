#include <iostream>
#include <cstdio>

int main(void){
	while(1){
		int w;
		scanf(" %d", &w);
		if(w==-1) break;
		
		int price = 1150;
		if(w<=10){}
		else if(w<=20){
			price += (w-10)*125;
		}
		else if(w<=30){
			price += 1250 + (w-20)*140;
		}
		else{	
			price += 1250 + 1400 + (w-30)*160;
		}
	
		printf("%d\n", 4280-price);
	
	}

	return 0;
}