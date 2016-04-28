#include <stdio.h>
#include <string.h>

typedef struct{
	char name[100];
	int win;
	int lose;
	int prior;
}team;

void swap(team *p, team *q){
	team tmp = *p;
	*p = *q;
	*q = tmp;
}

int main(void){
	while(1){
		int n, i, j, a;
		char c[100];
		team t[10];
		
		scanf(" %d", &n);
		if(n==0) break;
	
		for(i=0; i<n; i++){
			scanf(" %s", c);
			strcpy(t[i].name, c);
			t[i].win=0;
			t[i].lose=0;
			t[i].prior=i;
			
			for(j=0; j<n-1; j++){
				scanf(" %d", &a);
				if(a==0) ++t[i].win; 
				else if(a==1) ++t[i].lose;
			}
		}
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if( (t[i].win > t[j].win) || (t[i].win==t[j].win && t[i].lose < t[j].lose) ||  (t[i].win==t[j].win && t[i].lose==t[j].lose && t[i].prior < t[j].prior) )
					swap(&t[i], &t[j]);
			}
		}
	
		for(i=0; i<n; i++)
			printf("%s\n", t[i].name);

	}

	return 0;
}