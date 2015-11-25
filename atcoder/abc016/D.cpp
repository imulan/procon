#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int ax, ay, bx, by;
	int n, x[100], y[100];
	int cross=0;
	
	//入力
	cin >> ax >> ay >> bx >> by;
	cin >>n;
	for(int i=0; i<n; ++i) scanf(" %d %d", &x[i], &y[i]);
	
	//線分同士の交差判定
	for(int i=0; i<n; ++i){
		int p=(i+1)%n;
		
		long ta = (ax-bx) * (y[i]-ay) + (ay-by) * (ax-x[i]);
		long tb = (ax-bx) * (y[p]-ay) + (ay-by) * (ax-x[p]); 
		long tc = (x[i]-x[p]) * (ay-y[i]) + (y[i]-y[p]) * (x[i]-ax);
		long td = (x[i]-x[p]) * (by-y[i]) + (y[i]-y[p]) * (x[i]-bx);
		
		if(tc*td<0 && ta*tb<0) ++cross;
	}
	
	printf("%d\n", cross/2+1);
	return 0;
}