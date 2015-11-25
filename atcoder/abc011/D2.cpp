#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double c[1100][1100]={0};
	
int main(){
	int n;
	long d, xp, yp;
	double ans=0;
	
	//combination
	c[0][0]=1.0;
	for(int i=1; i<=1000; ++i){
		c[i][0]=c[i-1][0]/2.0;
		for(int j=1; j<=i; ++j) c[i][j] = (c[i-1][j-1] + c[i-1][j])/2.0;
	}
	
	//入力
	scanf(" %d %ld", &n, &d);
	scanf(" %ld %ld", &xp, &yp);
	
	//上下左右対称だから，第１象限に移して考える
	if(xp<0) xp = -xp;
	if(yp<0) yp = -yp;
	
	//(xp,yp)にたどり着く可能性が有れば
	if(xp%d==0 && yp%d==0){
		int x=xp/d, y=yp/d;
		//printf("x=%d,y=%d\n", x, y);
		
		for(int i=x; i<=n; ++i){ //左右に動く回数
			int tmp=i+x;
			int r; //右
			if(tmp%2==0) r=tmp/2;
			else continue;
			
			tmp=(n-i)+y;
			int u; //上
			if(tmp%2==0) u=tmp/2;
			else continue;
			//printf("c[%d][%d] * c[%d][%d] * c[%d][%d]\n",n, i, i, r, n-i, u);
			ans += (double)c[n][i] * c[i][r] * c[n-i][u];
		}
		
	}
	
	printf("%.15lf\n", ans);
	return 0;
}