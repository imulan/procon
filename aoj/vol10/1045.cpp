#include <cstdio>
#include <iostream>
using namespace std;

int n;
long m, sum, a[20];

//sum/2以下で最も高い戦闘力の合計
void rec(int x, long y){ //x人目を入れるか入れないか,今の戦闘力y
	if(x==n){
		if(m<y) m=y;	
	}
	else{
		if(y+a[x]>sum/2) rec(x+1,y);
		else{
			rec(x+1,y+a[x]);
			rec(x+1,y);		
		}	
	}
	
}

int main(){
	while(1){
		scanf(" %d", &n);
		if(n==0) break;
		
		sum=0;
		for(int i=0; i<n; ++i){
			scanf(" %ld", &a[i]);
			sum+=a[i];
		}
	
		m=0;	
		rec(0, 0);
		
		long mm=sum-m;
		//printf("m=%ld, mm=%ld\n",m ,mm);
		printf("%ld\n", mm-m);
	}
}