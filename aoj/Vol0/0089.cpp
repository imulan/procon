#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <iostream>
using namespace std;

int n=0;
int h[101][100]={0};
long dp[100][100]; //現在位置

long rec(int a, int b){
	if(dp[a][b]>=0) return dp[a][b];
	
	long ret=0;
	if(a==n){ //ゴール
		 ret=0;
	}
	else if(h[a+1][b] == -1){ //下に進めないので右下に行くしかない
		ret=rec(a+1, b+1)+h[a][b];
	}
	else if(h[a+1][b+1]==-1){ //右下に進めないので下に行くしかない
		ret=rec(a+1, b)+h[a][b];
	}
	else{ //どっちにも行ける
		ret+=max(rec(a+1, b) , rec(a+1, b+1)) + h[a][b];
	}
	
	return ret;
}	

int main(){
	memset(h, -1, sizeof(h));
	
	string s;
	int maxm=-1, limn=-1;
	bool flag=true;
	
	while(getline(cin, s)){
		int t=0, m=0;
		stack<int> st;
		
		while(1){
			//printf("n=%d, if??%d\n", n, limn==n);
					
			if(t+1==s.size()){
				int tmp=0;
				if( !st.empty() ){
					tmp=st.top();
					st.pop();	
				}
				int a=s[t]-'0';
				h[n][m]=tmp*10+a;
				
				if(m>maxm) maxm=m;
				else if(m==maxm && flag){
					limn=maxm*2+2;
					//printf("limn= %d\n", limn);
					flag=false;
				}
				else if(flag){ //maxmが決定した
					limn=maxm*2+1;
					//printf("limn= %d\n", limn);
					flag=false;
				}
							
				break;
			}
			else{
				if(s[t]==','){
					h[n][m]=st.top();
					st.pop();
					++t;
					++m;
				}	
				else{
					int tmp=0;
					if( !st.empty() ){
						tmp=st.top();
						st.pop();	
					}
					int a=s[t]-'0';
					st.push(tmp*10+a);
					
					++t;
				}
				
				//printf("t=%d\n", t);
			}
		}
		++n;
		//if(limn==n) break;	
		
		//printf("ok\n");
	}	
	
	
	for(int i=n/2+1; i<n; ++i){ //この行のhをずらす
		int p=i-maxm-(n%2==0);
		//printf(" i=%d, p=%d\n", i, p);
		
		for(int j=maxm; j>=p; --j){
			h[i][j] = h[i][j-p];	
		}
		
		for(int j=p-1; j>=0; --j) h[i][j]=-1;
	}
	
	/*
	for(int i=0; i<n; ++i){
		for(int j=0; j<5; ++j){
			printf("%3d", h[i][j]);		
		}
		printf("\n");
	}
	
	printf("n=%d,maxm=%d\n", n, maxm);
	*/
	
	//ここまでで次の進路が下か右下になるデータ構造が完成した
	//（ただし，-1のところに進むことはできない）
	//あとはメモ化再起を利用して解くだけ
	memset(dp, -1, sizeof(dp));
	printf("%ld\n", rec(0,0));
}