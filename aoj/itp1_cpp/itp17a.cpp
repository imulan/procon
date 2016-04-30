#include <cstdio>

int main(){
	while(1){
		int m, f, r;
		scanf(" %d %d %d", &m, &f, &r);
		if(m==-1 && f==-1 && r==-1) break;
	
		if(m==-1 || f==-1 || m+f<30) printf("F\n");
		else if(m+f>=80) printf("A\n");
		else if(m+f>=65) printf("B\n");
		else if(m+f>=50 || (m+f>=30 && r>=50) ) printf("C\n");
		else printf("D\n");
	}

	return 0;
}