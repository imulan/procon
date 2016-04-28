#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	while(1){
		int n, x, y, h, w;
		long p=0;
		
		cin >> n;
		if(n==0) break;
		
		for(int i=0; i<n; ++i){
			scanf(" %d %d %d %d", &x, &y, &h, &w);
			
			int s = x+y+h;
			
			if(s<=60 && w<=2) p+=600;
			else if(s<=80 && w<=5) p+=800;
			else if(s<=100 && w<=10) p+=1000;
			else if(s<=120 && w<=15) p+=1200;
			else if(s<=140 && w<=20) p+=1400;
			else if(s<=160 && w<=25) p+=1600;
			else ;
		}
	
		printf("%ld\n", p);
	}

	return 0;
}