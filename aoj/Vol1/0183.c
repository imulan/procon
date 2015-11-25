#include <stdio.h>

int judge(char x[3][3], char c){
	int res=0;
	int i, j;
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			if(x[i][j] == c) res=1;
			else{res=0; break;}
		}
		if(res==1) return res;
	} 
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			if(x[j][i] == c) res=1;
			else{res=0; break;}
		}
		if(res==1) return res;
	} 
	
	for(i=0; i<3; i++) {
		if(x[i][i] == c) res=1;
		else{res=0; break;}
	}
	if(res==1) return res;

	for(i=0; i<3; i++) {
		if(x[i][2-i] == c) res=1;
		else{res=0; break;}
	}
	if(res==1) return res;
	
	return res;
} 

int main(void){
	while(1){
		int i, j, flag=0;
		char f[3][3];
	
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				scanf(" %c", &f[i][j]);
				if(f[i][j]=='0') {
					flag=1;
					break;
				}
			}
			if(flag==1)break;	
		}
		if(flag==1) break;
	
		if(judge(f, 'b')==1)  printf("b\n");
		else if(judge(f, 'w')==1)	 printf("w\n");
		else printf("NA\n");
	}

	return 0;
}