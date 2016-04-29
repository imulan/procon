#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	while(1){
		int n, p[10000], d[10000], a, b, max=0, index=-1;
		
		cin >> n;
		if(n==0) break;
		
		for(int i=0; i<n; ++i){
			scanf(" %d %d %d", &p[i], &a, &b);
			d[i] = a+b;
			if(max<d[i]){
				max=d[i];
				index=i;
			}	
		}
		
		printf("%d %d\n",p[index], max);
	}
	return 0;
}