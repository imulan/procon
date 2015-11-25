#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long q1, b, c1, c2, q2;
		
		scanf(" %ld", &q1);
		if(q1==0) break;		
		scanf(" %ld %ld %ld %ld", &b, &c1, &c2, &q2);
		
		long x, y;
		
		//まず買えるだけ買ってみる
		long t=b/c1;
		if(t>q2) x=q2;
		else x=t;
		
		//その時の普通の鶏肉の量
		y=(b-x*c1)/c2;
		
		printf("x=%ld, y=%ld\n", x, y);
		
	}
}	