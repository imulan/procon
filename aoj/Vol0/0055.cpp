#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double a;
	while( scanf(" %lf", &a) != EOF ){
		double sum=a;
		for(int i=0; i<9; ++i){
			if(i%2==0){
				a*=2.0;
				sum+=a;
			}
			else{
				a/=3.0;
				sum+=a;
			}
			
			//printf("now:%.8lf\n", a);
		}
		
		printf("%.8lf\n", sum);
	}

	return 0;
}