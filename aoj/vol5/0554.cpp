#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int ans=0, a;
	for(int i=0; i<4; ++i){
		scanf(" %d", &a);
		ans += a;
	}
	
	int x=ans/60;
	ans-=x*60;
	
	printf("%d\n%d\n", x, ans);

	return 0;
}