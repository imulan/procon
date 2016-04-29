#include <cstdio>
#include <iostream>
using namespace std;

int student[10001][822]; //imos法のための配列

int main(){
	while(1){
		int N, M; //pc数，学生数
		
		scanf(" %d %d", &N, &M);
		if(N==0) break;
		
		for(int i=1; i<=M; ++i)
		for(int j=0; j<=821; ++j)
		student[i][j]=0;
		
		int r;
		scanf(" %d", &r);
		for(int i=0; i<r; ++i){
			int t, n, m, s;
			scanf(" %d %d %d %d", &t, &n, &m, &s);
			if(s==0) student[m][t-540+1]--;
			else student[m][t-540+1]++;	
		}

		for(int i=1; i<=M; ++i)
		for(int j=0; j<821; ++j)
		student[i][j+1] += student[i][j];
		
		//for(int j=0; j<820; ++j) printf("student[%d] = %d\n", j, student[1][j]);
		
		
		int q;
		scanf(" %d", &q);
		for(int i=0; i<q; ++i){
			int ts, te, m;
			scanf(" %d %d %d", &ts, &te, &m);
			
			int count=0;
			for(int j=ts+1; j<=te; ++j) if(student[m][j-540]>0) ++count;
			printf("%d\n", count);
		} 
	
	}
	return 0;
}