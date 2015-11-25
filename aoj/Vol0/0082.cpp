//未完成

#include <cstdio>

int main(void){
	while(1){
	
		int i, j, p[8], r[8]={0}, flag=0;
		int limit[8]={1,2,1,2,1,4,1,4};
		
		for(i=0; i<8; i++){
			if(scanf(" %d", &p[i]) == EOF) {
				flag=1;
				break;
			}
		}
		if(flag==1) break;
	
		for(i=0; i<8; i++){
			for(j=0; j<8; j++){
				if(p[j] - limit[(i+j) % 8] > 0) {
					r[i] += p[j] - limit[(i+j) % 8];
				}
			}
		}
		
		int min=r[0];
		int mins[8];
		
		mins[0] = 0;
		int count = 1;
		
		for(i=1; i<8; i++) {
			if(min > r[i]) {
				min = r[i];
				count = 1;
				mins[0] = i;
			}
			else if(min == r[i]) {
				mins[count] = i;
				count++;
			}
		}
		
		printf("count = %d\n", count);
		
		int index = 0;

		for(i=0; i<8; i++){
			min=limit[(mins[0]+i) % 8];
			index=mins[0];
			int ab=0;
			
				
			for(j=0; j<count; j++){
				int ff=0;
				int pp=0;
				if(index == mins[j]) {
					printf("cont\n");	
					pp=1;
				}
				
				if(pp==1) break;;
				
				if(min > limit[(mins[j]+i) % 8])
					index = mins[j];
				else if(min == limit[(mins[j]+i) % 8]){
					ff=1;
					printf("same\n");
				}
				if(ff==0) {
					ab=1;
					printf("ab\n");
					break;
				}
					
				printf("min = %d, index = %d\n", min, index);
	
			}
			
			if(ab==1) break;
			
		}
		
		printf("finalindex = %d\n", index);
		
				
		for(i=0; i<8; i++){
			printf("%d ", limit[(index+i) % 8]);
		}
		
		printf("\n");
	}

	return 0;
}