#include <cstdio>

int main(){
	int n;
	int room[4][3][10]={0};
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int b, f, r, v;
		scanf(" %d %d %d %d", &b, &f, &r, &v);
		room[b-1][f-1][r-1] += v;
	}
	
	for(int i=0; i<4; ++i){
		for(int j=0; j<3; ++j){
			for(int k=0; k<10; ++k){
				printf(" %d", room[i][j][k]);
			}
			printf("\n");
		}
		if(i!=3){
			for(int j=0; j<20; ++j)
				printf("#");
			printf("\n");
		}
	}

	return 0;
}