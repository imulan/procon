#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	while(1){
		int r, a, hit=0, blow=0;
		int x[4], y[4]; 
		
		cin >> r >> a;
		if(r==0 && a==0) break;
	
		for(int i=0; i<4; ++i){
			x[i] = (r%(int)pow(10, 4-i) - r%(int)pow(10, 3-i)) / (int)pow(10, 3-i);
			y[i] = (a%(int)pow(10, 4-i) - a%(int)pow(10, 3-i)) / (int)pow(10, 3-i);
		}
	
		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				if(x[i]==y[j]){
					if(i==j) ++hit;
					else ++blow;
				}
			}
		}
	
		printf("%d %d\n", hit, blow);
	}

	return 0;
}