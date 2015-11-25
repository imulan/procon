#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int day, a[4], ans=-1;

	scanf(" %d", &day);
	for(int i=0; i<4; ++i) scanf(" %d", &a[i]);
	
	for(int i=0; i<2; ++i){
		int p=a[i]/a[i+2];
		if(a[i]%a[i+2]==0){
			if(ans<p) ans=p;
		}
		else {
			if(ans<p) ans=p+1;
		}
		//printf("%d\n", ans);
	}
	printf("%d\n", day-ans);

	return 0;
}