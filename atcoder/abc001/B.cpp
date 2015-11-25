#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long m;
	scanf(" %ld", &m);

	if(m<100){
		m=0;
	}
	else if(m<=5000){
		m/=100;
	}
	else if(m<=30000){
		m=m/1000+50;
	}
	else if(m<=70000){
		m=(m/1000-30)/5+80;
	}
	else{
		m=89;
	}
	
	if(m<10) printf("0");
	printf("%ld\n", m);
	
	return 0;
}