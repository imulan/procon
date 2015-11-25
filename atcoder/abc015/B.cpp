#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, count=0, ans=0;	
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int a;
		scanf(" %d", &a);
		if(a) ++count;
		ans+=a;
	}
	
	if(ans%count==0) ans /=count;
	else ans=ans/count+1;	
	
	printf("%d\n", ans);
	return 0;
}