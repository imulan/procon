#include <stdio.h>

typedef struct{
	long num;
	long time;
	long score;
}team;

int main(void){
	long N, R, L, i, d, t, x;
	team t[100000];
	
	scanf(" %ld %ld %ld", &N, &R, &L);
	
	for(i=0; i<N; i++){
		t[i].num = i+1;
		t[i].time = 0;
		t[i].score = 0;
	}
	
	long now = 0;
	
	for(i=0; i<R; i++){
		scanf(" %ld %ld %ld", &d, &t, &x);
		t[d-1].
	
	}



	return 0;
}