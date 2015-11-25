#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string ss;
	while(getline(cin, ss)){
		string s[13];
		istringstream sin(ss);
		int now=-1;
		while(sin>>s[++now]);
	
		int size=stoi(s[0]);
		printf("now=%d\n", now);
		int cake[12];
		for(int i=1; i<now; ++i){
			cake[i-1]=stoi(s[i]);
			printf("%d\n", cake[i-1]);
		}
		
		//ここまでで入力終了，処理に入る
		
		//これだとただ入力順だからダメ
		--now;
		double ans=cake[0]+cake[now-1];
		for(int i=0; i<now-1; ++i){
			printf("%d, %d\n", i, i+1);
			double a=cake[i]+cake[i+1];
			double b=fabs(cake[i]-cake[i+1]);
			ans+=sqrt(a*a-b*b);	
			printf("%lf\n",ans);
		}
		
		if(ans<=size) printf("OK\n");
		else printf("NA\n");
		//書き足す必要ある
	}
	return 0;
}