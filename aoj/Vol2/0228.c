#include <stdio.h>
#include <string.h>

int main(void){
	char nums[10][8];
	
	strcpy(nums[0], "0111111");
	strcpy(nums[1], "0000110");
	strcpy(nums[2], "1011011");
	strcpy(nums[3], "1001111");
	strcpy(nums[4], "1100110");
	strcpy(nums[5], "1101101");
	strcpy(nums[6], "1111101");
	strcpy(nums[7], "0100111");
	strcpy(nums[8], "1111111");
	strcpy(nums[9], "1101111");

	while(1){
		int n, i, j, a;
		char ans[8];
		char now[8] = "0000000";
		
		scanf(" %d", &n);
		if(n==-1) break;
	
		for(i=0; i<n; i++){
			scanf(" %d", &a);	
			
			for(j=0; j<7; j++){
				if(now[j] == nums[a][j]) printf("0");
				else printf("1");
			}
			
			strcpy(now, nums[a]);
			
			printf("\n");
		}	
	}

	return 0;
}