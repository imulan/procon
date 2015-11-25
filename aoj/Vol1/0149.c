#include <stdio.h>

int main(void){
	int i, eye[4][2]={0};
	
	while(1){
		int j, flag=0;
		double a[2];
		
		for(i=0; i<40; i++){
			if(scanf(" %lf %lf", &a[0], &a[1]) == EOF)	 {
				flag=1;
				break;
			}
			
			for(j=0; j<2; j++){
				if(a[j] >= 1.1) eye[0][j]++;
				else if(a[j] >= 0.6) eye[1][j]++;
				else if(a[j] >= 0.2) eye[2][j]++;
				else eye[3][j]++;
			}
		}
		if(flag==1) break;
	}
	
	for(i=0; i<4; i++)
		printf("%d %d\n", eye[i][0], eye[i][1]);

	return 0;
}