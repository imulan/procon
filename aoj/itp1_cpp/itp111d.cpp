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

void spin(dice &d){
	int tmp=d.q2;
	d.q2=d.q3;
	d.q3=d.q5;
	d.q5=d.q4;
	d.q4=tmp;
}

bool isSame(dice y, dice z){
	bool flag = false;

	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
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
	
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){		
			if(y.q1==z.q1 && y.q2==z.q2 && y.q3==z.q3 && y.q4==z.q4 && y.q5==z.q5 && y.q6==z.q6) {
				flag = true;
				break;
			}
			spin(y);	
		}
		if(flag) break;
		mN(y);
	}	
			
	return flag;
}

int main(){
	dice a[100];
	int n;
	bool ans=false;
	
	scanf(" %d", &n);
	
	for(int i=0; i<n; ++i)
		scanf(" %d %d %d %d %d %d", &a[i].q1, &a[i].q2, &a[i].q3, &a[i].q4, &a[i].q5, &a[i].q6);
		
	for(int i=0; i<n-1; ++i){
		for(int j=i+1; j<n; ++j){
			ans=isSame(a[i], a[j]);
			if(ans) break;
		}
		if(ans) break;
	}
	
	if(ans) printf("No\n");
	else printf("Yes\n");
		
	return 0;
}