#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

//long dp[6][1100];
/*
long rec(int a, int b){ //a本目，最後に当てた位置b
	if(dp[a][b]>=0) return dp[a][b];
	
	long ret=0;
	long tmp=0;
	
	if(a==4) ret=0;
	else{
		for(int i=b; i<=n; ++i){
			tmp=rec(a+1, i)+p[i];
			if(tmp>m) tmp=0;	
			
			ret=max(ret, tmp);
			
		}		
	}
	
	return dp[a][b]=ret;
}
*/

int n;
long m, p[1001], q[1100000];

int main(){
	while(1){
		
		scanf(" %d %ld", &n, &m);
		if(n==0) break;
		p[0]=0; //投げない選択肢
		for(int i=1; i<=n; ++i) scanf(" %ld", &p[i]);
		sort(p, p+n);
		
		//半分全列挙(?)
		long now=0;
		for(int i=0; i<=n; ++i)
		for(int j=i; j<=n; ++j)
		q[now++]=p[i]+p[j];
		sort(q, q+now);
		
		//for(long i=0; i<now; ++i) printf("q[%ld]=%ld\n", i, q[i]);
		
		/*
		memset(dp, -1, sizeof(dp));
		printf("%ld\n", rec(0,0));
		*/
		
		long ans=0;
		for(long i=0; i<now; ++i){
			long rem=m-q[i];
			if(rem<0) break;
			
			//2分探索
			long left=0, right=now;
			while(left<right){
				long center=(left+right)/2;
				if(rem>q[center]){
					left=center+1;
				}
				else if(rem<q[center]){
					right=center;
				}
				else	break;
			}
			
			ans=max(ans, q[i]+q[right-1]);
		}
		
		printf("%ld\n", ans);
	}
}