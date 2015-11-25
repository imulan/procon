#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	int n, now=0;
	string s[400];
	double t[400][400];
	
	scanf(" %d", &n);
	for(int i=0; i<400; ++i)
	for(int j=0; j<400; ++j)
	t[i][j]=-1;
	
	for(int i=0; i<n; ++i){
		string p, q;
		double r;
		
		cin >> p >> r >> q;
		
		int x, y;
		bool flag=true;
		for(x=0; x<now; ++x){
			if(s[x]==p){
				flag=false;
				break;
			}
		}
		
		if(flag){
			s[now++]=p;
		}
		
		flag=true;
		for(y=0; y<now; ++y){
			if(s[y]==q){
				flag=false;
				break;
			}
		}
		
		if(flag){
			s[now++]=q;
		}
		
		t[x][y]=r;
	}
	
	/*
	for(int i=0; i<now; ++i){
		for(int j=0; j<now; ++j){
			printf(" %lf", t[i][j]);
		}
		printf("\n");
	}
	*/
	double m=0;
	int ma=0, mb=0;
	
	for(int i=0; i<now; ++i){
		double calc[400]; //単位換算

		for(int j=0; j<400; ++j) calc[j]=-1;
		
		calc[i]=1;
		
		//bfs
		queue<int> que;
		que.push(i);
		while( !que.empty() ){
			int v=que.front();
			que.pop();
			for(int j=0; j<now; ++j){
				if(t[v][j]>0 && calc[j]<calc[v]*t[v][j]){
					calc[j]=calc[v]*t[v][j];	
					que.push(j);
				}
				else if(t[j][v]>0 && calc[j]<calc[v]/t[j][v]){
					calc[j]=(double)calc[v]/t[j][v];	
					que.push(j);
					//printf(" %lf\n", calc[j]);
				}
			}
		}
		
		/*
		for(int j=0; j<now; ++j) printf("%lf ", calc[j]);		
		printf("\n");
		*/

		for(int j=0; j<now; ++j){
			if(calc[j]>m){
				m=calc[j];
				ma=i;
				mb=j;	
			}
		}
		
	} 
	
	
	cout << "1" << s[ma] << "=" << m << s[mb] << endl;
	
}