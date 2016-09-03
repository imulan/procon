#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	long d, xp, yp;
	double ans=0;
	
	//入力
	scanf(" %d %ld", &n, &d);
	scanf(" %ld %ld", &xp, &yp);
	
	//上下左右対称だから，第１象限に移して考える
	if(xp<0) xp = -xp;
	if(yp<0) yp = -yp;
	
	//(xp,yp)にたどり着く可能性が有れば
	if(xp%d==0 && yp%d==0){
		int x=xp/d, y=yp/d;
		printf("x=%d,y=%d\n", x, y);
		
		for(int u=0; u<=n; ++u){ //上に行く回数
			int d=u-y; //下に行く回数
			if(d<0) continue;
			
			//合計移動がn回なので自然と右に行ける回数も決まる
			int r;
			int t=n-u-d+x;
			if( t%2==0 ) r=t/2;
			else continue; //あてはまるrはない
		
			if(r<0) continue;
			
			int l=r-x; //左に行く回数
			if(l<0) continue;
			
			printf("up: %d, down: %d, right: %d, left: %d\n", u, d, r, l);
			//回数が決まった
		
			//確率計算できねえよ!!!!!!!でかすぎるわｗｗｗ
			//
			//
			//
		
		
		}
		
	}
	
	printf("%lf\n", ans);
	return 0;
}