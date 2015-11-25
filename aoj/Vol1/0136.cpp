#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	int a[6]={0};
	
	cin >> n;

	for(int i=0; i<n; ++i){
		double k;
		cin >> k;
		
		if(k<165) ++a[0];
		else if(k<170) ++a[1];
		else if(k<175) ++a[2];
		else if(k<180) ++a[3];
		else if(k<185) ++a[4];
		else ++a[5];
	}
	
	for(int i=0; i<6; ++i){
		printf("%d:", i+1);
		
		for(int j=0; j<a[i]; ++j)
			printf("*");
		printf("\n");
	}	

	return 0;
}