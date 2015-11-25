#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	if(n>=12) n-=12;
	int time = n*60+m; //分換算
	
	//真上を基準としてなす角度
	//短針
	double S=(double)time/2.0;
	//長針
	double L=(double)m*6;
	
	//printf("S:%lf, L:%lf\n", S, L);
	
	double ans=fabs(S-L);
	if(ans>180) ans = 360-ans;
	printf("%lf\n", ans);
}