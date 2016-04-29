#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int n=1001;

int main(){
	int v, d;
	int f[1001];
	
	while(cin >> v >> d){
		memset(f, 0, sizeof(f));
		int a, b, c;
		c=b=1;
		
		for(int i=0; i<v; ++i){
			a=(b+c)%n;
			f[a]++;
			c=b;
			b=a;
		}
		
		int pre=0, ans=1;

		while(f[pre]==0) pre++;
		
		for(int i=pre+1; i<=1000; ++i){					
			if(f[i]>0){
				//printf("%d\n", i);	
				
				if(i-pre>=d) ++ans;

				pre=i;
			}
		}	
		
		printf("%d\n", ans);		
	}
}	