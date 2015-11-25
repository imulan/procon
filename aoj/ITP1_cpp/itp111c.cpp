#include <cstdio>
#include <iostream>

using namespace std;

struct dice{
	int q1,q2,q3,q4,q5,q6;
};

void mN(dice &d){
	int tmp=d.q1;
	d.q1=d.q2;
	d.q2=d.q6;
	d.q6=d.q5;
	d.q5=tmp;
}

void mE(dice &d){
	int tmp=d.q1;
	d.q1=d.q4;
	d.q4=d.q6;
	d.q6=d.q3;
	d.q3=tmp;
}
void mW(dice &d){
	int tmp=d.q1;
	d.q1=d.q3;
	d.q3=d.q6;
	d.q6=d.q4;
	d.q4=tmp;
}
void mS(dice &d){
	int tmp=d.q1;
	d.q1=d.q5;
	d.q5=d.q6;
	d.q6=d.q2;
	d.q2=tmp;
}

void spin(dice &d){
	int tmp=d.q2;
	d.q2=d.q3;
	d.q3=d.q5;
	d.q5=d.q4;
	d.q4=tmp;
}

int main(){
	dice y, z;
	bool flag = false;
	
	scanf(" %d %d %d %d %d %d", &y.q1, &y.q2, &y.q3, &y.q4, &y.q5, &y.q6);
	scanf(" %d %d %d %d %d %d", &z.q1, &z.q2, &z.q3, &z.q4, &z.q5, &z.q6);
	
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			//printf("now: %d %d %d %d %d %d\n", y.q1, y.q2, y.q3, y.q4, y.q5, y.q6);
		
			if(y.q1==z.q1 && y.q2==z.q2 && y.q3==z.q3 && y.q4==z.q4 && y.q5==z.q5 && y.q6==z.q6) {
				flag = true;
				break;
			}
			spin(y);	
		}
		if(flag) break;
		mN(y);
	}
	
	mE(y);
	
	//printf("now: %d %d %d %d %d %d\n", y.q1, y.q2, y.q3, y.q4, y.q5, y.q6);
	
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			//printf("now: %d %d %d %d %d %d\n", y.q1, y.q2, y.q3, y.q4, y.q5, y.q6);
		
			if(y.q1==z.q1 && y.q2==z.q2 && y.q3==z.q3 && y.q4==z.q4 && y.q5==z.q5 && y.q6==z.q6) {
				flag = true;
				break;
			}
			spin(y);	
		}
		if(flag) break;
		mN(y);
	}	
			
	if(flag)printf("Yes\n");
	else printf("No\n");
		
	return 0;
}