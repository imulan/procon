#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef struct{
	long nume; //分子
	long deno; //分母
}fraction;

int main(){
	while(1){
		string s;
		cin >> s;
		if(s=="#") break;
		
		int t=s.size()-1;
		int n=0;
		fraction d; //degree
		d.nume=0;
		d.demo=1;
		while(t>=0){
			fraction p;
			p.demo=pow(2, n);
			++n;
			
			if(d.demo<p.demo){
				d.nume*=
				d.demo*=	
			}
			else if(d.demo>p.demo){
				
			}
			
			if(s[t]=='h'){ //north
				t-=5;
				
			}
			else if(s[t]=='t'){ //west
				t-=4;
				
			}
			
			
		}	
		
		
		
		
	
	}
	return 0;
}