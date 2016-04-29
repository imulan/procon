#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

long n;
int m, p[11];
string s;

int odd, even;
long dp[10][12];

long rec(int a, int b){ //a個目の*について考え,現在の合計のmod10はb
	if(dp[a][b]>=0) return dp[a][b];
	
	long ret=0;
	
	if(a==odd+even){
		if(b==0) ret=1;
		else ret=0;	
	}
	else{
		if(a<odd){
			for(int i=0; i<m; ++i) ret+=rec(a+1, (b+p[i])%10);	
		}
		else{
			for(int i=0; i<m; ++i){
				int v=2*p[i];
				if(v>9) v=1+(v%10);
				ret+=rec(a+1, (b+v)%10);	
			}
		}
		
	}
	
	return dp[a][b]=ret;
}

int main(){
	while(cin >> n){
		cin >> s >> m;
		for(int i=0; i<m; ++i) cin >> p[i];
		
		int sum=0;
		odd=0;
		even=0;
		int now=n-1;
		int ct=0;
		
		while(now>=0){
			if(s[now]=='*'){
				//printf("%d\n", now);
				if(ct%2==0) odd++;	
				else even++;
			}
			else if('0'<=s[now] && s[now]<='9'){
				if(ct%2==0) sum+=s[now]-'0';
				else{
					int v=2*(s[now]-'0');
					if(v>9){
						v=1+(v%10);	
					}
					sum+=v;
				}
				sum%=10;			
			}
			--now;
			++ct;	
		}
		
		//printf("odd=%d, even=%d\n", odd, even);
		
		memset(dp, -1, sizeof(dp));
		printf("%ld\n", rec(0,sum));
	}
}