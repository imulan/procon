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
		double m;

		cin >> p >> m >> q;

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

		t[x][y]=m;
		t[y][x]=1.0/m;
	}

	for(int T=0; T<5; ++T){
		for(int k=0; k<now; ++k){
			for(int i=0; i<now; ++i){
				for(int j=0; j<now; ++j){
					if(t[i][j]>0) continue;

					if(t[i][k]>0){
						if(t[k][j]>0) t[i][j]=t[i][k]*t[k][j];
						if(t[j][k]>0) t[i][j]=t[i][k]/t[j][k];
					}

				}

			}
		}
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
		for(int j=0; j<now; ++j){
			if(m<t[i][j]){
				m=t[i][j];
				ma=i;
				mb=j;
			}
		}
	}

	cout << "1" << s[ma] << "=" << (long)(m+0.001) << s[mb] << endl;

}
