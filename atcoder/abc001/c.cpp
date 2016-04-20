#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int main(){
	double a;
	double b;
	scanf(" %lf %lf", &a, &b);
	a/=112.5;
	b/=60.0;
	//printf("b befroe = %lf\n", b);
	b*=10.0;
	b=round(b);
	b/=10.0;
	
	//printf("c::::: a=%lf, b=%lf\n", a, b);
	
	string ans;
	int p;
	
	if(a<1 || 31<=a) ans="N";
	else if(a<3) ans="NNE"; 
	else if(a<5) ans="NE";
	else if(a<7) ans="ENE";
	else if(a<9) ans="E";
	else if(a<11) ans="ESE";
	else if(a<13) ans="SE";
	else if(a<15) ans="SSE";
	else if(a<17) ans="S";
	else if(a<19) ans="SSW";
	else if(a<21) ans="SW";
	else if(a<23) ans="WSW";
	else if(a<25) ans="W";
	else if(a<27) ans="WNW";
	else if(a<29) ans="NW";
	else if(a<31) ans="NNW";
	else ans="N";
	
	if(b<=0.2){
		ans="C";
		p=0;
	}
	else if(b<=1.5) p=1;
	else if(b<=3.3) p=2;
	else if(b<=5.4) p=3;
	else if(b<=7.9) p=4;
	else if(b<=10.7) p=5;
	else if(b<=13.8) p=6;
	else if(b<=17.1) p=7;
	else if(b<=20.7) p=8;
	else if(b<=24.4) p=9;
	else if(b<=28.4) p=10;
	else if(b<=32.6) p=11;
	else p=12;
	
	cout << ans << " " << p << endl;
	
	return 0;
}