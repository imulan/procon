#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	while(1){
		int n, x[4], y[4], count=0;
		bool flag = false;
		
		cin >> n;
		if(n==0) break;
	
		while(n!=6174){
			int a=0, b=0;
			//printf("%d\n", n);
			
			for(int i=0; i<4; ++i){
				x[i] = (n%(int)pow(10, 4-i) - n%(int)pow(10, 3-i)) / (int)pow(10, 3-i);
				y[i] = (n%(int)pow(10, 4-i) - n%(int)pow(10, 3-i)) / (int)pow(10, 3-i);
			}
			if(x[0]==x[1] && x[1]==x[2] && x[2]==x[3]){
				flag=true;
				break;
			}	
		
			sort(x, x+4);
			for(int i=0; i<4; ++i)
				a+=pow(10,3-i)*x[i];
			
			sort(y, y+4, greater<int>());
			for(int i=0; i<4; ++i)
				b+=pow(10,3-i)*y[i];
	
			n=b-a;
			
			++count;
		}
	
		if(flag) printf("NA\n");
		else printf("%d\n", count);
	}
	
	return 0;
}