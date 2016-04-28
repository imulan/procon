#include <iostream>
#include <cstdio>
using namespace std;

bool hangaku(int x, int y){
	int max=19*60+30, min=17*60+30;
	int n=x*60+y;

	if(min<=n && n<=max) return true;
	else return false;
}

int main(){
	//料金
	int p[8][8]={0};
	p[1][2]=300; p[1][3]=500; p[1][4]=600; p[1][5]=700; p[1][6]=1350; p[1][7]=1650;
	p[2][3]=350; p[2][4]=450; p[2][5]=600; p[2][6]=1150; p[2][7]=1500;
	p[3][4]=250; p[3][5]=400; p[3][6]=1000; p[3][7]=1350;
	p[4][5]=250; p[4][6]=850; p[4][7]=1300;
	p[5][6]=600; p[5][7]=1150;
	p[6][7]=500;     
	
	for(int i=1; i<8; ++i){
		for(int j=i+1; j<8; ++j){
			p[j][i]=p[i][j];
		}
	}
	
	//半額になるかどうか
	bool half[8][8];
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			half[i][j]=true;
			
	half[1][6]=false; half[1][7]=false; half[2][7]=false; half[3][7]=false;
	half[6][1]=false; half[7][1]=false; half[7][2]=false; half[7][3]=false;
			
	//処理
	while(1){
		int inic, outic, h1, m1, h2, m2;
		
		scanf(" %d", &inic);
		if(inic==0) break;
		
		scanf(" %d %d", &h1, &m1);
		scanf(" %d", &outic);
		scanf(" %d %d", &h2, &m2);
	
		int price=p[inic][outic];
		if(half[inic][outic]){
			if(hangaku(h1, m1) || hangaku(h2,m2)){
				price/=2;
				if(price%50!=0){
					price+=50-(price%50);	
				}
			}		
		}
		printf("%d\n", price);
	}
	return 0;
}